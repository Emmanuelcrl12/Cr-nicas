#include <iostream>
#include <winsock2.h>
#include <fstream>
#include <string>
#include "./Mazo.h"
#include "./Tablero.h"
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, SOMAXCONN);
    cout << "Esperando conexión del cliente...\n";

    SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
    cout << "Cliente conectado.\n";

    Mazo mazo;
    vector<Mano> manos;
    Tablero tablero;
    int turno = 0;

    ifstream test("estado.txt");
    if (test.good() && test.peek() != EOF) {
        cout << "Se encontró una partida guardada. ¿Deseas continuarla? (s/n): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta == 's' || respuesta == 'S') {
            manos = vector<Mano>(2);
            tablero.cargarEstado(manos, turno, "estado.txt");
        } else {
            mazo.barajar();
            manos = mazo.repartir(2);
            tablero.puntos = vector<int>(2, 0);
        }
    } else {
        mazo.barajar();
        manos = mazo.repartir(2);
        tablero.puntos = vector<int>(2, 0);
    }

    while (true) {
        tablero.jugarRonda(manos, tablero, 2, turno);

        if (turno == 1) {
            int ganador = tablero.compararGanador();
            tablero.asignarPuntos(ganador);

            cout << "\n--- Puntajes ---\n";
            for (int i = 0; i < tablero.puntos.size(); ++i) {
                cout << "Jugador " << i + 1 << ": " << tablero.puntos[i] << " puntos\n";
            }

            
            

            tablero.guardarEstado(manos, (turno + 1) % 2, "estado.txt");

            
        }

        tablero.guardarEstado(manos, (turno + 1) % 2, "estado.txt");

        ifstream file("estado.txt", ios::binary);
        file.seekg(0, ios::end);
        int fileSize = file.tellg();
        file.seekg(0, ios::beg);
        send(clientSocket, (char*)&fileSize, sizeof(fileSize), 0);

        char buffer[1024];
        while (!file.eof()) {
            file.read(buffer, sizeof(buffer));
            int bytes = file.gcount();
            send(clientSocket, buffer, bytes, 0);
        }
        file.close();

        cout << "Esperando turno del cliente...\n";
        recv(clientSocket, (char*)&fileSize, sizeof(fileSize), 0);
        if (fileSize <= 0) {
            cout << "El cliente cerró la conexión o se canceló.\n";
            break;
        }

        ofstream outFile("estado.txt", ios::binary);
        int received = 0;
        while (received < fileSize) {
            int bytes = recv(clientSocket, buffer, sizeof(buffer), 0);
            outFile.write(buffer, bytes);
            received += bytes;
        }
        outFile.close();

        tablero.cargarEstado(manos, turno, "estado.txt");
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
