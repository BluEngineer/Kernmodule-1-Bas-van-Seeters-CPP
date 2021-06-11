//
// Created by basva on 27/05/2021.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


class Player {

public:
    Player(sf::Vector2f size, sf::Vector2f position);
    ~Player();

    void Draw( sf::RenderWindow &window);

    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f  size;

    float acceleration = 0.01;
    float friction = 0.05f;
    float mass = 1;
    float maxVelocity = 7;

    float playerHsvCycle = 0;
    float playerHsvSpeed = 0.1f;
    float deltaTime;

    float speed = 6.f;
    sf::Vector2f move;

    sf::FloatRect nextPos;
    sf::FloatRect  playerHitbox;

    void Update(sf::RenderWindow &window);
    void EdgeCheck(sf::RenderWindow &window);

    sf::RectangleShape playerShape;
    //bool IsColliding(Enemy currentEnemy);


};


#endif //UNTITLED_PLAYER_H
