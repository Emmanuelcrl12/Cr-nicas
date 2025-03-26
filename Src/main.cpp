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
    
    

    vector<Mano> manos = mazo1.repartir(jugadores);

    
    tablero.jugarRonda(manos, tablero, jugadores);

    int ganador = tablero.compararGanador();
    tablero.mandarGanador(manos, ganador);

    

    return 0;
}
