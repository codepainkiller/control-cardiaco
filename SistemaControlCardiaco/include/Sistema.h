#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Sistema
{
    public:
        Sistema();
        ~Sistema();

        void Run();

    protected:

    private:

        sf::RenderWindow m_window;

        void Render();
        void Update();
        void ProcessEvents();
};

#endif // SISTEMA_H
