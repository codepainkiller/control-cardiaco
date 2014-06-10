#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Paciente.h"
#include "Escenario.h"
#include "Bomberos.h"


const int window_width = 1100;
const int window_heigth = 600;

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
        Escenario*          m_escenario;

        void Render();
        void Update();
        void ProcessEvents();
        void InputManager(sf::Keyboard::Key);
        void DrawPaciente();
        void DrawHospital();
        void DrawBomberos();
        void DrawEscenario();
};

#endif // SISTEMA_H
