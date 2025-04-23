#include <iostream>
#include "./Mazo.h"
#include "./Mano.h"
#include "./Tablero.h"

using namespace std;
int main(){
    
    srand(time(0));
    Mazo mazo1;
    mazo1.mostrar();
    system("cls");

    
    mazo1.barajar();
    cout<<" "<<endl;
    //mazo1.mostrar();
    system("pause");
    Mano mano;
    Tablero tablero;

    
    int jugadores;
    cout << "\nIngrese el n�mero de jugadores: ";
    cout << "Recuerde ingresar un valor par o 3, o 9\n ";
    cin >> jugadores;
    
    

    vector<Mano> manos = mazo1.repartir(jugadores);
    while(true){
    
        tablero.jugarRonda(manos, tablero, jugadores);

        int ganador = tablero.compararGanador();
        tablero.mandarGanador(manos, ganador);

        for (int i = 0; i < jugadores; i++) {
            if (manos[i].cartasM.size() == 36) { 
                system("cls");
                cout << "¡El jugador " << i + 1 << " ha ganado el juego con todas las cartas!" << endl;
                system("pause");
                return 0;
            }
        }


    }
    return 0;
}
