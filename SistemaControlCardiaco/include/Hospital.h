#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Hospital
{
    public:
        Hospital();
        ~Hospital();

        sf::Sprite  GetSpriteHospital();
        void        Update();

    private:

        sf::Texture     m_textureHospital;
        sf::Sprite      m_spriteHospital;

        sf::Vector2f    m_posicionHospital;

        void LoadResources();
};

#endif // HOSPITAL_H
