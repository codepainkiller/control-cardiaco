#include "CarroParamedicos.h"

CarroParamedicos::CarroParamedicos()
{
    /// Construimos el objeto

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
    if (!m_texture.loadFromFile("data/textures/bomberos/ambulancia.png"))
        std::cout << "No se cargo textura ambulancia!" << std::endl;

    m_sprite.setTexture(m_texture);

    // Sonidos
    if (!m_buffer.loadFromFile("data/sounds/ambulance.wav"))
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
