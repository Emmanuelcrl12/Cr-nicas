#include <iostream>
#include "./Mazo.h"
#include "./Mano.h"
#include "./Tablero.h"
#include "./Guardado.h"  

using namespace std;

int main(){
    int jugadores;
    vector<Mano> manos;
    Tablero tablero;
    int turno = 0;
    bool gano = true;

    cout << "¿Desea cargar una partida guardada? (s/n): ";
    char opcion;
    cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
    Cargar(manos, turno, tablero, jugadores);  
} else {
    srand(time(0));
    Mazo mazo1;
    mazo1.barajar();


    cout << "\nIngrese el número de jugadores: ";
    cout << "Recuerde ingresar un valor par o 3, o 9\n ";
    cin >> jugadores;

    manos = mazo1.repartir(jugadores);
}


    while (gano) {

    
        cout << "\n¿Desea guardar la partida antes de esta ronda? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            Guardar(manos,turno,tablero);
            jugadores = manos.size(); 
            return 0; 
        }
        cout << "Se cargaron " << manos.size() << " jugadores." << endl;
        turno++;
        tablero.jugarRonda(manos, tablero, jugadores);

        int ganador = tablero.compararGanador();
        tablero.vaciar(ganador, manos);

        int jugadoresConCartas = 0;
        int ultimoJugadorConCartas = -1; 
        for (int i = 0; i < jugadores; i++) {
            if (manos[i].cartasM.size() > 0) {
                jugadoresConCartas++;
                ultimoJugadorConCartas = i; 
            }
        }

        if (jugadoresConCartas == 1) {
            cout << "¡El jugador " << ultimoJugadorConCartas + 1 << " ha ganado el juego!" << endl;
            gano = false;
            break;
        }
    }

    return 0;
}
