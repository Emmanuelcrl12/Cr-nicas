#ifndef MANO_H
#define MANO_H


#include <iostream>
#include "./Carta.h"
#include "./Mazo.h"
#include <Vector>

using namespace std;
class Mano{
    
    public:
        int jugadores;
        int cartasJugador;
        vector<Carta> cartasM;
        Mano();
        void mostrar();
        Carta lanzar();

};

Mano::Mano(){

    Mazo mazo1;
    cartasJugador = 36/jugadores;//define cuantas cartas se reparten a cada jugador
    
}

void Mano::mostrar(){
    
    for(int i=0; i<cartasM.size(); i++){
        cartasM[i].mostrar();
        cout<<" "<<i;
    }
}

Carta Mano::lanzar(){
    Mano mano;
    mano.mostrar();
    
    int carta;
    cout<<"Ingrese la carta que desea lanzar: ";
    cin>>carta;
    
    return cartasM[carta];
}

#endif