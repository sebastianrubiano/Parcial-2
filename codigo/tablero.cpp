#include "tablero.h"

void Tablero::tablero_inicial()
{
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            tablero[i][j] = ' ';
        }
    }
    tablero[(tamano/2)-1][(tamano/2)-1] = tablero[tamano/2][tamano/2] = 'x';//jugador uno blanco
    tablero[(tamano/2)-1][tamano/2] = tablero[tamano/2][(tamano/2)-1] = '0';//jugador dos negro
}


 Tablero::Tablero(int tam)
{
    tamano = tam;
    tablero_inicial();
}

void Tablero::Mostrar_tablero()
{
    cout << "     ";
    for (int i = 65; i <= 65+tamano-1; i++) {
        char character = static_cast<char>(i);
        cout << character << "   ";
    }
    cout << "\n   ";
    for (int i = 0; i < tamano; i++) {
        cout << "+---";
    }
    cout << "+"<< endl;

    for (int i = 0; i < tamano; i++)
    {
        cout << setw(2) << i + 1 << " | ";
        for (int j = 0; j < tamano; j++)
        {
           cout << tablero[i][j] << " | ";
        }
       cout << " " << setw(2) << i + 1 << endl;
        cout << "   ";
        for (int i = 0; i < tamano; i++) {
           cout << "+---";
        }
        cout << "+"<< endl;

    }
    cout << "     ";
    for (int i = 65; i <= 65+tamano-1; i++) {
       char character = static_cast<char>(i);
       cout << character << "   ";
    }
    cout << endl;

}

bool Tablero::movi_valido(int fila, int columnas, char jugador)
{
   if (fila < 0 || fila >= tamano || columnas < 0 || columnas >= tamano || tablero[fila][columnas] != ' ')
   {
       return false;
   }

}

