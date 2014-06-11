#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sistema.h"

using namespace std;

void Instrucciones()
{
    cout << endl;
    cout << "Instrucciones\n\n";
    cout << "Aumentar  ritmo cardiaco: Fecha hacia ARRIBA.\n";
    cout << "Disminuir ritmo cardiaco: Fecha hacia ABAJO.\n";
}

int main()
{
    Instrucciones();

    Sistema str;
    str.Run();

    return 0;
}
