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
        void            SetPosicion(sf::Vector2f posicion);
        float           GetVelocidad();
        void            SetVelocidad(float velocidad);
        float           GetTiempoLLegada();
        void            SetDistanciaDestino(float distancia);
        float           GetDistanciaDestino();
        bool            IsEnCamino();
        void            SetEnCamino(bool estado);

    private:

        sf::Texture     m_texture;
        sf::Sprite      m_sprite;
        sf::SoundBuffer m_buffer;
        sf::Sound       m_sound;
        sf::Vector2f    m_posicion;
        float           m_velocidad;
        float           m_tiempoLlegada;
        float           m_distanciaDestino;
        bool            m_enCamino;         // los paramedicos estan en camino

        /// Metodos privados
        void            LoadResources();
};

#endif // CARROPARAMEDICOS_H
