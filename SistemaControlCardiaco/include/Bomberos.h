#ifndef BOMBEROS_H
#define BOMBEROS_H

#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "CarroParamedicos.h"

class Bomberos
{
    public:
        Bomberos();
        ~Bomberos();

        void                Update();
        sf::Sprite          GetSpriteBomberos();
        sf::Sprite          GetSpriteTelefono();
        CarroParamedicos*   GetParamedicos();

    private:

        CarroParamedicos*   m_paramedicos;

        sf::Texture         m_textureBomberos;
        sf::Sprite          m_spriteBomberos;
        sf::Texture         m_textureTelefono;
        sf::Sprite          m_spriteTelefono;

        sf::Vector2f        m_posicionBomberos;
        sf::Vector2f        m_posicionTelefono;

        sf::SoundBuffer     m_bufferTelefono;
        sf::Sound           m_soundTelefono;



        void LoadResources();
};

#endif // BOMBEROS_H
