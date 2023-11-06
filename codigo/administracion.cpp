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
    char  fichaA, fichaB;
    int tam = 8;
/*
    cout<< "tamano del tablero: ";
    cin >> tam;

    if (tam < 4 && tam > 26 && tam%2 !=0)
    {
        cout << "El tamano del tablero debe ser al menos 4. Saliendo del programa." << endl;
        return ;
    }
    cout << "ficha del jugador_!: ";
    cin >> fichaA;

    cout << "ficha del jugador_2: ";
    cin >> fichaB;
*/
    fichaA= '*';//BLANO *
    fichaB= '-'; // NEGRO -

    cout << "nombre del Jugador@ de las fichas blancas: ";
    cin >> J1;


    cout << "nombre del Jugador@ de las fichas negras: ";
    cin >> J2;

    Tablero* TAB = new Tablero(tam, fichaA, fichaB);
    Jugador* jugador1 = new Jugador(fichaA, J1);
    Jugador* oponente = new Jugador(fichaB, J2);

    Jugador* jugadorActual = oponente;

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
           cout << "Jugador@ ";
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << jugador1->nombre;
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << " (";
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << jugador1->ficha;
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << ") , puntos: ";
           cout << jugador1->puntos << endl;
           cout << "Jugador@ ";
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
           cout << oponente->nombre;
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << " (";
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
           cout << oponente->ficha;
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << ") , puntos: ";
           cout << oponente->puntos << endl << endl;
           TAB->Mostrar_tablerocolor();
           cout  << endl;
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

           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << jugador1->nombre;
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << " (";
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << jugador1->ficha;
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << ") , puntos: ";
           cout << jugador1->puntos << endl;
           cout << "Jugador@ ";
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
           cout << oponente->nombre;
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << " (";
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
           cout << oponente->ficha;
           SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
           cout << ") , puntos: ";
           cout << oponente->puntos << endl << endl;
           TAB->Mostrar_tablerocolor();
           cout  << endl;
           if (jugador1->puntos > oponente->puntos)
           {
               cout << "Jugador@ ";
               SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
               cout << jugador1->nombre;
               SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
               cout << " (";
               SetConsoleTextAttribute(hConsole,  FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
               cout << oponente->ficha;
               SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
               cout <<  ") gana." << endl;
               jugador1->ganador = true;
               oponente->ganador = false;
           }
           else if (oponente->puntos > jugador1->puntos)
           {
               cout << "El jugador ";
               SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
               cout << oponente->nombre;
               SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
               cout << " (";
               SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
               cout << oponente->ficha;
               SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
               cout << ") gana." << endl;
               jugador1->ganador = false;
               oponente->ganador = true;
           }
           else
           {
               SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
               cout << "Es un empate." << endl;
               SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
               jugador1->ganador = true;
               oponente->ganador = true;
           }
           break;
       }

       jugadorActual = (jugadorActual == jugador1) ? oponente : jugador1;
    }
    guardar_archivo(jugador1, oponente);
}

void administracion::intrucciones()
{
    cout << "Instrucciones para jugar Othello:\n" << endl;
    cout << "1. El juego comienza con cuatro fichas en el centro del tablero: dos blancas y dos negras." << endl;
    cout << "2. Los jugadores se turnan para colocar sus fichas en el tablero." << endl;
    cout << "3. Debes colocar una ficha en una casilla vacía de modo que encierres" << endl;
    cout << " una o más fichas del oponente entre tu nueva ficha y tus fichas ya colocadas." << endl;
    cout << "Las fichas atrapadas entre las fichas del jugador y las fichas del oponente se voltearán y cambiarán de color." << endl;
    cout << "5. El objetivo es tener más fichas de tu color que el oponente al final del juego." << endl;
    cout << "6. El juego termina cuando no se pueden hacer más movimientos válidos." << endl;
    cout << "7. Gana el jugador con más fichas de su color en el tablero." << endl;
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
         << setw(tan_col) << "Jugador@" << setw(tan_col) << "Puntos "
         << setw(tan_col) << "Oponente" << setw(tan_col) << "Puntos "
         << setw(tan_col) << "Ganador" << endl;

    while (archivo >> fecha >> hora >> jugador >> ju_puntos >> oponente >> op_puntos >> ganador)
    {
       cout << left << setw(tan_col) << fecha << setw(tan_col) << hora
            << setw(tan_col) << jugador << setw(tan_col) << ju_puntos
            << setw(tan_col) << oponente << setw(tan_col) << op_puntos
            << setw(tan_col) << ganador <<  endl;
    }
    cout  <<  endl;
    archivo.close();
}
