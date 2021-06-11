//
// Created by basva on 20/05/2021.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "hsv.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "GameTextManager.h"
#include <vector>

int main()
{
    float backgroundColorCycle = 0;
    float backgroundColorSpeed = 0.8f;

    float mainColorCycle = 55;
    float mainColorCycleSpeed = 1.f;

    int enemyStartCount = 2;
    int maxEnemyCount = 35;
    int enemyCount = 0;
    float enemySpawnTimer = 0;
    float enemySpawnIncrease = 1.f;
    float enemyspawnRate = 100;

    enum GameState {START, GAME, END};
    GameState gameState = START;
    bool gameOver;

    int healthPoints = 3;
    int scorePoints = 0;

    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Coole_game");
    window.setFramerateLimit(120);
    Player player(sf::Vector2f (70.f,70.f),sf::Vector2f (400,(float)window.getSize().y - (float)window.getSize().y / 9) );
    enemies.reserve(enemyStartCount);
    sf::Event event{};

    GameTextManager gameTextManager;
    gameTextManager.InitializeText(window);

    //UI TEXT

    while (window.isOpen())
    {
        auto it = enemies.begin();
        auto it2 = bullets.begin();

        switch (gameState)
        {
            case START:

                gameTextManager.drawTitleText(window);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    //initialise GAME mode
                    for (int i = 0; i < enemyStartCount ; ++i) {
                        enemies.emplace_back(sf::Vector2f(30,30), sf::Vector2f(rand() % window.getSize().x, 0.f), sf::Vector2f(rand() % 6, rand() % 4 + 0.1f ));
                        enemyCount++;
                    }
                    gameState = GameState::GAME;
                }

                break;

            case GAME:
                if (!it->isDead) {
                    while (it != enemies.end()) {
                        it->Draw(window);
                        it->Update();
                        it->CollideWithWall(window);

                        if (it->IsColliding(player)) {
                            healthPoints--;
                            enemyCount--;
                            it->isDead = true;
                            it = enemies.erase(it);
                            continue;
                        }

                        if (it->position.y >= (float) window.getSize().y) {
                            scorePoints++;
                            enemyspawnRate -= 2;
                            enemyCount--;
                            it->isDead = true;
                            it = enemies.erase(it);
                            continue;
                        }

                        while (it2 != bullets.end()) {
                            if(it2->position.y < 0)
                            {
                                it2 = bullets.erase(it2);
                                std::cout << "Bullet left screen" << "\n";

                                continue;
                            }

                            if (it2->IsColliding(*it)) {
                                scorePoints++;
                                enemyspawnRate -= 2;
                                enemyCount--;
                                it->isDead = true;
                                it = enemies.erase(it);
                                it2 = bullets.erase(it2);
                                std::cout << "collision detected" << "\n";

                            } else {
                                it2++;
                            }
                        }

                        it++;
                    }
                }

                //update player
                player.Update(window);
                player.playerHsvSpeed = (scorePoints / 10);

                //update text
                gameTextManager.drawGameText(window, healthPoints, scorePoints, enemyCount);

                //Player Shoot Bullets
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    bullets.emplace_back(sf::Vector2f(8, 15),sf::Vector2f(player.position.x + (player.size.x / 2), player.position.y + (player.size.y / 2)), sf::Vector2f(0,-7));
                }

                for (auto & bullet : bullets)
                {
                    bullet.Draw(window);
                    bullet.Update();
                }

                //Spawn enemies over time
                enemySpawnTimer += enemySpawnIncrease;
                if(enemyCount != maxEnemyCount && enemySpawnTimer >= enemyspawnRate)
                {
                    enemies.emplace_back(sf::Vector2f(30,30), sf::Vector2f(rand() % window.getSize().x, 0.f), sf::Vector2f(rand() % 3, rand() % 4 + 0.3f ));
                    enemyCount++;
                    enemySpawnTimer = 0;
                }

                if(scorePoints == 100) maxEnemyCount = 45;
                if(scorePoints == 150) maxEnemyCount = 55;
                if(scorePoints == 150) maxEnemyCount = 70;

                //end condition
                if(healthPoints <= 0)
                {
                    //initialize endscreen
                    gameState = GameState::END;
                }

                break;

            case END:
                gameTextManager.drawEndText(window, scorePoints);
                mainColorCycle += mainColorCycleSpeed;

                break;
        }
        window.display();

        window.clear(hsv((int)backgroundColorCycle, 0.25f, 0.25f));
        backgroundColorCycle+= backgroundColorSpeed;

        while (window.pollEvent(event))
        {
            if  (event.type == sf::Event::Closed ||
                 (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
        }
    }

    return 0;
}



