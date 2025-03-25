#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <vector>
#include "./Jugador.h"
#include "./Mano.h"

class Mano;
using namespace std;

class Tablero {

public:
	vector<Jugador> jugadores;
	vector<Carta> cartasTablero;
	Tablero();
	void agregarCarta(Carta c);
	void jugarRonda();
	void mostrarTablero(vector<Tablero>& cartaSeleccionada);
	void mostrar();
	int compararGanador();
	void mandarGanador(vector<Mano>& manos, int jugadorGanador);


};

Tablero::Tablero() {

}
void Tablero::agregarCarta( Carta c) {
	cartasTablero.push_back(c);
}
void Tablero::mostrar() {

	for(int i=0; i<cartasTablero.size(); i++) {
		cout<<i+1<<")";
		cartasTablero[i].mostrar();
		cout<<" ";
	}
}



void Tablero ::mostrarTablero(vector<Tablero>& cartaSeleccionada) {
	cout << "-----CARTAS EN JUEGO-------\n ";
	for (int i = 0; i < cartasTablero.size(); i++) {
		cartaSeleccionada[i].mostrar();
		cout << "existo ";

	}
	cout << "\n";
}




void Tablero::jugarRonda() {


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
void Tablero::mandarGanador(vector<Mano>& manos, int jugadorGanador) {
	cout << "El jugador " << jugadorGanador + 1 << " recibe las cartas.\n";

	for (int i = 0; i < cartasTablero.size(); i++) {
		manos[jugadorGanador].agregarCarta(cartasTablero[i]);
	}

	cartasTablero.clear();  // Vaciar el tablero
}




#endif
