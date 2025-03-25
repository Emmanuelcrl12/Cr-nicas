#include <iostream>
#include "./Mazo.h"
#include "./Mano.h"
#include "./Tablero.h"

using namespace std;
int main(){
    
    srand(time(0));
    Mazo mazo1;
    mazo1.mostrar();

    mazo1.barajar();
    cout<<" "<<endl;
    mazo1.mostrar();

    Mano mano;
    Tablero tablero;
    
    int jugadores;
    cout << "\nIngrese el n�mero de jugadores: ";
    cin >> jugadores;
    
    

    vector<vector<Mano>> manos = mazo1.repartir(jugadores);
   Tablero tablero;

for (int i = 0; i < jugadores; i++) {
    cout << "Turno del jugador " << i + 1 << ":\n";
    
    // El jugador selecciona y lanza una carta
    Carta cartaJugada = manos[i].lanzar(manos, i);

    // Agregar la carta al tablero manualmente
    tablero.agregarCarta(cartaJugada);
}

cout << "\nEstado actual del tablero:\n";
tablero.mostrar();
cout << endl;

int ganador = tablero.compararGanador();
tablero.mandarGanador(manos, ganador);

    return 0;
}
