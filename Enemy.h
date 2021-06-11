//
// Created by basva on 27/05/2021.
//

#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H


#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"


class Enemy {

public:
    Enemy(sf::Vector2f(enemySize), sf::Vector2f(enemyPosition), sf::Vector2f(enemySpeed));

    ~Enemy();

    sf::RectangleShape enemyShape;
    sf::Vector2f position;
    sf::Vector2f speed;
    sf::Vector2f size;

    sf::FloatRect enemyHitbox;
    sf::FloatRect nextPos;

    bool isDead;

    sf::Vector2f acceleration;
    sf::Vector2f velocity;
    sf::Vector2f preClampVelocity;

    float friction = 4.f;
    float mass = 0.5;
    float maxVelocity = 50;


    float enemyHsvCycle = rand() % 255;
    float enemyHsvSpeed = 0.5f;
    float enemyHsvMultiplier = 1.2f;

    void Update();
    void Draw( sf::RenderWindow &window);

    void CollideWithWall(sf::RenderWindow &window);

    bool IsColliding(Player player);

private:
    sf::Vector2f move;

};
#endif //UNTITLED_ENEMY_H
