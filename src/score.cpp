#include "../include/score.hpp"
#include <iostream>

void Ikah::Score::createScoreText()
{
    score = 0;
    font.loadFromFile("../assets/fonts/NERDFONT-REGULAR.TTF");
    scoreText.setFont(font);
    scoreText.setString(std::to_string(score));
    scoreText.setCharacterSize(windowDimensions.x / 16);
    scoreText.setPosition(scoreText.getCharacterSize(), windowDimensions.y - scoreText.getCharacterSize() * 2);
    scoreText.setFillColor(sf::Color(blueCuracao));
    scoreText.setOutlineColor(sf::Color(pinkOrchid));
    scoreText.setOutlineThickness(scoreText.getCharacterSize() / 16);
}

void Ikah::Score::draw(sf::RenderWindow &window)
{
    window.draw(scoreText);
}

void Ikah::Score::setScore(int score)
{
    this->score = score;
    scoreText.setString(std::to_string(score));
}

int Ikah::Score::getScore()
{
    return this->score;
}

void Ikah::Score::getWindowDimensions(int width, int height)
{
    windowDimensions = sf::Vector2i(width, height);
}