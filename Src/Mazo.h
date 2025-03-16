#include <iostream>
#include "./Carta.h"
#include <cstdlib> 
#include <ctime>  
 
 using namespace std;

 class Mazo{

 public:
     int ncartas;
     Carta cartas[36];
     Mazo();
     void barajar();
     void mostrar();
     Carta repartir();
 };

Mazo::Mazo(){
    
    int indice=0;
    for(int i=0;  i <4; i++){
        for(int j=0; j<9; j++){
            
            indice= (9*i)+j;
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
       
    cout<<endl<<"Se barajaron las cartas";
       
    Carta aux;
       
    for (int i = 0; i < 50; i++) {
        int a = rand() % 36; 
        int b = rand() % 36; 
          
        Carta aux = cartas[a];
        cartas[a] = cartas[b];
        cartas[b] = aux;
    }
}

Carta Mazo::repartir(){
    
    Carta carta = cartas[ncartas];
    ncartas++;
    return carta;
}