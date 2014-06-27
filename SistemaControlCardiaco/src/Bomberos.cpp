#include "Bomberos.h"

Bomberos::Bomberos()
{
    // Se crea el objeto paramedicos
    m_paramedicos = new CarroParamedicos();

    //Coordenadas de objetos en la ventana
    m_posicionBomberos = sf::Vector2f(830.0f, 400.0f);
    m_posicionTelefono = sf::Vector2f(1000.0f, 500.0f);
    m_posicionBaseParamedicos = sf::Vector2f(700.0f, 510.0f);

    m_existeEmergencia = false;

    // Se cargan todos los recursos para este objeto
    this->LoadResources();
}

Bomberos::~Bomberos()
{
    //dtor
}

void Bomberos::Update()
{
    m_paramedicos->Update();

    if (!m_pacienteEnEmergencia->IsEnPeligro())
    {
        m_existeEmergencia = false;
    }

    if (this->m_existeEmergencia)
    {
        /// Enviar paramedicos: Controlar la velocidad y distancia

        sf::Vector2f posicion = m_paramedicos->GetPosicion();
        posicion.x -= 0.5f;;

        if (posicion.x > 80.0f)
        {
            m_paramedicos->SetPosicion(posicion);
            m_paramedicos->SetEnCamino(false);

        }
        else {
            m_paramedicos->SetSound(false);
        }
    }
    else {
        m_paramedicos->SetPosicion(m_posicionBaseParamedicos);

        m_paramedicos->SetEnCamino(false);
    }

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

void Bomberos::RecibeLlamadaEmergencia(Paciente* paciente)
{
    // Se recibe datos del paciente para su ubicacion
    this->m_pacienteEnEmergencia = paciente;
    m_paramedicos->SetEnCamino(true);
    m_existeEmergencia = true;

    // Enviamos paramedicos
    m_paramedicos->SetEnCamino(true);
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


