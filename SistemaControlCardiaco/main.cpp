#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sistema.h"



int main()
{

    Sistema str;

    str.Run();
    /*
// Crear ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Prueba Box2D");

// Bucle del juego
    while (window.isOpen())
    {
// Bucle de Eventos de ventana
        sf::Event event;
        while (window.pollEvent(event))
        {
// Cerrar la ventana cuando se pulsa en el boton de cerrar ventana
            if (event.type == sf::Event::Closed)
                window.close();
        }

// Limpiar ventana con el color negro
        window.clear(sf::Color::Black);

// Dibujamos un rectangulo que actuara de suelo mas adelante
        sf::RectangleShape rectSuelo(sf::Vector2f(800, 100));
        rectSuelo.setPosition(sf::Vector2f(0, 500));
        rectSuelo.setFillColor(sf::Color::Red);
        window.draw(rectSuelo); //Dibujamos el elemento en el buffer

// Mostrar el buffer en pantalla
        window.display();
    }
*/
    return 0;
}
