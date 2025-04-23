#ifndef MANO_H
#define MANO_H


#include <iostream>
#include "./Carta.h"
#include "./Mazo.h"

#include <vector>


using namespace std;
class Mano{
    
    public:
        vector<Carta> cartasM;
        Mano();
        void mostrar();
        void agregarCarta(Carta c);
        Carta lanzar(vector<Mano>& manos, int nJugador);
        void mostrarMano(vector<Mano>& manos, int nJugador);
        
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

void Mano::mostrarMano(vector<Mano>& manos, int nJugador){
    
    manos[nJugador].mostrar();
    cout << endl;
}

Carta Mano::lanzar(vector<Mano>& manos, int nJugador) {
    
    int opcion;
    mostrarMano(manos,nJugador);
    cout << "\nSeleccione una carta para lanzar: ";
    cin >> opcion;

    // Guardar la carta seleccionada
    Carta cartaLanzada = cartasM[opcion - 1];

    cout << endl;

    // Eliminar la carta de la mano
    cartasM.erase(cartasM.begin() + (opcion - 1));

    return cartaLanzada;  // Retornar la carta seleccionada
}



#endif
