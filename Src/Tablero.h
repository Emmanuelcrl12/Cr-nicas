#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <vector>
#include "./Jugador.h"
#include "./Mano.h"
#include <cstdlib>
#include<string>

class Mano;
using namespace std;

class Tablero {

public:
	vector<Jugador> jugadores;
	vector<Carta> cartasTablero;
	Tablero();
	void agregarCarta(Carta c);
	void jugarRonda(vector <Mano>& manos, Tablero& tablero, int jugadores);
	void mostrar();
	int compararGanador();
	void vaciar(int &indiceGanador,vector <Mano>& manos);


};

Tablero::Tablero() {

}
void Tablero::agregarCarta( Carta c) {
	cartasTablero.push_back(c);
}
void Tablero::mostrar() {
	for(int i=0; i<cartasTablero.size(); i++) {
		cartasTablero[i].mostrar();
		cout<<" ";
	}
}



void Tablero::jugarRonda(vector <Mano>& manos, Tablero& tablero, int jugadores) {
	
	for (int i = 0; i < jugadores; i++) {
	    if (manos[i].cartasM.empty()) continue; // Si el jugador no tiene cartas, se salta su turno
		
		if (i>0 ){
		   cout << "----CARTAS EN JUEGO----\n";
		   tablero.mostrar();
		}
	        cout<<"Puntaje:"<<manos[i].puntaje;
		cout << "\nTurno del jugador " << i + 1 << ":\n";
		Carta cartaJugada = manos[i].lanzar(manos, i);
		tablero.agregarCarta(cartaJugada);
		system("clear");
		}

}

int  Tablero::compararGanador() {

	int colorBase= cartasTablero[0].color;
	Carta cartaGanadora = cartasTablero[0];
	int indiceGanador = 0;

	for(int i=1; i<cartasTablero.size(); i++ )
	{
		if(cartasTablero[i].color==colorBase) {
			if(cartasTablero[i].numero>cartaGanadora.numero) {
				cartaGanadora=cartasTablero[i];
				indiceGanador=i;
			}
		}

	}
	cout << "El jugador " << indiceGanador + 1 << " ganC3 la ronda.\n";
	return indiceGanador;
}
void Tablero::vaciar(int &indiceGanador,vector <Mano>& manos ) {
       
	manos[indiceGanador].puntaje += cartasTablero.size();
	cartasTablero.clear();  
}

#endif
