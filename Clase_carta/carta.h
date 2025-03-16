
#include <iostream>
#include "./colores.h"
#include <string>

using namespace std;


class carta{
    
    
    public : 
    
    string paleta[4]= {BG_RED, BG_GREEN, BG_BLUE, BG_YELLOW};
    int numero;
    int color;
    carta();
      carta(int color, int numero);
    void mostrar();
};

carta :: carta(){
    
    numero=0;
    color=0;
    
    
}

carta :: carta (int color, int numero){
    this->color=color;
    this->numero= numero;
}


void carta::   mostrar(){
    cout << paleta[color] << " " << numero << " \x1B[0m"; 
}
