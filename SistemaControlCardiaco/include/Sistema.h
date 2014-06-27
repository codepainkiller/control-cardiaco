#ifndef SISTEMA_H
#define SISTEMA_H

#include "Paciente.h"
#include "Escenario.h"
#include "Bomberos.h"
#include "Hospital.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

const int window_width = 1100;
const int window_heigth = 600;

struct tPaciente
{
    std::string nombres;
    std::string apellidos;
    std::string codigoPulsera;
};

class Sistema
{
    public:

        Sistema();
        ~Sistema();

        void Run();
        tPaciente GetRegistro(int index);

    private:

        sf::RenderWindow    m_window;
        sf::Clock           m_clock;
        sf::Time            m_frameTime;

        // Objetos que intercatuan en el sistema
        Paciente*           m_paciente;
        Escenario*          m_escenario;
        Hospital*           m_hospital;
        Bomberos*           m_bomberos;

        tPaciente           m_tPaciente;

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
