#ifndef ESCENARIO_H
#define ESCENARIO_H


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>

class Escenario
{
    public:
        Escenario();
        ~Escenario();
        void        Update();
        sf::Sprite  GetSpriteOndas1();
        sf::Sprite  GetSpriteOndas2();
        sf::Sprite  GetSpriteOndas3();
        sf::Sprite  GetSpriteAntena();

        sf::Text    GetTextOndas1();
        sf::Text    GetTextOndas2();
        sf::Text    GetTextOndas3();

    private:

        sf::Texture m_textureAntena;
        sf::Sprite  m_spriteAntena;
        sf::Texture m_textureOndas;
        sf::Sprite  m_spriteOndas1;
        sf::Sprite  m_spriteOndas2;
        sf::Sprite  m_spriteOndas3;

        sf::Font m_font;
        sf::Text m_textOndas1;
        sf::Text m_textOndas2;
        sf::Text m_textOndas3;

        sf::Vector2f m_posicionAntena;
        sf::Vector2f m_posicionOndas1;
        sf::Vector2f m_posicionOndas2;
        sf::Vector2f m_posicionOndas3;

        void LoadResources();
};

#endif // ESCENARIO_H
