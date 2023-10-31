#include <iostream>

#include "administracion.h"

using namespace std;

int main(){
    string archivo;
    archivo = "registros";
    administracion* admin = new administracion(archivo);
    int opciones = 0;
    while(opciones != 3)
    {
        cout << "** BIENBENIDOS A JUGAR ***\n " << endl;
        cout << "1. Jugar Othello" << endl;
        cout << "2. Ver tabla de partidas" << endl;
        cout << "3. salir" << endl;
        cout << endl;
        cout << "Ingrese una opcion del menu: ";
        cin >> opciones;
        switch (opciones)
        {
            case 1:
            {
                while(opciones != 3)
                {
                    cout << "1. Jugar " << endl;
                    cout << "2. Mostrar intruncion" << endl;
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
                        admin->intrucciones();
                        break;
                        }
                        case 3:
                        {
                            cout <<"saliendo del juego";
                        }
                    }
                }
            }
            case 2:
            {
                admin->leer_archivo();
                break;
            }

        }
    }
    return 0;
}
