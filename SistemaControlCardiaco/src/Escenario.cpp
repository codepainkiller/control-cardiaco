#include "Escenario.h"

Escenario::Escenario()
{
    m_posicionAntena = sf::Vector2f(450.0f, 0.0f);
    m_posicionOndas1 = sf::Vector2f(20.0f, 400.0f);
    m_posicionOndas2 = sf::Vector2f(600.0f, 0.0f);

    this->LoadResources();
}

Escenario::~Escenario()
{
    //dtor
}

void Escenario::LoadResources()
{
    if (!m_textureAntena.loadFromFile("data/textures/antena.png"))
        std::cout << "No se cargo texture antena!" << std::endl;

    if (!m_textureOndas.loadFromFile("data/textures/ondas.png"))
        std::cout << "No se cargo textura de ondas!" << std::endl;

    m_spriteAntena.setTexture(m_textureAntena);
    m_spriteOndas1.setTexture(m_textureOndas);
    m_spriteOndas2.setTexture(m_textureOndas);

    m_spriteAntena.setPosition(m_posicionAntena);
    m_spriteOndas1.setPosition(m_posicionOndas1);
    m_spriteOndas2.setPosition(m_posicionOndas2);

    m_spriteAntena.scale(0.2f, 0.2f);
    m_spriteOndas1.scale(1.5f, 1.0f);
    m_spriteOndas2.scale(0.8f, 1.0f);

    m_spriteOndas1.rotate(-40.0f);
    m_spriteOndas2.rotate(15.0f);

}

void Escenario::Update()
{

}

sf::Sprite Escenario::GetSpriteOndas1()
{
    return this->m_spriteOndas1;
}

sf::Sprite Escenario::GetSpriteOndas2()
{
    return this->m_spriteOndas2;
}

sf::Sprite Escenario::GetSpriteAntena()
{
    return this->m_spriteAntena;
}

