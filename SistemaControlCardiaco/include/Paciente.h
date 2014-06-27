#ifndef PACIENTE_H
#define PACIENTE_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>

#define FRECC_MAX 90    // Frecuencia cardiaca maxima  - Latidos  x minuto
#define FRECC_MIN 60    // Frecuencia cardiaca minima  - Latidos  x minuto
#define PRESA_MAX 37    // Presion arterial maxima     - Grados Celsius
#define TEMPC_MAX 120   // Temperatura corporal maxima - mm Hg
#define TIEMPO_INF 300.0  // Tiempo para un infarto en segundos

namespace convert_type
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

        float       GetRitmoCardiaco();
        float       GetPresionArterial();
        float       GetTemperatura();
        float       GetTiempoInfarto();
        std::string GetLatitud();
        std::string GetLongitud();
        std::string GetCodigoPulsera();
        std::string GetUbicacion();
        std::string GetNombre();
        bool        IsEnPeligro();
        bool        IsEstaVivo();

        /// Metodos para animacion de paciente (sprite)
        sf::Sprite  GetSprite();
        sf::Text    GetTextNombre();
        sf::Text    GetTextRitmoCardiaco();
        sf::Text    GetTextPresionArterial();
        sf::Text    GetTextTemperatura();
        sf::Text    GetTextEstado();
        sf::Text    GetTextTiempoInfarto();

        /// Manipulacion de ritmo cardiaco
        void SetRitmoCardiaco(float delta);
        void SetPresionArterial(float delta);
        void SetTemperatura(float delta);

    private:

        /// Bip del corazon
        sf::SoundBuffer m_bufferLatido;
        sf::SoundBuffer m_bufferAlerta;
        sf::SoundBuffer m_bufferCorazonDetenido;
        sf::Sound       m_soundLatido;
        sf::Sound       m_soundAlerta;
        sf::Sound       m_soundCorazonDetenido;

        sf::Clock   m_clock;
        sf::Clock   m_clockInfarto;
        sf::Time    m_frecuencia;    // Ritmo cardiaco
        sf::Time    m_cuentaRegresiva;   // Tiempo que le quedara para el infarto

        /// Atributos de animacion
        sf::Texture m_texture;
        sf::Sprite  m_sprite;

        /// Fonts - Text para mostrar por pantalla
        sf::Font    m_font;             // fuente para todos los textos que se mostraran
        sf::Text    m_textNombre;
        sf::Text    m_textRitmoCardiaco;
        sf::Text    m_textPresionArterial;
        sf::Text    m_textTemperatura;
        sf::Text    m_textEstado;
        sf::Text    m_textTiempoInfarto;

        /// Atributos de paciente
        std::string m_nombre;
        float       m_ritmoCardiaco;
        float       m_presionArterial;
        float       m_temperatura;
        float       m_tiempoInfarto;  // tiempo para que le de un infarto
        bool        m_estaVivo;
        bool        m_enPeligro;
        std::string m_codigoPulsera;
        std::string m_ubicacionActual;
        std::string m_latitud;
        std::string m_longitud;

        void  LoadResources();

};

#endif // PACIENTE_H
