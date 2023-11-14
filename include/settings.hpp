#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "definitions.hpp"

namespace Ikah
{
    class Settings
    {
        public:
            Settings();
            void draw(sf::RenderWindow &window);
            void update(sf::RenderWindow &window);
            void setFont(sf::Font &font);
            void createGUI(int windowWidth, int windowHeight);
            int getMusicVolume();
            int getSfxVolume();
        private:
            int windowWidth, windowHeight;
            bool settingsOpen;

            int musicVolume, sfxVolume;

            bool mouseOver(sf::RenderWindow &window, float xStart, float xEnd, float yStart, float yEnd);
            sf::RectangleShape createRectangle(float width, float height, float x, float y, sf::Color color);
            bool mouseOverSlider(sf::RenderWindow &window, sf::RectangleShape &sliderLine, sf::CircleShape &slider);
            bool isLeftMouseButtonPressed();

            void updateMusicVolume(sf::Vector2f position);
            void updateSfxVolume(sf::Vector2f position);
            void setCommonTextProperties(sf::Text& text, const sf::Font& font, int characterSize, const std::string& string, const sf::Color& fillColor, const sf::Vector2f& position);

            sf::Color backgroundColor;
            sf::Font font;

            sf::RectangleShape guiBackground;
            //Back arrow
            sf::Sprite arrow;
            sf::Texture arrowTexture;
            //Volume Sliders
            sf::Text musicVolumeText;
            sf::Text sfxVolumeText;
            sf::RectangleShape musicVolumeSliderLine;
            sf::CircleShape musicVolumeSlider;
            sf::RectangleShape sfxVolumeSliderLine;
            sf::CircleShape sfxVolumeSlider;
            //Quit button
            sf::Sprite quitButton;
            sf::Texture quitTexture;
            sf::Text quitText;
    };
}

#endif