#ifndef PACIENTE_H
#define PACIENTE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

namespace covert_type
{
    template <typename T>
    std::string to_string(T value)
    {
        std::ostringstream os ;
        os << value ;

        return os.str() ;
    }
}


class Paciente
{
    public:
        Paciente(std::string nombre, std::string codigoPulsera);

        ~Paciente();

        /// Metodos de de estado y ubicacion paciente

        void Update();

        /// Metodos para animacion de paciente (sprite)

        sf::Sprite GetSprite();

        sf::Text GetTextNombre();
        sf::Text GetTextRitmoCardiaco();


        /// Manipulacion de ritmo cardiaco
        void SetRitmoCardiaco(float delta);

    protected:

    private:
        /// Atributos de animacion
        sf::Texture m_texture;
        sf::Sprite  m_sprite;

        /// Bip del corazon
        //sf::SoundBuffer m_soundBuffer;
        //sf::Sound       m_sound;

        /// Atributos de paciente
        std::string m_nombre;
        float       m_ritmoCardiaco;
        float       m_presionArterial;
        float       m_temperatura;
        float       m_tiempoInfarto;  // tiempo para que le de un infarto
        bool        m_estado;         // con vida

        /// Fonts - Text para mostrar por pantalla
        sf::Font    m_font;             // fuente para todos lostextos que se mostraran
        sf::Text    m_textNombre;
        sf::Text    m_textRitmoCardiaco;
        sf::Text    m_textPresionArterial;
        sf::Text    m_textTiempoInfarto;

        /// Atributos del pulsersa
        std::string m_codigoPulsera;
        std::string m_ubicacionActual;
        double      m_latitud;
        double      m_longitud;

        /// Cargar texturas y sonidos
        void LoadResources();

        float GetRitmoCardiaco();
        float GetPresionArterial();
        float GetTemperatura();
        float GetTiempoInfarto();
        float GetLatitud();
        float GetLongitud();
        bool  IsEstado();
        std::string GetCodigoPulsera();
        std::string GetUbicacion();


};

#endif // PACIENTE_H
