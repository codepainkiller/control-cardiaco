#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Paciente.h"
#include "Bomberos.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <sstream>

class Hospital
{
    public:
        Hospital();
        ~Hospital();

        sf::Sprite  GetSpriteHospital();
        void        Update();
        void        SetEmergencia(Paciente *paciente);
        Bomberos*   GetBomberos();

        sf::Text    GetTextUbicacion();
        sf::Text    GetTextTiempoInfarto();
        sf::Text    GetTextPaciente();
        sf::Text    GetTextCodigoPulsera();
        bool        IsEmergencia();


    private:
        sf::Texture     m_textureHospital;
        sf::Sprite      m_spriteHospital;
        sf::Vector2f    m_posicionHospital;

        sf::Font        m_font;
        sf::Text        m_textCodigoPulsera;
        sf::Text        m_textPaciente;
        sf::Text        m_textUbicacion;
        sf::Text        m_textTiempoInfarto;

        Paciente*       m_pacienteEnPeligro;
        Bomberos*       m_bomberos;

        bool            m_emergencia;

        void            LoadResources();
        void            LlamarBomberos();
};

#endif // HOSPITAL_H
