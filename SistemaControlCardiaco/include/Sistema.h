#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Paciente.h"

class Sistema
{
    public:
        Sistema();
        ~Sistema();

        void Run();

    private:

        sf::RenderWindow    m_window;
        sf::Clock           m_clock;
        sf::Time            m_frameTime;
        Paciente*           m_paciente;

        void Render();
        void Update();
        void ProcessEvents();
        void InputManager(sf::Keyboard::Key);
        void DrawPaciente();
};

#endif // SISTEMA_H
