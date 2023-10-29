#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H
#include <fstream>
#include <string>
#include "jugador.h"
#include "tablero.h"
using namespace std;
class Jugador;
class administracion
{
   string nombre_ar;
public:
    administracion(string archivo);
    void leer_archivo();
    void guardar_archivo(Jugador* jugador, Jugador* oponente);
    void juego();
};

#endif // ADMINISTRACION_H
