#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Paciente.h"
#include "Bomberos.h"

class Hospital
{
    public:
        Hospital();
        ~Hospital();

        sf::Sprite  GetSpriteHospital();
        void        Update();
        void        SetEmergencia(Paciente *paciente);
        Bomberos*   GetBomberos();


    private:
        sf::Texture     m_textureHospital;
        sf::Sprite      m_spriteHospital;
        sf::Vector2f    m_posicionHospital;

        Paciente*       m_pacienteEnPeligro;
        Bomberos*       m_bomberos;

        void            LoadResources();
        void            LlamarBomberos();
};

#endif // HOSPITAL_H
