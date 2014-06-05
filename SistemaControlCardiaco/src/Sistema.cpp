#include "Sistema.h"

Sistema::Sistema(): m_window(sf::VideoMode(1000, 600, 32), "Sistema Control Cardiaco")
{
    m_window.setVerticalSyncEnabled(true); // Activa la sincronización vertical (60 fps)

    m_window.setFramerateLimit(60);

    // Creamos un objeto paciente
    m_paciente = new Paciente("George Castillo", "pac-001");
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
    m_window.clear(sf::Color::Black);

    this->DrawPaciente();


    m_window.display();

}

void Sistema::DrawPaciente()
{
    m_window.draw(m_paciente->GetSprite());
    m_window.draw(m_paciente->GetTextNombre());
    m_window.draw(m_paciente->GetTextRitmoCardiaco());
}

void Sistema::Update()
{
    m_paciente->Update();
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
            std::cout << "Aumenta ritmo cardiaco." << std::endl;
            m_paciente->SetRitmoCardiaco(0.5);
            break;
        case sf::Keyboard::Down :
            std::cout << "Disminuye ritmo cardiaco." << std::endl;
            m_paciente->SetRitmoCardiaco(- 0.5);
            break;

    }


}









