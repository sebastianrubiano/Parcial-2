#include <iostream>
using namespace std;
#include "jugador.h"
#include "tablero.h"



int main()
{
    int tam = 8;
    //cout<< "tamano del tablero: ";
   // cin >> tam;

   Tablero* TAB= new Tablero(tam);
    TAB->Mostrar_tablero();
    return 0;
}
