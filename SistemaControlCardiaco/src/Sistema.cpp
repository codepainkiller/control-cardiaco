#include "Sistema.h"

Sistema::Sistema(): m_window(sf::VideoMode(window_width, window_heigth, 32), "Sistema Control Cardiaco")
{
    // Activa la sincronización vertical (60 fps)
    m_window.setVerticalSyncEnabled(true);

    // Iniciamos el reloj de sistema
    m_frameTime = m_clock.restart();

    // Creamos obejetos
    m_paciente  = new Paciente("Steven Castillo", "pac-014");
    m_escenario = new Escenario();
    m_hospital  = new Hospital();
    m_bomberos  = m_hospital->GetBomberos();
}

Sistema::~Sistema()
{
    //dtor
}

void Sistema::Run()
{
    while (m_window.isOpen())
    {
        ProcessEvents();
        Update();
        Render();
    }
}

void Sistema::Render()
{
    m_window.clear(sf::Color(239, 253, 232, 255));

    this->DrawEscenario();
    this->DrawPaciente();
    this->DrawHospital();
    this->DrawBomberos();

    m_window.display();
}

void Sistema::Update()
{
    // Frames x segundo
    m_frameTime = m_clock.restart();

    m_paciente->Update();
    m_hospital->Update();
    //m_bomberos->Update();

    if (m_paciente->IsEnPeligro())
    {
        //std::cout << "Enviando mensaje de emergencia a hospital" << std::endl;
        m_hospital->SetEmergencia(m_paciente);
    }
    else
    {
        /// Paciente estable
        //  paramedicos deben volver

    }
}

void Sistema::ProcessEvents()
{
    sf::Event event;

    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                m_window.close();

            case sf::Event::KeyPressed:
                this->InputManager(event.key.code);

        }
    }
}

void Sistema::InputManager(sf::Keyboard::Key key)
{
    switch (key)
    {
        case sf::Keyboard::Up :
            //std::cout << "Aumenta ritmo cardiaco." << std::endl;
            m_paciente->SetRitmoCardiaco(1.3);
            break;
        case sf::Keyboard::Down :
            //std::cout << "Disminuye ritmo cardiaco." << std::endl;
            m_paciente->SetRitmoCardiaco(- 1.3);
            break;
    }
}

void Sistema::DrawPaciente()
{
    m_window.draw(m_paciente->GetSprite());
    m_window.draw(m_paciente->GetTextNombre());
    m_window.draw(m_paciente->GetTextRitmoCardiaco());
    m_window.draw(m_paciente->GetTextPresionArterial());
    m_window.draw(m_paciente->GetTextTemperatura());
    m_window.draw(m_paciente->GetTextEstado());
    m_window.draw(m_paciente->GetTextTiempoInfarto());
}

void Sistema::DrawHospital()
{
    m_window.draw(m_hospital->GetSpriteHospital());
}

void Sistema::DrawBomberos()
{
    m_window.draw(m_bomberos->GetSpriteBomberos());
    m_window.draw(m_bomberos->GetSpriteTelefono());
    m_window.draw(m_bomberos->GetParamedicos()->GetSprite());
}

void Sistema::DrawEscenario()
{
    m_window.draw(m_escenario->GetSpriteAntena());
    m_window.draw(m_escenario->GetSpriteOndas1());
    m_window.draw(m_escenario->GetSpriteOndas2());
}
