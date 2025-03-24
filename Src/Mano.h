#ifndef MANO_H
#define MANO_H


#include <iostream>
#include "./Carta.h"
#include "./Mazo.h"
#include "./Tablero.h"
#include <Vector>

using namespace std;
class Mano{
    
    public:
        vector<Carta> cartasM;
        Mano();
        void mostrar();
        Carta lanzar(vector<vector<Mano>>& manos, int nJugador);
        void agregarCarta(Carta c);
        void mostrarManos(vector<vector<Mano>>& manos);
        void mostrarMano(vector<vector<Mano>>& manos, int nJugador);
        
};



Mano::Mano(){  
}

void Mano::agregarCarta(Carta c){
        cartasM.push_back(c);
}


void Mano::mostrar(){
    
    for(int i=0; i<cartasM.size(); i++){
        cout<<i+1<<")";
        cartasM[i].mostrar();
        cout<<" ";
    }
}

void  Mano::mostrarManos(vector<vector<Mano>>& manos) {
    for(int i=0; i<manos.size(); i++){
        cout << "\nCartas del Jugador " << i + 1 << ":" << endl;  
        manos[i][0].mostrar();
        cout << endl;
    }
}

void Mano::mostrarMano(vector<vector<Mano>>& manos, int nJugador){
    
    cout<<"\nLa mano del jugador "<<nJugador+1<<":"<<endl;
    manos[nJugador][0].mostrar();
    cout << endl;
}



Carta Mano::lanzar(vector<vector<Mano>>& manos, int nJugador){
   
    int opcion;
    mostrarMano(manos, nJugador);
    cout << "\nSeleccione una carta para lanzar: ";
    cin >> opcion;
    Carta cartaSeleccionada = manos[nJugador][0].cartasM[opcion-1];
    cout<< "la carta tirada es: \n";
    cartaSeleccionada.mostrar();
    cout << endl;

    return cartaSeleccionada;
}



#endif
