#ifndef TABLERO_H
#define TABLERO_H
#include <iomanip>
#include <iostream>
using namespace std;

class Tablero
{
private:
    int tamano;
    char** tablero;
    void tablero_inicial();


public:
    Tablero(int tam);
    void Mostrar_tablero();
    bool movi_valido(int fila, int columnas, char jugador);
    void hacerMovimiento(int fila, int columna, char jugador);
    bool tieneMovimientosValidos(char jugador);
    int contarFichas(char jugador);

};

#endif // TABLERO_H
