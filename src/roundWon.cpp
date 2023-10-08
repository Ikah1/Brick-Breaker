#include "../include/roundWon.hpp"

Ikah::RoundWon::RoundWon()
{
    //Load font
    font.loadFromFile("../assets/fonts/NERDFONT-REGULAR.TTF");
}

void Ikah::RoundWon::draw(sf::RenderWindow &window)
{
    window.draw(quitButton);
    window.draw(quitText);
    window.draw(winText);
    window.draw(scoreText);
}

bool Ikah::RoundWon::noBricks(std::vector<sf::RectangleShape> bricks)
{
    //Return true if there are no bricks left and false if there are and create quit dialog
    if (bricks.size() == 0)
    {
        createDialogBox();
        return true;
    }
    return false;
}

void Ikah::RoundWon::getWindowDimensions(int width, int height)
{
    //Get and set window dimensions
    this->windowWidth = width;
    this-> windowHeight = height;
}

void Ikah::RoundWon::createDialogBox()
{
    //Create quit button
    quitButton.setSize(sf::Vector2f(windowWidth / 12, windowHeight / 16));
    quitButton.setPosition(windowWidth / 2 - quitButton.getSize().x / 2, windowHeight / 2 - quitButton.getSize().y / 2);
    quitButton.setFillColor(sf::Color(lilacRose));
    quitButton.setOutlineColor(sf::Color(pinkOrchid));
    quitButton.setOutlineThickness(quitButton.getSize().x / 14);
    
    //Create quit text
    quitText.setFont(font);
    quitText.setString("Quit");
    quitText.setCharacterSize(quitButton.getSize().x / 2.5f);
    quitText.setPosition(quitButton.getPosition().x + quitButton.getSize().x / 2 - quitText.getGlobalBounds().width / 2, quitButton.getPosition().y + quitButton.getSize().y / 2 - quitText.getGlobalBounds().height / 1.25f);
    quitText.setFillColor(sf::Color(pinkOrchid));
    quitText.setOutlineColor(sf::Color(blueCuracao));
    quitText.setOutlineThickness(quitText.getCharacterSize() / 15);

    //Create win text
    winText.setFont(font);
    winText.setString("You Win!");
    winText.setCharacterSize(quitButton.getSize().x / 2);
    winText.setPosition(quitButton.getPosition().x + quitButton.getSize().x / 2 - winText.getGlobalBounds().width / 2, quitButton.getPosition().y - winText.getGlobalBounds().height - 50);
    winText.setFillColor(sf::Color(pinkOrchid));
    winText.setOutlineColor(sf::Color(blueCuracao));
    winText.setOutlineThickness(winText.getCharacterSize() / 16);

    //Create score text
    scoreText.setFont(font);
    scoreText.setCharacterSize(quitButton.getSize().x / 2);
    scoreText.setPosition(windowWidth / 2 - scoreText.getGlobalBounds().width / 2, quitButton.getPosition().y + quitButton.getSize().y + 10);
    scoreText.setFillColor(sf::Color(pinkOrchid));
    scoreText.setOutlineColor(sf::Color(blueCuracao));
    scoreText.setOutlineThickness(scoreText.getCharacterSize() / 16);
}

void Ikah::RoundWon::quit(sf::RenderWindow &window)
{
    //Check if mouse is in the quit button area
    while (sf::Mouse::getPosition(window).x >= quitButton.getPosition().x && sf::Mouse::getPosition(window).x <= quitButton.getPosition().x + quitButton.getSize().x && sf::Mouse::getPosition(window).y >= quitButton.getPosition().y && sf::Mouse::getPosition(window).y <= quitButton.getPosition().y + quitButton.getSize().y)
    {
        //Close the window if the left button is pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            window.close();
        }
    }
}

void Ikah::RoundWon::setScoreText(int score)
{
    //Create score text
    scoreText.setString("Your Score is: " + std::to_string(score));
    
}
