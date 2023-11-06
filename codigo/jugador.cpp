#include "jugador.h"

Jugador::Jugador(char fichas,string non_Ju) {
    ficha = fichas;
    nombre = non_Ju;
}

Jugador::~Jugador()
{

}

void Jugador::movimiento(Tablero* TAB)
{
    char columna;
    int fila;
    while (true) {
        if (ficha ==TAB->fichaA)
        {
        cout << "Jugador@  ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout<< nombre;
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "  ( ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout <<  ficha;
        }
        else
        {
        cout << "Jugador@  ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
        cout<< nombre;
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "  ( ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
        cout <<  ficha;
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << " ) , ingresa tu movimiento (";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout<< "columna";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout <<" y ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        cout << "fila";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout <<") ejemplo ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout << "C";
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        cout << '3';
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout <<": ";
        cin >> columna >> fila;
        fila--;
        columna = toupper(columna) - 'A';
        if (TAB->movi_valido(fila, columna, ficha)) {
            TAB->hacerMovimiento(fila,columna,ficha);
            break;
        } else {
            cout << "Movimiento invalido. Intentalo de nuevo." << endl;
        }
    }
}


