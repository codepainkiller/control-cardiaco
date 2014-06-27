#include "CarroParamedicos.h"

CarroParamedicos::CarroParamedicos()
{
    // Construimos el objeto
    this->m_posicion  = sf::Vector2f(700.0f, 510.0f);
    this->m_enCamino  = false;

    this->LoadResources();
}

CarroParamedicos::~CarroParamedicos()
{
    //dtor
}

void CarroParamedicos::Update()
{
    m_sprite.setPosition(m_posicion);

    if (this->IsEnCamino() && sf::Sound::Stopped == m_sound.getStatus())
        m_sound.play();

    if (!this->IsEnCamino())
        m_sound.stop();

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
    m_sound.setVolume(40.0f);
    m_sound.setLoop(true);
}
bool CarroParamedicos::IsEnCamino()
{
    return this->m_enCamino;
}

void CarroParamedicos::SetEnCamino(bool estado)
{
    this->m_enCamino = estado;
}

void CarroParamedicos::SetPosicion(sf::Vector2f posicion)
{
    this->m_posicion = posicion;
}

void CarroParamedicos::SetVelocidad(float velocidad)
{
    this->m_velocidad = velocidad;
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

void CarroParamedicos::SetSound(bool estado)
{
    if (estado)
        m_sound.play();
    else
        m_sound.stop();
}

