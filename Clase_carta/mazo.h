#include <iostream>
#include "./carta.h"
#include <cstdlib> 
#include <ctime>  
 
 using namespace std;

class mazo{
    
    
    public :
    
    
    int ncartas;
    carta cartas[36];
    mazo();
    void barajar();
    void mostrar();
    carta repartir();
     
    
    
    
    
};


mazo:: mazo(){
    
    int indice=0;
    for(int i=0;  i <4; i++){
        for(int j=0; j<9; j++){
            
            indice= (9*i)+j;
            cartas[indice].numero= j+1;
            cartas[indice].color=i;
            
            
            
        }
    }
    
}
void mazo::  mostrar(){
    
    
    int indice =0;
        for(int i=0; i<4;  i++ ){
            
            
            cout<<" "<<endl;
            for(int j=0; j<9; j++){
                
            cartas[indice].mostrar();
            cout<<" ";
           
            indice ++;
            }}
}


void mazo:: barajar(){
       
       cout<<endl<<"Se barajaron las cartas";
       
       carta aux;
       
       
       
          for (int i = 0; i < 50; i++) {
            int a = rand() % 36; 
            int b = rand() % 36; 
          
            carta aux = cartas[a];
            cartas[a] = cartas[b];
            cartas[b] = aux;
        }
