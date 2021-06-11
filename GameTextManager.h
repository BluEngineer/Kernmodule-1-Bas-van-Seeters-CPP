//
// Created by basva on 09/06/2021.
//

#ifndef UNTITLED_GAMETEXTMANAGER_H
#define UNTITLED_GAMETEXTMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "hsv.h"

class GameTextManager {
public:
    GameTextManager();
    ~GameTextManager();
    sf::Font valorantFont;
    sf::Font generalFont;
    sf::Text startScreenTitleText;
    sf::Text startScreenText;
    sf::Text gameOverText;
    sf::Text livesText;
    sf::Text scoreText;
    sf::Text endScoreText;
    sf::Text enemyCountText;

    float titleHsvCycle = 0;
    float titleHsvCycleOffset = 0.9f;

    void InitializeText(sf::RenderWindow &window);
    void drawGameText(sf::RenderWindow &window, int healthPoints, int scorePoints, int enemyCount);
    void drawTitleText(sf::RenderWindow &window);
    void drawEndText(sf::RenderWindow & window, int scorePoints);
};

#endif //UNTITLED_GAMETEXTMANAGER_H
