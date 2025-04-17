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
    cout << "Recuerde ingresar un valor par o 3, o 9\n ";
    cin >> jugadores;
    bool gano=true;
    

    vector<Mano> manos = mazo1.repartir(jugadores);
    while(gano){
    tablero.jugarRonda(manos, tablero, jugadores);
    int ganador = tablero.compararGanador();
    tablero.vaciar(ganador,manos);
         int jugadoresConCartas = 0;
         int ultimoJugadorConCartas = -1; 
            for (int i = 0; i < jugadores; i++) {
                if (manos[i].cartasM.size() > 0) {
                  jugadoresConCartas++;
                  ultimoJugadorConCartas = i; 
                  jugadoresConCartas++;
                }
             }
            if (jugadoresConCartas == 1) {
              cout << "¡El jugador " << ultimoJugadorConCartas + 1 << " ha ganado el juego!" << endl;
              gano=false;
              break;
            }

       }      
    return 0;
}
