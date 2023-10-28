#include "tablero.h"

void Tablero::tablero_inicial()
{
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            tablero[i][j] = ' ';
        }
    }
    tablero[(tamano/2)-1][(tamano/2)-1] = tablero[tamano/2][tamano/2] = '*';//jugador uno blanco
    tablero[(tamano/2)-1][tamano/2] = tablero[tamano/2][(tamano/2)-1] = '-';//jugador dos negro
}

Tablero::Tablero(int tam)
{
     tamano = tam;

    tablero = new char*[tamano];
    for (int i = 0; i < tamano; i++) {
            tablero[i] = new char[tamano];
    }
    tablero_inicial();
}

void Tablero::Mostrar_tablero()
{

    cout << "     ";
    for (int i = 65; i <= 65+tamano-1; i++) {
        char character = static_cast<char>(i);
        cout << character << "   ";
    }
    cout << "\n   ";
    for (int i = 0; i < tamano; i++) {
        cout << "+---";
    }
    cout << "+"<< endl;

    for (int i = 0; i < tamano; i++)
    {
        cout << setw(2) << i + 1 << " | ";
        for (int j = 0; j < tamano; j++)
        {
           cout << tablero[i][j] << " | ";
        }
       cout << " " << setw(2) << i + 1 << endl;
        cout << "   ";
        for (int i = 0; i < tamano; i++) {
           cout << "+---";
        }
        cout << "+"<< endl;

    }
    cout << "     ";
    for (int i = 65; i <= 65+tamano-1; i++) {
       char character = static_cast<char>(i);
       cout << character << "   ";
    }
    cout << endl;

}

bool Tablero::movi_valido(int filas, int columnas, char jugador)
{
   if (filas < 0 || filas >= tamano || columnas < 0 || columnas >= tamano || tablero[filas][columnas] != ' ')
   {
       return false;
   }
    char enemigo = (jugador == '*') ? '-' : '*'; //  'X') ? '0' : 'X';
    int df[ ] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dc[ ] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (int direccion = 0; direccion < 8; direccion++)
    {
           int fila = filas + df[direccion];
           int columna = columnas + dc[direccion];
           bool direccionValida = false;
           while (fila >= 0 && fila < tamano && columna >= 0 && columna < tamano && tablero[fila][columna] == enemigo)
           {
               fila += df[direccion];
               columna += dc[direccion];
               direccionValida = true;
           }
           if (direccionValida && fila>= 0 && fila < tamano && columna >= 0 && columna < tamano && tablero[fila][columna] == jugador)
           {
               return true;
           }
    }
    return false;
}

void Tablero::hacerMovimiento(int J_fila, int J_columna, char jugador) {
    char oponente = (jugador == '*') ? '-' : '*'; //  'X') ? '0' : 'X';
    tablero[J_fila][J_columna] = jugador;

    int df[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (int direccion = 0; direccion < 8; direccion++)
    {
           int fila = J_fila + df[direccion];
           int columna = J_columna + dc[direccion];
           bool direccionValida = false;

           while (fila >= 0 && fila < tamano && columna >= 0 && columna < tamano && tablero[fila][columna] == oponente)
           {
               fila += df[direccion];
               columna += dc[direccion];
               direccionValida = true;
           }

           if (direccionValida && fila >= 0 && fila < tamano && columna >= 0 && columna < tamano && tablero[fila][columna] == jugador)
           {
               fila = J_fila + df[direccion];
               columna = J_columna + dc[direccion];

               while (fila >= 0 && fila < tamano && columna >= 0 && columna < tamano && tablero[fila][columna] == oponente)
               {
                   tablero[fila][columna] = jugador;
                   fila += df[direccion];
                   columna += dc[direccion];
               }
           }
    }
}

bool Tablero::tieneMovimientosValidos(char jugador)
{
    for (int i = 0; i < tamano; i++) {
           for (int j = 0; j < tamano; j++) {
               if (movi_valido(i, j, jugador)) {
                   return true;
               }
           }
    }
    return false;
}

int Tablero::contarFichas(char jugador)
{
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
           for (int j = 0; j < tamano; j++)
           {
               if (tablero[i][j] == jugador)
               {
                   contador++;
               }
           }
    }
    return contador;
}
