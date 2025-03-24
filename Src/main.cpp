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
    

    mano.mostrarManos(manos);
    tablero.mostrarTablero();
    
    for (int i = 0; i < jugadores; i++){
        mano.lanzar(manos, i);
    }
    //mano.lanzar(manos);
    tablero.mostrarTablero();

    return 0;
}
