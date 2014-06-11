#include "CarroParamedicos.h"

CarroParamedicos::CarroParamedicos()
{
    // Construimos el objeto
    m_posicion  = sf::Vector2f(700.0f, 510.0f);

    this->LoadResources();
}

CarroParamedicos::~CarroParamedicos()
{
    //dtor
}

void CarroParamedicos::Update()
{

}

void CarroParamedicos::LoadResources()
{
    // Texturas y sprites
    if (!m_texture.loadFromFile("data/textures/ambulancia2.png"))
        std::cout << "No se cargo textura ambulancia!" << std::endl;

    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_posicion);

    // Sonidos
    if (!m_buffer.loadFromFile("data/sounds/ambulancia.wav"))
       std::cout << "No se cargo buffeSound ambulancia!" << std::endl;

    m_sound.setBuffer(m_buffer);
}


sf::Sprite CarroParamedicos::GetSprite()
{
    return this->m_sprite;
}

sf::Vector2f CarroParamedicos::GetPosicion()
{
    return this->m_posicion;
}

float CarroParamedicos::GetVelocidad()
{
    return this->m_velocidad;
}

float CarroParamedicos::SetVelocidad(float velocidad)
{
    this->m_velocidad = velocidad;
}

float CarroParamedicos::GetTiempoLLegada()
{
    return this->m_tiempoLlegada;
}

void CarroParamedicos::SetDistanciaDestino(float distancia)
{
    this->m_distanciaDestino = distancia;
}

float CarroParamedicos::GetDistanciaDestino()
{
    return this->m_distanciaDestino;
}


