#include <iostream>

#include "administracion.h"

using namespace std;

int main(){
    string archivo;
    cout << "nombre del archivo: ";
    cin >> archivo;
    archivo = "registros";
    administracion* admin = new administracion(archivo);
    int opciones = 0;
    while(opciones != 10)
    {
        cout << "1. Jugar" << endl;
        cout << "2. Ver base de jugadores" << endl;
        cout << "3. salir" << endl;
        cout << endl;
        cout << "Ingrese una opcion del menu: ";
        cin >> opciones;
        switch (opciones)
        {
            case 1:
            {
                admin->juego();
                break;
            }
            case 2:
            {
                admin->leer_archivo();
                break;
            }
            case 3:
            {
                break;
            }
        }
    }
    return 0;
}
