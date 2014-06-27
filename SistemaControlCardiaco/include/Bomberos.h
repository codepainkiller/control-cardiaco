#ifndef BOMBEROS_H
#define BOMBEROS_H

#include "CarroParamedicos.h"
#include "Paciente.h"

#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



class Bomberos
{
    public:
        Bomberos();
        ~Bomberos();

        void                Update();
        sf::Sprite          GetSpriteBomberos();
        sf::Sprite          GetSpriteTelefono();
        CarroParamedicos*   GetParamedicos();
        void                RecibeLlamadaEmergencia(Paciente* paciente);

    private:

        CarroParamedicos*   m_paramedicos;
        Paciente*           m_pacienteEnEmergencia;

        sf::Texture         m_textureBomberos;
        sf::Sprite          m_spriteBomberos;
        sf::Texture         m_textureTelefono;
        sf::Sprite          m_spriteTelefono;

        sf::Vector2f        m_posicionBomberos;
        sf::Vector2f        m_posicionTelefono;
        sf::Vector2f        m_posicionBaseParamedicos;

        sf::SoundBuffer     m_bufferTelefono;
        sf::Sound           m_soundTelefono;

        bool                m_existeEmergencia;

        void LoadResources();
};

#endif // BOMBEROS_H
