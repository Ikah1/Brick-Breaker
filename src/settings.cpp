#include "../include/settings.hpp"
#include <iostream>

Ikah::Settings::Settings()
{
    darkGray = sf::Color(51, 51, 51, 250);
    settingsOpen = false;
    musicVolume = 50;
    sfxVolume = 50;
}

void Ikah::Settings::update(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        settingsOpen = true;
    }

    if (settingsOpen)
    {
        if (mouseOver(window, arrowLine.getPosition().x, arrowLine.getPosition().x + arrowLine.getSize().x, arrowLine.getPosition().y, arrowLine.getPosition().y + arrowLine.getSize().y))
        {
            if (isLeftMouseButtonPressed())
            {
                settingsOpen = false;
            }
        }

        if (mouseOverSlider(window, musicVolumeSliderLine, musicVolumeSlider))
        {
            if (isLeftMouseButtonPressed())
            {
                int mouseX = sf::Mouse::getPosition(window).x;
                musicVolumeSlider.setPosition(mouseX, musicVolumeSlider.getPosition().y);
                updateMusicVolume(musicVolumeSlider.getPosition());
            }
        }

        if (mouseOverSlider(window, sfxVolumeSliderLine, sfxVolumeSlider))
        {
            if (isLeftMouseButtonPressed())
            {
                int mouseX = sf::Mouse::getPosition(window).x;
                sfxVolumeSlider.setPosition(mouseX, sfxVolumeSlider.getPosition().y);
                updateSfxVolume(sfxVolumeSlider.getPosition());
            }
        }

        if (mouseOver(window, quitButton.getPosition().x, quitButton.getPosition().x + quitButton.getSize().x, quitButton.getPosition().y, quitButton.getPosition().y + quitButton.getSize().y))
        {
            if (isLeftMouseButtonPressed())
            {
                window.close();
            }
        }
    }
}

void Ikah::Settings::draw(sf::RenderWindow &window)
{
    if(settingsOpen)
    {
        window.draw(guiBackground);
        window.draw(arrowLine);
        window.draw(arrowHead);
        window.draw(musicVolumeText);
        window.draw(musicVolumeSliderLine);
        window.draw(musicVolumeSlider);
        window.draw(sfxVolumeText);
        window.draw(sfxVolumeSliderLine);
        window.draw(sfxVolumeSlider);
        window.draw(quitButton);
        window.draw(quitText);
    }
}

bool Ikah::Settings::isLeftMouseButtonPressed()
{
    return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Ikah::Settings::mouseOverSlider(sf::RenderWindow &window, sf::RectangleShape &sliderLine, sf::CircleShape &slider)
{
    float xStart = sliderLine.getPosition().x;
    float xEnd = sliderLine.getPosition().x + sliderLine.getSize().x - slider.getRadius() * 2;
    float yStart = sliderLine.getPosition().y;
    float yEnd = sliderLine.getPosition().y + sliderLine.getSize().y;

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool isMouseOver = mousePosition.x >= xStart && mousePosition.x <= xEnd && mousePosition.y >= yStart && mousePosition.y <= yEnd;
    return isMouseOver;
}

void Ikah::Settings::createGUI(int windowWidth, int windowHeight)
{
    //Gui background
    sf::Vector2f backgroundSize(windowWidth / 8, windowHeight / 4);
    sf::Vector2f backgroundPosition(windowWidth / 2 - backgroundSize.x / 2, windowHeight / 2 - backgroundSize.y / 2);

    guiBackground = createRectangle(backgroundSize.x, backgroundSize.y, backgroundPosition.x, backgroundPosition.y, sf::Color(darkGray));

    int backgroundMiddleX = backgroundSize.x  / 2;
    int guiVerticalSplit = backgroundSize.y / 6;

    //Back arrow
    arrowLine = createRectangle(backgroundSize.x / 10, backgroundSize.y / 60, backgroundPosition.x + 5, backgroundPosition.y + 10, sf::Color(blueCuracao));
    arrowHead.setFillColor(sf::Color(blueCuracao));
    arrowHead.setPointCount(3);
    arrowHead.setRadius(arrowLine.getSize().x / 2);
    arrowHead.setRotation(-90);
    arrowLine.setPosition(backgroundPosition.x + backgroundSize.x * 0.1f, backgroundPosition.y + 10);
    arrowHead.setPosition(arrowLine.getPosition().x - arrowHead.getRadius(), arrowLine.getPosition().y + arrowLine.getSize().y / 2 + arrowHead.getRadius());

    int sliderLineWidth = backgroundSize.x * 0.8f;
    int sliderLineHeight = sliderLineWidth / 10;
    int sliderRadius = sliderLineHeight / 2;

    //Music volume slider
    musicVolumeSliderLine = createRectangle(sliderLineWidth, sliderLineHeight, backgroundPosition.x + (backgroundMiddleX - sliderLineWidth / 2), backgroundPosition.y + guiVerticalSplit * 1.5f, sf::Color(blueCuracao));
    musicVolumeSlider.setRadius(sliderRadius);
    musicVolumeSlider.setPosition(musicVolumeSliderLine.getPosition().x + (sliderLineWidth / 2 - sliderRadius), musicVolumeSliderLine.getPosition().y + (sliderLineHeight / 2 - sliderRadius));
    musicVolumeSlider.setFillColor(sf::Color(pinkOrchid));

    //Sfx volume slider
    sfxVolumeSliderLine = createRectangle(sliderLineWidth, sliderLineHeight, backgroundPosition.x + (backgroundMiddleX - sliderLineWidth / 2), backgroundPosition.y + guiVerticalSplit * 2.5f, sf::Color(blueCuracao));
    sfxVolumeSlider.setRadius(sliderRadius);
    sfxVolumeSlider.setPosition(sfxVolumeSliderLine.getPosition().x + (sliderLineWidth / 2 - sliderRadius), sfxVolumeSliderLine.getPosition().y + (sliderLineHeight / 2 - sliderRadius));
    sfxVolumeSlider.setFillColor(sf::Color(pinkOrchid));

    //Quit button
    quitButton = createRectangle(backgroundSize.x / 2, backgroundSize.y / 6, backgroundPosition.x + backgroundMiddleX - backgroundSize.x / 4, backgroundPosition.y + guiVerticalSplit * 4.5f, sf::Color(blueCuracao));

    //Music volume text
    setCommonTextProperties(musicVolumeText, font, guiBackground.getSize().x / 10, "Music Volume", sf::Color(blueCuracao), sf::Vector2f(musicVolumeSliderLine.getPosition().x, guiBackground.getPosition().y + guiVerticalSplit));

    //Sfx volume text
    setCommonTextProperties(sfxVolumeText, font, guiBackground.getSize().x / 10, "Sfx volume", sf::Color(blueCuracao), sf::Vector2f(sfxVolumeSliderLine.getPosition().x, guiBackground.getPosition().y + guiVerticalSplit * 2));

    //Quit text
    setCommonTextProperties(quitText, font, backgroundSize.x / 6, "Quit", sf::Color(pinkOrchid), sf::Vector2f(quitButton.getPosition().x + (quitButton.getSize().x / 6), quitButton.getPosition().y + quitButton.getSize().y / 16));
    quitText.setStyle(sf::Text::Bold);
    quitText.setLetterSpacing(0.5f);
} 

void Ikah::Settings::setCommonTextProperties(sf::Text& text, const sf::Font& font, int characterSize, const std::string& string, const sf::Color& fillColor, const sf::Vector2f& position)
{
    text.setFont(font);
    text.setCharacterSize(characterSize);
    text.setString(string);
    text.setFillColor(fillColor);
    text.setPosition(position);
}

/**
 * Checks if the mouse is within a specified area on the window.
 */
bool Ikah::Settings::mouseOver(sf::RenderWindow& window, float xStart, float xEnd, float yStart, float yEnd)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    bool isMouseOver = mousePosition.x >= xStart && mousePosition.x <= xEnd && mousePosition.y >= yStart && mousePosition.y <= yEnd;
    return isMouseOver;
}

//Creates a rectangle
sf::RectangleShape Ikah::Settings::createRectangle(float width, float height, float x, float y, sf::Color color)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(sf::Color(color));
    return rectangle;
}

/**
 * Updates the music volume based on the position of the music volume slider.
 */
void Ikah::Settings::updateMusicVolume(sf::Vector2f position)
{
    // Calculate the minimum and maximum x positions of the music volume slider line
    int min = musicVolumeSliderLine.getPosition().x;
    int max = min + musicVolumeSliderLine.getSize().x - musicVolumeSlider.getRadius() * 2;

    // Calculate the percentage of the position within the range of the music volume slider line
    float percentage = (position.x - min) / static_cast<float>(max - min);

    // Update the music volume
    musicVolume = static_cast<int>(percentage * 100);
}

void Ikah::Settings::updateSfxVolume(sf::Vector2f position)
{
    // Calculate the minimum and maximum x positions of the SFX volume slider line
    int min = sfxVolumeSliderLine.getPosition().x;
    int max = min + sfxVolumeSliderLine.getSize().x - sfxVolumeSlider.getRadius() * 2;

    // Calculate the percentage of the position within the range of the SFX volume slider line
    float percentage = (position.x - min) / static_cast<float>(max - min);

    // Update the SFX volume based on the calculated percentage
    sfxVolume = static_cast<int>(percentage * 100);
}

void Ikah::Settings::setFont(sf::Font &font)
{
    this->font = font;
}

int Ikah::Settings::getMusicVolume()
{
    return this->musicVolume;
}

int Ikah::Settings::getSfxVolume()
{
    return this->sfxVolume;
}