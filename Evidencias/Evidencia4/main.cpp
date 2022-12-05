#include "Grafo_h.h"
#include "Vertice.h"
#include "hashBoat.h"
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int main() {
  // lectura del archivo y creacion del grafo
  string filename;
  cout << "inserte el nombre del archivo" << endl;
  cin >> filename;
  cout << endl << endl;
  ifstream file;
  file.open(filename);
  string puerto1;
  string puerto2;
  int distancia;
  int size;
  vector<Vertice<string>> aristas;
  file >> size;
  for (int i = 1; i <= size; i++) {
    file >> puerto1 >> puerto2 >> distancia;
    Vertice<string> arista(puerto1, puerto2, distancia);
    aristas.push_back(arista);
  }
  file >> size;
  HashBoat puertos;
  for (int i = 1; i <= size; i++) {
    file >> puerto1;
    puertos.addBoat(puerto1);
  }
  GrafoH grafo(puertos, aristas);

  // Peticion del puerto
  string puerto;
  string destino;
  while (true) {
    cout << "que puerto quiere revisar? " << endl;
    cin >> puerto >> destino;
    cout << endl << endl;

    grafo.Dijkstra(puerto, destino);
    cout << endl << endl;
    vector<bool> status = grafo.DijkstraInversa(
        puerto,
        destino); // aparte de mostrar los datos, recive el status para
                  // saber cuales puertos se pudieron navegar y cuales no
    cout << endl << endl;
    cout << "puertos que no se pudieron navegar: " << endl;
    for (int i = 0; i < status.size(); i++) {
      if (status[i] == 0) {
        cout << "- " << puertos[i] << endl;
      }
    }
    char opcion;
    cout << "Desea buscar otra ruta (y/n)";
    cin >> opcion;
    if (opcion == 'n') {
      cout << "Muchas gracias por participar!!";
      break;
    } else if (opcion == 'y') {
      cout << endl << endl;
    } else {
      throw invalid_argument("no se escribio 'n' o 'y' ");
    }
  }

  return 0;
}
