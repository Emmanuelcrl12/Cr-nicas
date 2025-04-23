#include <iostream>
#include <winsock2.h>
#include <fstream>
#include "./Mazo.h"
#include "./Tablero.h"
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Cambia esto por la IP del servidor

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "No se pudo conectar al servidor.\n";
        return 1;
    }
    cout << "Conectado al servidor.\n";

    Tablero tablero;
    vector<Mano> manos(2);
    int turno;
    char buffer[1024];

    while (true) {
        int fileSize;
        recv(clientSocket, (char*)&fileSize, sizeof(fileSize), 0);

        if (fileSize == -1) {
            cout << "El servidor finalizó la partida.\n";
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

        if (turno == 1) {
            tablero.jugarRonda(manos, tablero, 2, turno);

            int ganador = tablero.compararGanador();
            tablero.asignarPuntos(ganador);

            cout << "\n--- Puntajes ---\n";
            for (int i = 0; i < tablero.puntos.size(); ++i) {
                cout << "Jugador " << i + 1 << ": " << tablero.puntos[i] << " puntos\n";
            }

            tablero.guardarEstado(manos, (turno + 1) % 2, "estado.txt");
        }

        ifstream file("estado.txt", ios::binary);
        file.seekg(0, ios::end);
        fileSize = file.tellg();
        file.seekg(0, ios::beg);
        send(clientSocket, (char*)&fileSize, sizeof(fileSize), 0);

        while (!file.eof()) {
            file.read(buffer, sizeof(buffer));
            int bytes = file.gcount();
            send(clientSocket, buffer, bytes, 0);
        }
        file.close();
    }

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
