#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <vector>
#include "./Jugador.h"





class Tablero{

    public:
        
        vector<Jugador> jugadores;
        vector<Carta> cartasTablero;
        Tablero();
        void jugarRonda();
        void mostrarTablero();


};


Tablero::Tablero(){
    
}

void Tablero::mostrarTablero(){
    cout << "-----CARTAS EN JUEGO-------\n ";
    for (int i = 0; i < cartasTablero.size(); i++){
        cartasTablero[i].mostrar();
        cout << " ";
    }
    cout << "\n";
}

void Tablero::jugarRonda(){

    
}

#endif