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
        cout << "Jugador  " << nombre << "  ( " <<  ficha << " ) , ingresa tu movimiento (columna y fila) ejemplo c3: ";
        cin >> columna >> fila;
        fila--;
        columna = toupper(columna)-'A';
        if (TAB->movi_valido(fila, columna, ficha)) {
            TAB->hacerMovimiento(fila,columna,ficha);
            break;
        } else {
            cout << "Movimiento invalido. Intentalo de nuevo." << endl;
        }
    }
}
/*
void Jugador::agregar_jugador(string NOMBRE, string HORA, string FECHA, int PUNTOS, bool GANADOR)
{
    nombre = NOMBRE;
    fecha = FECHA;
    hora = HORA;
    puntos = PUNTOS;
    ganador = GANADOR;
}*/


