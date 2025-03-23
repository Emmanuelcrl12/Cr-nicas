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
        void agregarCarta(Carta c);
        void mostrarManos(vector<Mano>& manos);
        

};

Mano::Mano(){

   void Mano:: agregarCarta(Carta c){
    
    
    cartasM.push_back(c);
}
    
}
void  Mano ::mostrarManos(vector<Mano>& manos) {
    for (int i = 0; i < manos.size(); i++) {  
        cout << "Cartas del Jugador " << i + 1 << ":" << endl;  
        manos[i].mostrar();
        cout << endl;
    }
}

void Mano::mostrar(){
    
    for(int i=0; i<cartasM.size(); i++){
        cartasM[i].mostrar();
        cout<<" "<<endl;
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
