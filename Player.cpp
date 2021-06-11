//
// Created by basva on 27/05/2021.
//

#include "Player.h"
#include "hsv.h"
#include "SFML\System.hpp"
#include <iostream>
#include <cmath>


Player::Player(sf::Vector2f size, sf::Vector2f position)
{
    this->size = size;
    playerShape.setSize(this->size);
    this->position = position;
}

Player::~Player() = default;

void Player::Update(sf::RenderWindow &window)
{
    acceleration = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        acceleration += speed;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        acceleration += -speed;

    }

    float preClamVelocity;
    preClamVelocity = (1/friction) * (std::pow(2.7, -friction/mass)) * (friction * velocity.x + mass * acceleration) - (mass * acceleration / friction);
    velocity.x = std::clamp(preClamVelocity ,-maxVelocity , maxVelocity);
    move = velocity;
    position = position + move;

    playerHitbox = playerShape.getGlobalBounds();
    nextPos = playerHitbox;
    nextPos.left += speed;
    Draw(window);
    EdgeCheck(window);

}

void Player::Draw(sf::RenderWindow &window)
{
    playerHsvCycle += playerHsvSpeed;
    playerShape.setFillColor(hsv((int)playerHsvCycle, 255.f, 255.f));
    //position = sf::Vector2f (sf::Mouse::getPosition(window).x, /*window.getSize().y - (100 )*/ sf::Mouse::getPosition(window).y );
    playerShape.setPosition(position.x, position.y);
    window.draw(playerShape);
}

void Player::EdgeCheck(sf::RenderWindow &window) {

    //left screen collision
    if(position.x < 0 ) position.x = 0 , move.x = 0;
    //right screen collision
    if(position.x + size.x > (float)window.getSize().x ) position.x = (float)window.getSize().x - size.x;
}



/*
bool Player::IsColliding(Enemy currentEnemy) {
    if(currentEnemy.enemyHitbox.intersects(nextPos))
    {
        //enemy = enemies.erase(enemy);
        return true;

    }

    return false;
}
*/
