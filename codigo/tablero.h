#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

class Tablero
{
private:
    int tamano;
    char** tablero;
    void tablero_inicial();

public:
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char fichaA, fichaB;
    Tablero(int tam,char A,char B);
    void Mostrar_tablero();
    bool movi_valido(int fila, int columnas, char jugador);
    void hacerMovimiento(int fila, int columna, char jugador);
    bool tieneMovimientosValidos(char jugador);
    int contarFichas(char jugador);
    void Mostrar_tablerocolor();

};

#endif // TABLERO_H
