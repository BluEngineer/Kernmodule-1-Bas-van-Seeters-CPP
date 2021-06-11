//
// Created by basva on 04/06/2021.
//

#include "Bullet.h"

Bullet::Bullet(sf::Vector2f bulletSize, sf::Vector2f bulletPosition, sf::Vector2f bulletSpeed)
{
    this->size = bulletSize;
    this->position = bulletPosition;
    this->speed = bulletSpeed;
}


bool Bullet::IsColliding(Enemy currentEnemy) {
    if (currentEnemy.enemyHitbox.intersects(nextPos)) {
        //currentEnemy = enemies.erase(currentEnemy);
        return true;
    }
    return false;
}

void Bullet::Update()
{
    position.y += speed.y;
    position.x += speed.x;
    bulletHitbox = bulletShape.getGlobalBounds();
    nextPos = bulletHitbox;
    //nextPos.left += speed;
}

void Bullet::Draw(sf::RenderWindow &window)
{
    bulletShape.setPosition(position.x, position.y);
    bulletShape.setFillColor(hsv((int)bulletColorCycle, 255, 255));
    bulletColorCycle += bulletColorCycleSpeed;
    bulletShape.setSize(sf::Vector2f(size.x, size.y));
    window.draw(bulletShape);
}

Bullet::~Bullet() = default;
