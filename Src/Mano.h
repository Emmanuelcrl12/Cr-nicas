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
}

void Mano::agregarCarta(Carta c){
        cartasM.push_back(c);
}

void Mano::mostrar(){
    
    for(int i=0; i<cartasM.size(); i++){
        cartasM[i].mostrar();
        cout<<" ";
    }
}

void  Mano ::mostrarManos(vector<vector<Mano>>& manos) {
    for(int i=0; i<manos.size(); i++){
        cout << "Cartas del Jugador " << i + 1 << ":" << endl;  
        manos[i][0].mostrar();
        cout << endl;
    }
}

void Mano:: mostrarMano(vector<vector<Mano>>& manos){
int n=1;
    cout<<"La mano del jugador "<<n<<":"<<endl;
    manos[n-1][0].mostrar();
    cout << endl;
}

Carta Mano::lanzar(){
Carta Mano::lanzar(vector<vector<Mano>>& manos){
   
   Carta cartaSeleccionada = manos[0][0].cartasM[6];
cartaSeleccionada.mostrar();
manos

return cartaSeleccionada;
}

#endif
