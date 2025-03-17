#ifndef MAZO_H

#define MAZO_H

#include <iostream>
#include "./Carta.h"
#include <cstdlib> 
#include <ctime>  


using namespace std;

class Mazo{

    public:
        //int ncartas;
        Carta cartas[36];
        Mazo();
        void barajar();
        void mostrar();
        Carta repartir();
     
 };

Mazo::Mazo(){
    
    int indice = 0;
    for(int i = 0;  i <4; i++){
        
        for(int j = 0; j<9; j++){
            
            indice = (9*i)+j;
            cartas[indice].numero = j+1;
            cartas[indice].color = i;
        }
    }
    
}
void Mazo::mostrar(){
    
    int indice = 0;
    for(int i=0; i<4;  i++ ){
        cout<<" "<<endl;    
        for(int j=0; j<9; j++){
                
            cartas[indice].mostrar();
            cout<<" ";
           
            indice ++;
       }
    }
}


void Mazo::barajar(){
       
    cout<<"\nSe barajaron las cartas"<<endl;   
    Carta aux;
       
    for (int i = 0; i < 50; i++) {
        int a = rand() % 36; 
        int b = rand() % 36; 
          
        Carta aux = cartas[a];
        cartas[a] = cartas[b];
        cartas[b] = aux;
    }
}

#include "./Mano.h" 

Carta Mazo::repartir() {
    Mano mano;

    int jugadores;
    cout<<"\nIngrese el numero de jugadores: ";
    cin>>jugadores;

    int cartasJugador;
    cartasJugador = 36/jugadores;

    for(int i = 0; i < jugadores; i++){
        cout<<"Jugador "<<i+1<<endl;
        for(int j = 0; j < cartasJugador; j++){
            mano.cartasM.push_back(cartas[j]);
            cartas[j].mostrar();
            cout<<" ";
        }
        cout<<" "<<endl;
    }
    return mano.cartasM[0];
}

#endif