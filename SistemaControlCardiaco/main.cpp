#include "Sistema.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>

using namespace std;

void RegistrarPacientes()
{
    string path = "registro_pacientes.txt";
    fstream F;
    string nombres;
    string apellidos;
    string codigoPulsera;
    char opcion;

    F.open(path, fstream::out | fstream::app);

    cout << endl << "REGISTRO DE PACIENTES" << endl << endl;

    if (F.is_open())
    {
        cout << " Registrar paciente? (s/n): "; cin >> opcion;
        cin.ignore();

        while (opcion != 'n')
        {
            cout << " Nombres: "; getline(cin, nombres);
            cout << " Apellidos: "; getline(cin, apellidos);
            cout << " Codigo pulsera: "; getline(cin, codigoPulsera);

            F << nombres << ' ';
            F << apellidos << ' ';
            F << codigoPulsera << endl;

            cout << " Agregar mas registros? (s/n): "; cin >> opcion;
        }

        F.close();
    }
    else
    {
        cout << "Error en abrir archivo" << endl;
    }

}

void Instrucciones()
{
    cout << endl;
    cout << "Instrucciones\n\n";
    cout << "Aumentar  ritmo cardiaco: Fecha hacia ARRIBA.\n";
    cout << "Disminuir ritmo cardiaco: Fecha hacia ABAJO.\n";
}

int main()
{
    //Instrucciones();
    RegistrarPacientes();
    Sistema str;
    str.Run();

    return 0;
}
