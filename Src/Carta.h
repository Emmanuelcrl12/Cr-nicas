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
        bool estado;
        Carta();
        Carta(int color, int numero, bool estado);
        void mostrar();
};

Carta::Carta(){

    estado=true;
    color = 0;
    numero = 0;
    
}

Carta::Carta (int color, int numero, bool estado){
    this->color = color;
    this->numero = numero;
    this->estado=estado;
}

void Carta::mostrar(){
    if(estado){
      cout << "[X]";  // Mostramos la carta bocabajo
    }else{
    cout << paleta[color] << " " << numero << " "<< " \x1B[0m ";     
    }
}

#endif
