#ifndef MANO_H
#define MANO_H


#include <iostream>
#include "./Carta.h"
#include "./Mazo.h"

#include <Vector>

using namespace std;
class Mano{
    
    public:
        vector<Carta> cartasM;
        Mano();
        void mostrar();
        Carta lanzar(vector<vector<Mano>>& manos);
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
    
    cout<<"La mano del jugador "<<nJugador+1<<":"<<endl;
    manos[nJugador][0].mostrar();
    cout << endl;
}


Carta Mano::lanzar(vector<vector<Mano>>& manos){
   
    int opcion;
    mostrarMano(manos, 0);
    cout << "\nSeleccione una carta para lanzar: ";
    cin >> opcion;
    Carta cartaSeleccionada = manos[0][0].cartasM[opcion-1];
    cartaSeleccionada.mostrar();


    return cartaSeleccionada;
}

#endif
