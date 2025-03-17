#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include "./colores.h"
#include <string>

using namespace std;

class Carta{
    
    public : 
        string paleta[4]= {BG_RED, BG_GREEN, BG_BLUE, BG_YELLOW};
        int numero;//poder de la carta
        int color;
        Carta();
        Carta(int color, int numero);
        void mostrar();
};

Carta::Carta(){
    
    color = 0;
    numero = 0;
    
}

Carta::Carta (int color, int numero){
    this->color = color;
    this->numero = numero;
}


void Carta::mostrar(){
    cout << paleta[color] << " " << numero << " "<< RESET; 
}

#endif