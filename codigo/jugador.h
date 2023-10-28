#ifndef JUGADOR_H
#define JUGADOR_H
#include "tablero.h"
class Tablero;
class Jugador
{
public:
    string nombre;
    char ficha;
    int puntos = 2;
    bool ganador = true;


    Jugador(char fichas,string non_Ju);
    void movimiento(Tablero* tablero);

    ~Jugador();
};

#endif // JUGADOR_H
