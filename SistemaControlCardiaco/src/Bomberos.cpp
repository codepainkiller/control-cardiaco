#include "Bomberos.h"

Bomberos::Bomberos()
{
    // Se crea el objeto paramedicos
    m_paramedicos = new CarroParamedicos();



    //Coordenadas de objetos en la ventana
    m_posicionBomberos = sf::Vector2f(830.0f, 400.0f);
    m_posicionTelefono = sf::Vector2f(1000.0f, 500.0f);


    // Se cargan todos los recursos para este objeto
    this->LoadResources();
}

Bomberos::~Bomberos()
{
    //dtor
}

void Bomberos::Update()
{

}

void Bomberos::LoadResources()
{
    // Textures y sprites

    if (!m_textureBomberos.loadFromFile("data/textures/bomberos.png"))
        std::cout << "No se puedo cargar texture bomberos!" << std::endl;

    if (!m_textureTelefono.loadFromFile("data/textures/telefono.png"))
        std::cout << "No se puedo cargar texture telefono!" << std::endl;

    m_spriteBomberos.setTexture(m_textureBomberos);
    m_spriteTelefono.setTexture(m_textureTelefono);

    m_spriteBomberos.setScale(0.7f, 0.7f);
    m_spriteTelefono.setScale(0.45f, 0.45f);

    m_spriteBomberos.setPosition(m_posicionBomberos);
    m_spriteTelefono.setPosition(m_posicionTelefono);
}

sf::Sprite Bomberos::GetSpriteBomberos()
{
    return this->m_spriteBomberos;
}

sf::Sprite Bomberos::GetSpriteTelefono()
{
    return this->m_spriteTelefono;
}

CarroParamedicos* Bomberos::GetParamedicos()
{
    return this->m_paramedicos;
}

