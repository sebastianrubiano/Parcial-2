#ifndef JUGADOR_H
#define JUGADOR_H
#include "tablero.h"
#include <windows.h>
class Tablero;
class Jugador
{
public:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string nombre;
    char ficha;
    int puntos = 2;
    bool ganador = true;


    Jugador(char fichas,string non_Ju);
    void movimiento(Tablero* tablero);

    ~Jugador();
};

#endif // JUGADOR_H
