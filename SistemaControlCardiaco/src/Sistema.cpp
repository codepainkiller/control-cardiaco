#include "Sistema.h"

Sistema::Sistema(): m_window(sf::VideoMode(window_width, window_heigth, 32), "Sistema Control Cardiaco")
{
    // Activa la sincronización vertical (60 fps)
    m_window.setVerticalSyncEnabled(true);

    // Numeros aleatorios (semilla)
    srand(time(0));

    // Escogiendo paciente al azar
    int _index = rand() % (10 + 1);

    m_tPaciente = this->GetRegistro(_index);
    // Creamos obejetos
    m_paciente  = new Paciente(m_tPaciente.nombres + " " + m_tPaciente.apellidos, m_tPaciente.codigoPulsera);
    m_escenario = new Escenario();
    m_hospital  = new Hospital();
    m_bomberos  = m_hospital->GetBomberos();
}

Sistema::~Sistema()
{
    //dtor

}

tPaciente Sistema::GetRegistro(int index)
{
    tPaciente reg_paciente;
    std::string path = "registro_pacientes.txt";
    std::fstream F;

    F.open(path, std::fstream::in);

    int i = 0;

    while (F >> reg_paciente.nombres >> reg_paciente.apellidos >> reg_paciente.codigoPulsera)
    {
        if (i == index)
            break;
        i++;
    }
    F.close();

    return reg_paciente;
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

    // Variacion de parametros de paciente (aleatorio)

    m_frameTime = m_clock.getElapsedTime();

    if (m_frameTime.asSeconds() > 1.5f)
    {
        int _rand1, _rand2, _rand3;

        _rand1 = -2 + rand()% (4 + 2);
        _rand2 = -1 + rand()% (2 + 1);
        _rand3 = -1 + rand()% (2 + 1);

        m_paciente->SetRitmoCardiaco(_rand1);
        m_paciente->SetPresionArterial(_rand2);
        m_paciente->SetTemperatura(_rand3);

        m_frameTime = m_clock.restart();
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
    m_window.draw(m_hospital->GetTextPaciente());
    m_window.draw(m_hospital->GetTextTiempoInfarto());
    m_window.draw(m_hospital->GetTextUbicacion());
    m_window.draw(m_hospital->GetTextCodigoPulsera());
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

    if (m_paciente->IsEnPeligro())
    {
        m_window.draw(m_escenario->GetTextOndas1());
        m_window.draw(m_escenario->GetTextOndas2());
        m_window.draw(m_escenario->GetTextOndas3());
        m_window.draw(m_escenario->GetSpriteOndas3());

    }

    if (m_frameTime.asSeconds() > 0.5f && m_frameTime.asSeconds() < 1.5f)
    {
        m_window.draw(m_escenario->GetSpriteOndas1());
        m_window.draw(m_escenario->GetSpriteOndas2());
    }

}
