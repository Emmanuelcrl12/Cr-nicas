
#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <vector>
#include <fstream>
#include "./Mano.h"

class Mano;
using namespace std;

class Tablero {
public:
    vector<Carta> cartasTablero;
    int ronda;
    vector<int> puntos;

    Tablero();
    void agregarCarta(Carta c);
    void jugarRonda(vector<Mano>& manos, Tablero& tablero, int jugadores, int turno);
    void mostrar();
    int compararGanador();
    void asignarPuntos(int jugadorGanador);
    void guardarEstado(vector<Mano>& manos, int turno, const string& filename);
    void cargarEstado(vector<Mano>& manos, int& turno, const string& filename);
};

Tablero::Tablero() {
    ronda = 1;
}

void Tablero::agregarCarta(Carta c) {
    cartasTablero.push_back(c);
}

void Tablero::mostrar() {
    for (Carta& c : cartasTablero) {
        c.mostrar();
        cout << " ";
    }
}

void Tablero::jugarRonda(vector<Mano>& manos, Tablero& tablero, int jugadores, int turno) {
    int i = turno;
    system("cls");
    cout << "Turno del jugador: " << i + 1 << endl;
    system("pause");
    if (manos[i].cartasM.empty()) return;
    cout << "----CARTAS EN JUEGO----\n";
    tablero.mostrar();
    cout << "\nJugador " << i + 1 << " lanza carta:\n";
    Carta cartaJugada = manos[i].lanzar(manos, i);
    tablero.agregarCarta(cartaJugada);
}

int Tablero::compararGanador() {
    if (cartasTablero.empty()) return -1;
    int colorBase = cartasTablero[0].color;
    Carta cartaGanadora = cartasTablero[0];
    int indiceGanador = 0;

    for (int i = 1; i < cartasTablero.size(); i++) {
        if (cartasTablero[i].color == colorBase && cartasTablero[i].numero > cartaGanadora.numero) {
            cartaGanadora = cartasTablero[i];
            indiceGanador = i;
        }
    }

    cout << "El jugador " << indiceGanador + 1 << " gana la ronda.\n";
    return indiceGanador;
}

void Tablero::asignarPuntos(int jugadorGanador) {
    int puntosGanados = cartasTablero.size();
    puntos[jugadorGanador] += puntosGanados;
    cout << "El jugador " << jugadorGanador + 1 << " recibe " << puntosGanados << " puntos.\n";
    cartasTablero.clear();
    ronda++;
}

void Tablero::guardarEstado(vector<Mano>& manos, int turno, const string& filename) {
    ofstream out(filename);
    out << turno << endl;
    out << ronda << endl;

    out << "PUNTOS ";
    for (int p : puntos) out << p << ";";
    out << endl;

    for (auto& mano : manos) {
        out << "MANO ";
        for (Carta& c : mano.cartasM) {
            out << c.color << "-" << c.numero << ";";
        }
        out << endl;
    }

    out << "TABLERO ";
    for (Carta& c : cartasTablero) {
        out << c.color << "-" << c.numero << ";";
    }
    out << endl;
    out.close();
}

void Tablero::cargarEstado(vector<Mano>& manos, int& turno, const string& filename) {
    ifstream in(filename);
    string linea;
    getline(in, linea);
    turno = stoi(linea);
    getline(in, linea);
    ronda = stoi(linea);

    puntos.clear();
    getline(in, linea); // PUNTOS
    size_t pos = linea.find(" ");
    string puntoStr = linea.substr(pos + 1);
    size_t start = 0, end;
    while ((end = puntoStr.find(";", start)) != string::npos) {
        puntos.push_back(stoi(puntoStr.substr(start, end - start)));
        start = end + 1;
    }

    for (auto& mano : manos) {
        mano.cartasM.clear();
        getline(in, linea);
        pos = linea.find(" ");
        string cartas = linea.substr(pos + 1);
        start = 0;
        while ((end = cartas.find(";", start)) != string::npos) {
            string c = cartas.substr(start, end - start);
            size_t mid = c.find("-");
            int color = stoi(c.substr(0, mid));
            int numero = stoi(c.substr(mid + 1));
            mano.agregarCarta(Carta(color, numero));
            start = end + 1;
        }
    }

    cartasTablero.clear();
    getline(in, linea);
    pos = linea.find(" ");
    string cartas = linea.substr(pos + 1);
    start = 0;
    while ((end = cartas.find(";", start)) != string::npos) {
        string c = cartas.substr(start, end - start);
        size_t mid = c.find("-");
        int color = stoi(c.substr(0, mid));
        int numero = stoi(c.substr(mid + 1));
        cartasTablero.push_back(Carta(color, numero));
        start = end + 1;
    }
    //in.close();
}

#endif
