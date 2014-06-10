#include "Paciente.h"

Paciente::Paciente(std::string nombre, std::string codigoPulsera)
{
    m_nombre = nombre;
    m_codigoPulsera = codigoPulsera;

    m_estado            = true;
    m_tiempoInfarto     = 0.0f;
    m_ritmoCardiaco     = 66.3f;
    m_presionArterial   = 95.0f;
    m_temperatura       = 35.0f;

    m_frecuencia = m_clock.getElapsedTime();

    this->LoadResources();
}

Paciente::~Paciente()
{
    //dtor
}

void Paciente::Update()
{
    m_frecuencia    = m_clock.getElapsedTime();

    /// Frecuencia de pulsaciones cardiacas
    if (m_frecuencia.asSeconds() > (60.0f / this->GetRitmoCardiaco()))
    {
        sound.play();
        m_frecuencia = m_clock.restart();
    }

    /// Si la frecuencia cardiaca ha pasado el umbral definido
    if (this->GetRitmoCardiaco() > FRECC_MAX)
    {
        m_estado = false;  // En peligro
        m_textEstado.setString("Estado\t\t\t\t: En peligro");
    }
    else {
        m_estado = true;    // Vuelve ha estar estable
        m_clockInfarto.restart();
        m_tiempoInfarto = 0.0f;
        m_cuentaRegresiva = sf::Time::Zero;

        m_textEstado.setString("Estado\t\t\t\t: Estable");
    }

    if (m_estado == false)  // Esta en peligro!
    {
        // Calculamos el tiempo hasta el infarto
        m_cuentaRegresiva = m_clockInfarto.getElapsedTime();
        m_tiempoInfarto = TIEMPO_INF - m_cuentaRegresiva.asSeconds();
    }

    /// Mostramos datos de paciente

    m_textTiempoInfarto.setString("Tiempo Infarto  : " +
                                      convert_type::to_string(this->GetTiempoInfarto()) + " s");

    m_textRitmoCardiaco.setString("Ritmo Cardiaco  : " +
                                  convert_type::to_string(this->GetRitmoCardiaco()) + "  lat por m.");

    m_textPresionArterial.setString("Presion Arterial : " +
                                  convert_type::to_string(this->GetPresionArterial()) + "  mm Hg");

    m_textTemperatura.setString("Temperatura      : " +
                                  convert_type::to_string(this->GetTemperatura()) + "  ° C");

}

void Paciente::LoadResources()
{
    /// Texture

    if (!m_texture.loadFromFile("data/textures/paciente.png"))
        std::cout << "No se cargo textura! " << std::endl;

    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.8f, 0.8f);
    m_sprite.setPosition(sf::Vector2f(0.0f, 600 - m_sprite.getGlobalBounds().height));


    /// Text

    if (!m_font.loadFromFile("data/fonts/OpenSans-Regular.ttf"))
        std::cout << "No se cargo fuente! "<< std::endl;

    m_textNombre.setString("Paciente\t\t\t  : " + m_nombre);
    m_textNombre.setColor(sf::Color::Black);
    m_textNombre.setFont(m_font);
    m_textNombre.setCharacterSize(12);
    m_textNombre.setPosition(0.0f, 0.0f);

    m_textRitmoCardiaco.setColor(sf::Color::Black);
    m_textRitmoCardiaco.setFont(m_font);
    m_textRitmoCardiaco.setCharacterSize(12);
    m_textRitmoCardiaco.setPosition(0.0f, 20.0f);

    m_textPresionArterial.setColor(sf::Color::Black);
    m_textPresionArterial.setFont(m_font);
    m_textPresionArterial.setCharacterSize(12);
    m_textPresionArterial.setPosition(0.0f, 40.0f);

    m_textTemperatura.setColor(sf::Color::Black);
    m_textTemperatura.setFont(m_font);
    m_textTemperatura.setCharacterSize(12);
    m_textTemperatura.setPosition(0.0f, 60.0f);

    m_textEstado.setString("Estado\t\t\t\t: Estable");
    m_textEstado.setColor(sf::Color::Black);
    m_textEstado.setFont(m_font);
    m_textEstado.setCharacterSize(12);
    m_textEstado.setPosition(0.0f, 80.0f);

    m_textTiempoInfarto.setString("Tiempo Infarto  : 0 s");
    m_textTiempoInfarto.setColor(sf::Color::Black);
    m_textTiempoInfarto.setFont(m_font);
    m_textTiempoInfarto.setCharacterSize(12);
    m_textTiempoInfarto.setPosition(0.0f, 100.0f);

    /// Sounds

    if (!buffer.loadFromFile("data/sounds/latido.wav"))
        std::cout << "No se cargo sonido" << std::endl;

    sound.setBuffer(buffer);

}

void Paciente::SetRitmoCardiaco(float delta)
{
    this->m_ritmoCardiaco += delta;
}

sf::Text Paciente::GetTextNombre()
{
    return this->m_textNombre;
}

sf::Text Paciente::GetTextRitmoCardiaco()
{
    return this->m_textRitmoCardiaco;
}

sf::Text Paciente::GetTextPresionArterial()
{
    return this->m_textPresionArterial;
}
sf::Text Paciente::GetTextTemperatura()
{
    return this->m_textTemperatura;
}

sf::Text Paciente::GetTextEstado()
{
    return this->m_textEstado;

}

sf::Text Paciente::GetTextTiempoInfarto()
{
    return this->m_textTiempoInfarto;
}


sf::Sprite Paciente::GetSprite()
{
    return this->m_sprite;
}

float Paciente::GetRitmoCardiaco()
{
    return this->m_ritmoCardiaco;
}

float Paciente::GetPresionArterial()
{
    return this->m_presionArterial;
}

float Paciente::GetTemperatura()
{
    return this->m_temperatura;
}

bool Paciente::IsEstado()
{
    return this->m_estado;
}

float Paciente::GetTiempoInfarto()
{
    return this->m_tiempoInfarto;
}

std::string Paciente::GetCodigoPulsera()
{
    return this->m_codigoPulsera;
}

std::string Paciente::GetUbicacion()
{
    return this->m_ubicacionActual;
}

float Paciente::GetLatitud()
{
    return this->m_latitud;
}

float Paciente::GetLongitud()
{
    return this->m_longitud;
}

