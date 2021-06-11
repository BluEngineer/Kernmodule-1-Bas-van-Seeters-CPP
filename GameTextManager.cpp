//
// Created by basva on 09/06/2021.
//

#include "GameTextManager.h"

GameTextManager::GameTextManager() = default;
GameTextManager::~GameTextManager() = default;

void GameTextManager::InitializeText(sf::RenderWindow &window) {
    if(!valorantFont.loadFromFile("Fonts/ValorantFont.ttf")){};
    if(!generalFont.loadFromFile("Fonts/ProximaNovaBold.otf")){};

    //StartScreentitle
    startScreenTitleText.setFont(valorantFont);
    startScreenTitleText.setCharacterSize(90);
    startScreenTitleText.setString("KERNMODULE 1");
    sf::FloatRect startScreenTitleTextRect = startScreenTitleText.getLocalBounds();
    startScreenTitleText.setOrigin(startScreenTitleTextRect.left + startScreenTitleTextRect.width/2.0f,startScreenTitleTextRect.top  + startScreenTitleTextRect.height/2.0f);
    startScreenTitleText.setPosition(sf::Vector2f((float)window.getSize().x/2.0f,(float)window.getSize().y/2.0f));

    //StartScreentext
    startScreenText.setFont(generalFont);
    startScreenText.setCharacterSize(20);
    startScreenText.setString("DOOR BAS VAN SEETERS (EPILEPSY WARNING)");
    startScreenText.setLetterSpacing(5);
    sf::FloatRect startScreenTextRect = startScreenText.getLocalBounds();
    startScreenText.setOrigin(startScreenTextRect.left + startScreenTextRect.width/2.0f,startScreenTextRect.top  + (startScreenTextRect.height/2.0f));
    startScreenText.setPosition(sf::Vector2f((float)window.getSize().x/2.0f,((float)window.getSize().y/2.0f)+ 60));

    gameOverText.setFont(valorantFont);
    gameOverText.setCharacterSize(90);
    gameOverText.setString("GAME-OVER");
    sf::FloatRect gameOvertextRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(gameOvertextRect.left + gameOvertextRect.width/2.0f,gameOvertextRect.top  + gameOvertextRect.height/2.0f);
    gameOverText.setPosition(sf::Vector2f((float)window.getSize().x/2.0f,(float)window.getSize().y/2.0f));

    livesText.setFont(generalFont);
    livesText.setString("LIVES:");
    livesText.setCharacterSize(30);
    livesText.setLetterSpacing(2);
    livesText.setPosition(30,30);

    scoreText.setFont(generalFont);
    scoreText.setCharacterSize(25);
    scoreText.setLetterSpacing(2);
    scoreText.setPosition(window.getSize().x - 200,30);

    endScoreText.setFont(generalFont);
    endScoreText.setCharacterSize(25);
    endScoreText.setLetterSpacing(2);
    sf::FloatRect endScoretextRect = endScoreText.getLocalBounds();
    endScoreText.setOrigin(endScoretextRect.left + endScoretextRect.width/2.0f,endScoretextRect.top  + (endScoretextRect.height/2.0f));
    endScoreText.setPosition(sf::Vector2f((float)window.getSize().x/2.0f,((float)window.getSize().y/2.0f)+ 45));

    enemyCountText.setFont(generalFont);
    enemyCountText.setCharacterSize(30);
    enemyCountText.setLetterSpacing(2);
    enemyCountText.setPosition(30,70);
}

void GameTextManager::drawTitleText(sf::RenderWindow &window) {
    titleHsvCycle += titleHsvCycleOffset;

    startScreenTitleText.setFillColor(hsv((int)titleHsvCycle, 1.f, 1.f));
    window.draw(startScreenTitleText);

    startScreenText.setFillColor(hsv((int)titleHsvCycle, 1.f, 1.f));
    window.draw(startScreenText);

}

void GameTextManager::drawGameText(sf::RenderWindow &window, int healthPoints, int scorePoints, int enemyCount) {


    livesText.setString( "LIVES: " + std::to_string(healthPoints) );
    window.draw(livesText);
    scoreText.setString( "SCORE: " + std::to_string(scorePoints) );
    window.draw(scoreText);
    enemyCountText.setString( "ENEMIES: " + std::to_string(enemyCount) );
    window.draw(enemyCountText);
}

void GameTextManager::drawEndText(sf::RenderWindow &window, int scorePoints) {
    titleHsvCycle += titleHsvCycleOffset;
    gameOverText.setFillColor(hsv((int)titleHsvCycle, 1.f, 1.f));
    window.draw(gameOverText);

    endScoreText.setFillColor(hsv((int)titleHsvCycle, 1.f, 1.f));
    endScoreText.setString( "YOUR SCORE WAS: " + std::to_string(scorePoints) );
    window.draw(endScoreText);

}


