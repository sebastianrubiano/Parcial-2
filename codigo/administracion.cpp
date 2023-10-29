#include "administracion.h"

administracion::administracion(string archivo)
{
    nombre_ar = archivo+".txt";

}

void administracion::guardar_archivo(Jugador* jugador, Jugador* oponente)
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    char timestamp[80];
    strftime(timestamp, sizeof(timestamp), "%Y/%m/%d %H:%M:%S", now);
    ofstream registro(nombre_ar, ios::app);

    if (!registro.is_open()) {
       cerr << "Error al abrir el archivo de registro." << endl;
       return;
    }
    registro << timestamp << " " <<  jugador->nombre  << " " <<   jugador->puntos  << " " <<  oponente->nombre  << " " <<   oponente->puntos <<  " ";
    if(jugador->ganador == true && oponente->ganador == true)
    {
       registro << "ENPATE" << endl;;
    }
    else if(jugador->ganador == true)
    {
       registro << jugador->nombre << endl;;
    }
    else{
       registro  << oponente->nombre << endl;;
    }
    registro.close();
}

void administracion::juego() {
    string J1, J2;
    int tam = 4;/*
    cout<< "tamano del tablero: ";
    cin >> tam;
    if (tam < 4 || mod(tamano) !=0) {
        cout << "El tamano del tablero debe ser al menos 4. Saliendo del programa." << endl;
        return ;*/

    cout << "nombre del jugador1: ";
    cin >> J1;

    cout << "nombre del jugador2: ";
    cin >> J2;

    Tablero* TAB = new Tablero(tam);
    Jugador* jugador1 = new Jugador('*', J1);
    Jugador* oponente = new Jugador('-', J2);

    Jugador* jugadorActual = jugador1;

    while (true)
    {
       if (!TAB->tieneMovimientosValidos(jugadorActual->ficha))
       {
           cout << "El jugador " << jugadorActual->nombre << " no tiene movimientos validos." << endl;

           if (jugadorActual == jugador1)
           {
               jugador1->ganador = false;
           }
           else
           {
               oponente->ganador = false;
           }
       }
       else
       {
            cout << endl; //system("cls");
           cout << "El jugador " << jugador1->nombre << " (*) , puntos: " << jugador1->puntos << endl;
           cout << "El jugador " << oponente->nombre << " (-) , puntos: " << oponente->puntos << endl;
           TAB->Mostrar_tablero();
           jugador1->ganador = true;
           oponente->ganador = true;
           jugadorActual->movimiento(TAB);
       }
       jugador1->puntos = TAB->contarFichas(jugador1->ficha);
       oponente->puntos = TAB->contarFichas(oponente->ficha);

       bool gana = (jugador1->ganador == false && oponente->ganador == false);

       if (jugador1->puntos + oponente->puntos == tam * tam || gana == true)
       {
           cout << endl;//system("cls");

           cout << "El jugador " << jugador1->nombre << " (*) tiene " << jugador1->puntos << " puntos." << endl;
           cout << "El jugador " << oponente->nombre << " (-) tiene " << oponente->puntos << " puntos." << endl;
           TAB->Mostrar_tablero();

           if (jugador1->puntos > oponente->puntos)
           {
               cout << "El jugador " << jugador1->nombre << " (*) gana." << endl;
               jugador1->ganador = true;
               oponente->ganador = false;
           }
           else if (oponente->puntos > jugador1->puntos)
           {
               cout << "El jugador " << oponente->nombre << " (-) gana." << endl;
               jugador1->ganador = false;
               oponente->ganador = true;
           }
           else
           {
               cout << "Es un empate." << endl;
               jugador1->ganador = true;
               oponente->ganador = true;
           }
           break;
       }

       jugadorActual = (jugadorActual == jugador1) ? oponente : jugador1;
    }
    guardar_archivo(jugador1, oponente);
    delete jugador1;
    delete oponente;
    delete jugadorActual;
    return;

}

void administracion::leer_archivo()
{
    ifstream archivo(nombre_ar);
    if (!archivo.is_open())
    {
       cerr << "No se pudo abrir el archivo." << endl;
       return;
    }

    string jugador, oponente, ganador, fecha, hora;
    int ju_puntos, op_puntos;
    const int tan_col = 15;
    cout << left << setw(tan_col) << "Fecha" << setw(tan_col) << "Hora"
         << setw(tan_col) << "Jugador" << setw(tan_col) << "Puntos "
         << setw(tan_col) << "Oponente" << setw(tan_col) << "Puntos "
         << setw(tan_col) << "Ganador" << endl;

    while (archivo >> fecha >> hora >> jugador >> ju_puntos >> oponente >> op_puntos >> ganador)
    {
       cout << left << setw(tan_col) << fecha << setw(tan_col) << hora
            << setw(tan_col) << jugador << setw(tan_col) << ju_puntos
            << setw(tan_col) << oponente << setw(tan_col) << op_puntos
            << setw(tan_col) << ganador << endl;
    }
    archivo.close();
}
