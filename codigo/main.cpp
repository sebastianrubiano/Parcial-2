#include <iostream>
#include "administracion.h"

using namespace std;

int main() {
    string archivo = "../registros";
    administracion* admin = new administracion(archivo);
    int opciones = 0;
    while (opciones != 3) {
        cout << "** BIENVENIDOS A JUGAR ***\n " << endl;
        cout << "1. Jugar Othello" << endl;
        cout << "2. Ver tabla de partidas" << endl;
        cout << "3. Salir" << endl;
        cout << endl;
        cout << "Ingrese una opcion del menu: ";
        cin >> opciones;
        switch (opciones)
        {
            case 1:
            {
                int opcionJuego = 0;
                while (opcionJuego != 3)
                {
                    cout << endl;
                    cout << "1. Jugar " << endl;
                    cout << "2. Mostrar instrucciones" << endl;
                    cout << "3. Salir" << endl;
                    cout << endl;
                    cout << "Ingrese una opcion del menu: ";
                    cin >> opcionJuego;
                    switch (opcionJuego)
                    {
                        case 1:
                        {
                            admin->juego();
                            break;
                        }
                        case 2:
                        {
                            admin->intrucciones();
                            break;
                        }
                        case 3:
                        {
                            cout << "Saliendo del juego" << endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                admin->leer_archivo();
                break;
            }
            case 3:
            {
                cout << "Saliendo del programa." << endl;
                break;
            }
            default:
            {
                cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                    break;
            }
        }
    }
    delete admin;
    return 0;
}
