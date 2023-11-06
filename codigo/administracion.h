#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H
#include <fstream>
#include <string>
#include <windows.h>
#include "jugador.h"
#include "tablero.h"
using namespace std;
class Jugador;
class administracion
{
   string nombre_ar;
public:
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    administracion(string archivo);
    void leer_archivo();
    void guardar_archivo(Jugador* jugador, Jugador* oponente);
    void juego();
    void intrucciones();
};

#endif // ADMINISTRACION_H
