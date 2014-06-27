#include "Escenario.h"

Escenario::Escenario()
{
    m_posicionAntena = sf::Vector2f(450.0f, 0.0f);
    m_posicionOndas1 = sf::Vector2f(20.0f, 400.0f);
    m_posicionOndas2 = sf::Vector2f(600.0f, 0.0f);
    m_posicionOndas3 = sf::Vector2f(1000.0f, 200.0f);

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
    m_spriteOndas3.setTexture(m_textureOndas);

    m_spriteAntena.setPosition(m_posicionAntena);
    m_spriteOndas1.setPosition(m_posicionOndas1);
    m_spriteOndas2.setPosition(m_posicionOndas2);
    m_spriteOndas3.setPosition(m_posicionOndas3);

    m_spriteAntena.scale(0.6f, 0.6f);
    m_spriteOndas1.scale(1.5f, 1.0f);
    m_spriteOndas2.scale(0.8f, 1.0f);
    m_spriteOndas3.scale(0.8f, 1.0f);

    m_spriteOndas1.rotate(-40.0f);
    m_spriteOndas2.rotate(15.0f);
    m_spriteOndas3.rotate(90.0f);

    if (!m_font.loadFromFile("data/fonts/OpenSans-Regular.ttf"))
        std::cout << "No se cargo font Escenario" << std::endl;

    m_textOndas1.setFont(m_font);
    m_textOndas2.setFont(m_font);
    m_textOndas3.setFont(m_font);

    m_textOndas1.setColor(sf::Color::Red);
    m_textOndas2.setColor(sf::Color::Red);
    m_textOndas3.setColor(sf::Color::Red);

    m_textOndas1.setCharacterSize(15);
    m_textOndas2.setCharacterSize(15);
    m_textOndas3.setCharacterSize(15);

    m_textOndas1.setPosition(150.0f, 300.0f);
    m_textOndas2.setPosition(650.0f, 30.0f);
    m_textOndas3.setPosition(1030.0f, 250.0f);

    m_textOndas1.setRotation(-45);
    m_textOndas3.setRotation(90);

    m_textOndas1.setString("Mensaje de alerta");
    m_textOndas2.setString("Mensaje de alerta");
    m_textOndas3.setString("Llamada a bomberos");
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

sf::Text Escenario::GetTextOndas1()
{
    return this->m_textOndas1;
}

sf::Text Escenario::GetTextOndas2()
{
    return this->m_textOndas2;
}

sf::Sprite Escenario::GetSpriteOndas3()
{
    return this->m_spriteOndas3;
}

sf::Text Escenario::GetTextOndas3()
{
    return this->m_textOndas3;
}
