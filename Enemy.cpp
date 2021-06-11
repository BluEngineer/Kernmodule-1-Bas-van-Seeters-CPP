//
// Created by basva on 27/05/2021.
//

#include "Enemy.h"
#include "Player.h"
#include <cmath>
#include "hsv.h"
#include <SFML/Graphics.hpp>

Enemy::Enemy(sf::Vector2f enemySize, sf::Vector2f enemyPosition, sf::Vector2f(enemySpeed)) {
    this->size = enemySize;
    this->speed = enemySpeed;
    this->position = enemyPosition;
}

void Enemy::Update()
{
    if(!isDead)
    {
        //De Physics code heb ik helaas niet meer optijd werkend gekregen

        //acceleration.x = 0;
        //acceleration.y = 0;

        position.x += speed.x;
        position.y += speed.y;

       // preClampVelocity.x = (1 / friction) * (std::pow(2.7f, -friction / mass )) * (friction * velocity.x + mass * acceleration.x) - (mass * acceleration.x / friction);
       // velocity.x = std::clamp(preClampVelocity.x, -maxVelocity, maxVelocity);

        //preClampVelocity.y = (1 / friction) * (std::pow(2.7f, -friction / mass )) * (friction * velocity.y + mass * acceleration.y) - (mass * acceleration.y / friction);
        //velocity.y = std::clamp(preClampVelocity.y, 0.f, maxVelocity);

       // move.x = -velocity.x;
        //move.y = -velocity.y;

       // position = position + move;

        enemyHitbox = enemyShape.getGlobalBounds();
        nextPos = enemyHitbox;
        enemyHsvSpeed = (((speed.x + speed.y) / 2) * enemyHsvMultiplier);


    }

}

void Enemy::Draw(sf::RenderWindow &window) {
    if(!isDead)
    {
        enemyShape.setPosition(position.x, position.y);
        enemyShape.setFillColor(hsv((int)enemyHsvCycle, 255, 255));
        enemyHsvCycle += enemyHsvSpeed;
        //enemyShape.setPosition(window.getSize().x / 2, window.getSize().y / 2);
        enemyShape.setSize(sf::Vector2f(size.x, size.y));
        window.draw(enemyShape);
    }

}

bool Enemy::IsColliding(Player player) {
    if(player.playerHitbox.intersects(nextPos))
    {
        //enemy = enemies.erase(enemy);
        return true;

    }

    return false;
}


void Enemy::CollideWithWall(sf::RenderWindow &window) {
    //left wall
    if(position.x < 0 )
    {
        velocity.x *= -1;
        speed.x *= -1;
    }

    //right wall
    if(position.x + size.x > (float)window.getSize().x )
    {
        velocity.y *= -1;
        speed.x *= -1;
    }
}

Enemy::~Enemy() = default;


