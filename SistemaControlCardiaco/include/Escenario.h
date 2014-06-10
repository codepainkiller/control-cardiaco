#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Escenario
{
    public:
        Escenario();
        ~Escenario();
        void        Update();
        sf::Sprite  GetSpriteOndas1();
        sf::Sprite  GetSpriteOndas2();
        sf::Sprite  GetSpriteAntena();

    private:

        sf::Texture m_textureAntena;
        sf::Sprite  m_spriteAntena;
        sf::Texture m_textureOndas;
        sf::Sprite  m_spriteOndas1;
        sf::Sprite  m_spriteOndas2;

        sf::Vector2f m_posicionAntena;
        sf::Vector2f m_posicionOndas1;
        sf::Vector2f m_posicionOndas2;

        void LoadResources();
};

#endif // ESCENARIO_H
