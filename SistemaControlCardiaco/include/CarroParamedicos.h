#ifndef CARROPARAMEDICOS_H
#define CARROPARAMEDICOS_H

#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class CarroParamedicos
{
    public:
        CarroParamedicos();
        ~CarroParamedicos();
        void            Update();
        sf::Sprite      GetSprite();
        sf::Vector2f    GetPosicion();
        float           GetVelocidad();
        float           SetVelocidad(float velocidad);
        float           GetTiempoLLegada();
        void            SetDistanciaDestino(float distancia);
        float           GetDistanciaDestino();

    private:

        sf::Texture     m_texture;
        sf::Sprite      m_sprite;
        sf::SoundBuffer m_buffer;
        sf::Sound       m_sound;
        sf::Vector2f    m_posicion;
        float           m_velocidad;
        float           m_tiempoLlegada;
        float           m_distanciaDestino;

        /// Metodos privados
        void            LoadResources();
};

#endif // CARROPARAMEDICOS_H
