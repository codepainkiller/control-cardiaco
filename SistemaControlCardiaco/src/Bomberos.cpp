#include "Bomberos.h"

Bomberos::Bomberos()
{
    m_paramedicos = new CarroParamedicos();

    this->LoadResources();
}

Bomberos::~Bomberos()
{
    //dtor
}

sf::Sprite Bomberos::GetSprite()
{

}

void Bomberos::LoadResources()
{

}
