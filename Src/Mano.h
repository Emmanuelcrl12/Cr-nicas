#include <iostream>
#include "./Carta.h"
#include "./Mazo.h"
#include <Vector>

using namespace std;
class Mano{
    
    public:
        int Jugadores;
        int cartasJugador;
        vector<Carta> cartasM;
        Mano();
        void mostrar();
        Carta lanzar();

};

Mano::Mano(){

    Mazo mazo1;
    cartasJugador = Jugadores / 36;//define cuantas cartas se reparten a cada jugador
    for(int i=0; i<cartasJugador; i++){
        cartasM.push_back(mazo1.repartir());
    }
 
}

void Mano::mostrar(){
    
    for(int i=0; i<cartasM.size(); i++){
        cartasM[i].mostrar();
        cout<<" ";
    }
}

Carta Mano::lanzar(){
    
    int carta;
    cout<<"Ingrese la carta que desea lanzar: ";
    cin>>carta;
    
    return cartasM[carta];
}

