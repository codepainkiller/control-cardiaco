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

        sf::Sprite GetSprite();

    private:

        CarroParamedicos*   m_paramedicos;

        sf::Texture         m_textureBomberos;
        sf::Sprite          m_spriteBomberos;
        sf::Texture         m_textureTelefono;
        sf::Sprite          m_spriteTelefono;

        sf::SoundBuffer     m_bufferTelefono;
        sf::Sound           m_soundTelefono;



        void LoadResources();
};

#endif // BOMBEROS_H
