#include "Paciente.h"

Paciente::Paciente(std::string nombre, std::string codigoPulsera)
{
    m_nombre = nombre;
    m_codigoPulsera = codigoPulsera;

    m_estado            = true;
    m_ritmoCardiaco     = 65.3f;
    m_presionArterial   = 0.15f;
    m_temperatura       = 25.0f;

    this->LoadResources();
}

Paciente::~Paciente()
{
    //dtor
}

void Paciente::LoadResources()
{
    // Texture

    if (!m_texture.loadFromFile("data/textures/paciente/paciente.png"))
        std::cout << "No se cargo textura! " << std::endl;

    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(sf::Vector2f(0.0f, 0.0f));

    // Text

    if (!m_font.loadFromFile("data/fonts/OpenSans-Regular.ttf"))
        std::cout << "No se cargo fuente! "<< std::endl;

    m_textNombre.setString("Paciente: " + m_nombre);
    m_textNombre.setFont(m_font);
    m_textNombre.setCharacterSize(15);
    m_textNombre.setPosition(100.0f, 0.0f);

    m_textRitmoCardiaco.setString("Ritmo Cardiaco: " + covert_type::to_string(m_ritmoCardiaco));
    m_textRitmoCardiaco.setFont(m_font);
    m_textRitmoCardiaco.setCharacterSize(15);
    m_textRitmoCardiaco.setPosition(100.0f, 50.0f);

}

sf::Text Paciente::GetTextNombre()
{
    return this->m_textNombre;
}

sf::Text Paciente::GetTextRitmoCardiaco()
{
    return this->m_textRitmoCardiaco;
}

void Paciente::SetRitmoCardiaco(float delta)
{
    this->m_ritmoCardiaco += delta;
}

void Paciente::Update()
{
    m_textRitmoCardiaco.setString("Ritmo Cardiaco: " +
                                  covert_type::to_string(this->GetRitmoCardiaco()));
}



sf::Sprite Paciente::GetSprite()
{
    return m_sprite;
}


float Paciente::GetRitmoCardiaco()
{
    return m_ritmoCardiaco;
}

float Paciente::GetPresionArterial()
{
    return m_presionArterial;
}

float Paciente::GetTemperatura()
{
    return m_temperatura;
}

bool Paciente::IsEstado()
{
    return m_estado;
}

float Paciente::GetTiempoInfarto()
{
    return m_tiempoInfarto;
}

std::string Paciente::GetCodigoPulsera()
{
    return m_codigoPulsera;
}

std::string Paciente::GetUbicacion()
{
    return m_ubicacionActual;
}

float Paciente::GetLatitud()
{
    return m_latitud;
}

float Paciente::GetLongitud()
{
    return m_longitud;
}

