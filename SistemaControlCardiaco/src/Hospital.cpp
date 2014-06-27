#include "Hospital.h"

Hospital::Hospital()
{
    m_bomberos = new Bomberos();
    //Valors iniciales
    m_posicionHospital = sf::Vector2f(830.0f, 0.0f);

    m_emergencia = false;

    this->LoadResources();
}

Hospital::~Hospital()
{
    //dtor
}

void Hospital::Update()
{
    m_bomberos->Update();

    if (this->IsEmergencia() && m_pacienteEnPeligro->IsEnPeligro())
    {
        m_textCodigoPulsera.setString("Cod. Pulsera\t: " +
                                    convert_type::to_string(m_pacienteEnPeligro->GetCodigoPulsera()));
        m_textPaciente.setString("Paciente\t\t   : " +
                                  convert_type::to_string(m_pacienteEnPeligro->GetNombre()));
        m_textTiempoInfarto.setString("Tiempo infarto: " +
                                  convert_type::to_string(m_pacienteEnPeligro->GetTiempoInfarto()) + "  s");
        m_textUbicacion.setString("Ubicacion\t\t : " +
                                    convert_type::to_string(m_pacienteEnPeligro->GetUbicacion()));
    }
    else
    {
        m_textCodigoPulsera.setString("Cod. Pulsera\t:     - ");
        m_textPaciente.setString("Paciente\t\t   :     -");
        m_textTiempoInfarto.setString("Tiempo infarto:     -");
        m_textUbicacion.setString("Ubicacion\t\t :     -");
    }

}

void Hospital::SetEmergencia(Paciente* paciente)
{
    this->m_pacienteEnPeligro = paciente;

    m_emergencia = true;

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

    if (!m_font.loadFromFile("data/fonts/OpenSans-Regular.ttf"))
        std::cout << "Nose cargo la fuente!" << std::endl;

    m_textPaciente.setFont(m_font);
    m_textTiempoInfarto.setFont(m_font);
    m_textUbicacion.setFont(m_font);
    m_textCodigoPulsera.setFont(m_font),

    m_textPaciente.setColor(sf::Color::Black);
    m_textTiempoInfarto.setColor(sf::Color::Black);
    m_textUbicacion.setColor(sf::Color::Black);
    m_textCodigoPulsera.setColor(sf::Color::Black);

    m_textPaciente.setCharacterSize(15);
    m_textTiempoInfarto.setCharacterSize(15);
    m_textUbicacion.setCharacterSize(15);
    m_textCodigoPulsera.setCharacterSize(15);

    m_textCodigoPulsera.setPosition(600.0f, 160.0f);
    m_textPaciente.setPosition(600.0f, 180.0f);
    m_textTiempoInfarto.setPosition(600.0f, 200.0f);
    m_textUbicacion.setPosition(600.0f, 220.0f);

}

sf::Sprite Hospital::GetSpriteHospital()
{
    return this->m_spriteHospital;
}

Bomberos* Hospital::GetBomberos()
{
    return this->m_bomberos;
}

sf::Text Hospital::GetTextUbicacion()
{
    return this->m_textUbicacion;
}

sf::Text Hospital::GetTextTiempoInfarto()
{
    return this->m_textTiempoInfarto;
}

sf::Text Hospital::GetTextPaciente()
{
    return this->m_textPaciente;
}

bool Hospital::IsEmergencia()
{
    return this->m_emergencia;
}

sf::Text Hospital::GetTextCodigoPulsera()
{
    return this->m_textCodigoPulsera;
}
