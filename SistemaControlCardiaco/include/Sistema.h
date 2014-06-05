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

    protected:

    private:

        sf::RenderWindow m_window;
        Paciente*        m_paciente;


        void Render();
        void Update();
        void ProcessEvents();
        void InputManager(sf::Keyboard::Key);
        void DrawPaciente();
};

#endif // SISTEMA_H
