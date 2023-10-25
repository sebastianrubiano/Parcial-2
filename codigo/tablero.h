#ifndef TABLERO_H
#define TABLERO_H
#include <iomanip>
#include <iostream>
using namespace std;

class Tablero
{
private:
    int tamano = 8;
    char tablero[24][24];
    void tablero_inicial();

public:
    Tablero(int tan);
    void Mostrar_tablero();
    bool movi_valido(int fila, int columnas, char jugador);
};

#endif // TABLERO_H
