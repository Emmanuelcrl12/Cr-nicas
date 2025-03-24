#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <vector>
#include "./Jugador.h"
#include "./Mano.h"





class Tablero{

    public:
        
        vector<Jugador> jugadores;
        vector<Carta> cartasTablero;
        Tablero(Carta& cartaSeleccionada);
        Tablero();
        void jugarRonda();
        void mostrarTablero();


};

Tablero::Tablero(){
    
}

Tablero::Tablero(Carta& cartaSeleccionada){
    cartasTablero.push_back(cartaSeleccionada);
}

void Tablero::mostrarTablero(){
    cout << "-----CARTAS EN JUEGO-------\n ";
    for (int i = 0; i < cartasTablero.size(); i++){
        cartasTablero[i].mostrar();
        cout << "existo ";
        
    }
    cout << "\n";
}

void Tablero::jugarRonda(){

    
}

#endif