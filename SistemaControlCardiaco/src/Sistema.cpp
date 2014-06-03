#include "Sistema.h"

Sistema::Sistema(): m_window(sf::VideoMode(800, 600), "Sistema Control Cardiaco")
{
    m_window.setVerticalSyncEnabled(true);
    m_window.setFramerateLimit(60);
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

    m_window.display();

}

void Sistema::Update()
{

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
        }
    }

}
