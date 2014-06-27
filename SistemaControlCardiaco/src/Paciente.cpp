#include "Paciente.h"

Paciente::Paciente(std::string nombre, std::string codigoPulsera)
{
    this->m_nombre = nombre;
    this->m_codigoPulsera = codigoPulsera;

    m_estaVivo          = true;
    m_enPeligro         = false;
    m_tiempoInfarto     = 0.0f;
    m_ritmoCardiaco     = 66.0f;
    m_presionArterial   = 95.2f;
    m_temperatura       = 35.6f;
    m_longitud          = "2° 10' 26.508";
    m_latitud           = "41° 24' 12.1674'";
    m_ubicacionActual   = m_latitud + ", " + m_longitud;

    m_cuentaRegresiva   = sf::Time::Zero;

    m_frecuencia = m_clock.getElapsedTime();

    this->LoadResources();
}

Paciente::~Paciente()
{
    //dtor
}


void Paciente::Update()
{
    m_frecuencia        = m_clock.getElapsedTime();

    /// Sonidos y frecuencia cardiaca

    if (m_frecuencia.asSeconds() > (60.0f / this->GetRitmoCardiaco()))
    {
            m_soundCorazonDetenido.stop();
            m_soundLatido.play();
            m_frecuencia = m_clock.restart();

            // El sonido de alerta sonara al mismo tiempo que el corazon
            if (m_enPeligro)
                m_soundAlerta.play();
            else if (this->GetRitmoCardiaco() > 0 && this->GetRitmoCardiaco() < 60)
                m_soundAlerta.play();
    }


    /// Control de estados de corazon de paciente

    if (m_estaVivo)
    {
        if (this->GetRitmoCardiaco() > FRECC_MAX)
        {
            m_enPeligro = true;

            if (m_tiempoInfarto < 0)
            {
                m_estaVivo      = false;
                m_ritmoCardiaco = 0.0f;
                m_tiempoInfarto = 0;
                m_soundCorazonDetenido.play();
            }
            else
            {
                m_cuentaRegresiva += m_clockInfarto.restart();
                m_tiempoInfarto = TIEMPO_INF - m_cuentaRegresiva.asSeconds();
                m_textEstado.setString("Estado\t\t\t\t: En peligro");
            }
        }
        else
        {
            m_enPeligro       = false;
            m_cuentaRegresiva = sf::Time::Zero;
            m_tiempoInfarto   = 0.0f;
            m_clockInfarto.restart();
            m_textEstado.setString("Estado\t\t\t\t: Estable");
        }
    }
    else
    {
        if (m_ritmoCardiaco > 60)
        {
            m_estaVivo   = true;
            m_enPeligro  = false;
        }

        m_textEstado.setString("Estado\t\t\t\t: Paro cardiaco");
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
    /// Texture y sprites

    if (!m_texture.loadFromFile("data/textures/paciente.png"))
        std::cout << "No se cargo textura! " << std::endl;

    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.8f, 0.8f);
    m_sprite.setPosition(sf::Vector2f(0.0f, 600 - m_sprite.getGlobalBounds().height));


    /// Text por pantalla

    if (!m_font.loadFromFile("data/fonts/OpenSans-Regular.ttf"))
        std::cout << "No se cargo fuente! "<< std::endl;

    m_textNombre.setString("Paciente\t\t\t  : " + m_nombre);
    m_textNombre.setColor(sf::Color::Black);
    m_textNombre.setFont(m_font);
    m_textNombre.setCharacterSize(15);
    m_textNombre.setPosition(20.0f, 100.0f);

    m_textRitmoCardiaco.setColor(sf::Color::Black);
    m_textRitmoCardiaco.setFont(m_font);
    m_textRitmoCardiaco.setCharacterSize(15);
    m_textRitmoCardiaco.setPosition(20.0f, 120.0f);

    m_textPresionArterial.setColor(sf::Color::Black);
    m_textPresionArterial.setFont(m_font);
    m_textPresionArterial.setCharacterSize(15);
    m_textPresionArterial.setPosition(20.0f, 140.0f);

    m_textTemperatura.setColor(sf::Color::Black);
    m_textTemperatura.setFont(m_font);
    m_textTemperatura.setCharacterSize(15);
    m_textTemperatura.setPosition(20.0f, 160.0f);

    m_textEstado.setString("Estado\t\t\t\t: Estable");
    m_textEstado.setColor(sf::Color::Black);
    m_textEstado.setFont(m_font);
    m_textEstado.setCharacterSize(15);
    m_textEstado.setPosition(20.0f, 180.0f);

    m_textTiempoInfarto.setString("Tiempo Infarto  : 0 s");
    m_textTiempoInfarto.setColor(sf::Color::Black);
    m_textTiempoInfarto.setFont(m_font);
    m_textTiempoInfarto.setCharacterSize(15);
    m_textTiempoInfarto.setPosition(20.0f, 200.0f);

    /// Sounds

    if (!m_bufferLatido.loadFromFile("data/sounds/latido.wav"))
        std::cout << "No se cargo sonido" << std::endl;

    if (!m_bufferAlerta.loadFromFile("data/sounds/alerta_pulsera.wav"))
        std::cout << "No se cargo sonido" << std::endl;

    if (!m_bufferCorazonDetenido.loadFromFile("data/sounds/corazon_detenido.wav"))
        std::cout << "No se cargo sonido" << std::endl;

    m_soundLatido.setBuffer(m_bufferLatido);
    m_soundAlerta.setBuffer(m_bufferAlerta);
    m_soundCorazonDetenido.setBuffer(m_bufferCorazonDetenido);

    m_soundCorazonDetenido.setLoop(true);

    m_soundCorazonDetenido.setVolume(8.0f);
    m_soundAlerta.setVolume(10.0f);

}

void Paciente::SetRitmoCardiaco(float delta)
{
    this->m_ritmoCardiaco += delta;
}
void Paciente::SetPresionArterial(float delta)
{
    this->m_presionArterial +=delta;
}

void Paciente::SetTemperatura(float delta)
{
    this->m_temperatura += delta;
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

bool Paciente::IsEstaVivo()
{
    return this->m_estaVivo;
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

std::string  Paciente::GetLatitud()
{
    return this->m_latitud;
}

std::string  Paciente::GetLongitud()
{
    return this->m_longitud;
}

bool Paciente::IsEnPeligro()
{
    return this->m_enPeligro;
}
std::string Paciente::GetNombre()
{
    return this->m_nombre;
}

