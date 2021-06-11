//
// Created by basva on 04/06/2021.
//

#ifndef UNTITLED_BULLET_H
#define UNTITLED_BULLET_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "hsv.h"


class Bullet {
public:
    Bullet(sf::Vector2f(bulletSize), sf::Vector2f(bulletPosition), sf::Vector2f(bulletSpeed));

    ~Bullet();

    sf::RectangleShape bulletShape;
    sf::Vector2f position;
    sf::Vector2f speed;
    sf::Vector2f size;


    sf::FloatRect bulletHitbox;
    sf::FloatRect nextPos;

    float bulletColorCycle = rand() % 255;
    float bulletColorCycleSpeed = 5.f;

    void Update();
    void Draw( sf::RenderWindow &window);
    bool IsColliding(Enemy currentEnemy);

};


#endif //UNTITLED_BULLET_H
