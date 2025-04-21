#ifndef GUARDADO_H
#define GUARDADO_H
#include <fstream>
#include <vector>
#include "Mano.h"
#include "Tablero.h"


using namespace std;

void Guardar(vector<Mano> &Manos, int Turno, Tablero &tablero){
     ofstream archivo("Juego.txt");

     archivo << Turno << endl;
     archivo << Manos.size() << endl; 
     //Guardamos la mano
    for(auto &mano: Manos){
        archivo<<mano.cartasM.size()<< " ";
        for(auto &carta:mano.cartasM){
            archivo<<carta.numero<<"  "<<carta.color<<""<<endl;
        }
        archivo<<mano.puntaje<<endl;
    }
    archivo<<tablero.cartasTablero.size()<<" ";
    for(auto &cartaTablero : tablero.cartasTablero){
            archivo<<cartaTablero.numero<<"  "<<cartaTablero.color<<""<<endl;
        }
    archivo.close();
    cout << "Juego guardado correctamente." << endl;
}

void Cargar (vector<Mano>& manos, int& Turno, Tablero& tablero, int& jugadores) {
    ifstream archivo("Juego.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de guardado.\n";
        return;
    }

    archivo >> Turno;
    archivo >> jugadores;  
    manos.resize(jugadores);

    for (int j = 0; j < jugadores; j++) {
        int cantidadCartas;
        archivo >> cantidadCartas;
        manos[j].cartasM.clear();

        for (int i = 0; i < cantidadCartas; i++) {
            int numero, color;
            archivo >> numero >> color;
            manos[j].cartasM.push_back(Carta(numero, color));
        }
        archivo >> manos[j].puntaje;
    }

    int cantidadEnTablero;
    archivo >> cantidadEnTablero;
    tablero.cartasTablero.clear();
    for (int i = 0; i < cantidadEnTablero; i++) {
        int numero, color;
        archivo >> numero >> color;
        tablero.cartasTablero.push_back(Carta(numero, color));
    }
    for (int i = 0; i < jugadores; i++) {
    cout << "Jugador " << i + 1 << " tiene " << manos[i].cartasM.size() << " cartas y " << manos[i].puntaje << " puntos.\n";
}

    archivo.close();
    cout << "Juego cargado correctamente." << endl;
}





#endif
