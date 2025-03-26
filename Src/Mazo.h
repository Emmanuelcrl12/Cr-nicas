#ifndef MAZO_H

#define MAZO_H

#include <iostream>
#include "./Carta.h"
#include "./Mano.h" 
#include <vector>
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
        vector<Mano> repartir(int jugadores);

     
     
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


vector<Mano> Mazo::repartir(int jugadores){
    
    int ncartas_jugador=36/jugadores;
    vector<vector<Mano>> manos(jugadores, vector<Mano>(1));
    int indice = 35;
        for (int j = 0; j<jugadores ; j++) {
            for (int i =0; i<ncartas_jugador; i++) {
                
                manos[j][0].agregarCarta(cartas[indice]);
                indice--;
            }
        }
        return manos;
    
    
}







#endif
