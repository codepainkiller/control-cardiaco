#include "Hospital.h"

Hospital::Hospital()
{
    m_bomberos = new Bomberos();
    //Valors iniciales
    m_posicionHospital = sf::Vector2f(830.0f, 0.0f);

    this->LoadResources();
}

Hospital::~Hospital()
{
    //dtor
}

void Hospital::Update()
{
    m_bomberos->Update();
}

void Hospital::SetEmergencia(Paciente* paciente)
{
    this->m_pacienteEnPeligro = paciente;

    /// Falta: mostrar ubicacion por pantalla y vista del mapa

    this->LlamarBomberos();
}

void Hospital::LlamarBomberos()
{
    m_bomberos->RecibeLlamadaEmergencia(m_pacienteEnPeligro);
}

void Hospital::LoadResources()
{
    // Textures y sprite

    if (!m_textureHospital.loadFromFile("data/textures/hospital.png"))
        std::cout << "No se puedo cargar texture hospital" << std::endl;

    m_spriteHospital.setTexture(m_textureHospital);
    m_spriteHospital.setScale(0.9f, 0.9f);

    m_spriteHospital.setPosition(m_posicionHospital);
}

sf::Sprite Hospital::GetSpriteHospital()
{
    return this->m_spriteHospital;
}

Bomberos* Hospital::GetBomberos()
{
    return this->m_bomberos;
}




