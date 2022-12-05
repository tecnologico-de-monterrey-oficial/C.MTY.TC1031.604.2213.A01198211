#ifndef GrafoH_h
#define GrafoH_h
#include "Vertice.h"
#include "hashBoat.h"
#include <stack>
#include <stdexcept>
#include <vector>

class GrafoH {
private:
  HashBoat nodos;
  vector<vector<Vertice<string>>> grafo;
  int size;
  void DFSR(int indice, vector<bool> &status);
  int getSmallIndex(vector<bool> status, vector<int> cost);
  int getBigIndex(vector<bool> status, vector<int> cost);
  int Encontrarnodo(string nodo);

public:
  void print();
  GrafoH();
  GrafoH(HashBoat);
  GrafoH(HashBoat, vector<Vertice<string>>);
  void insertarNodo(string nodo);
  void insertarArista(Vertice<string> arista);
  void DFS(string nodo);
  void Dijkstra(string origen, string destino);
  vector<bool> DijkstraInversa(string origen, string destino);
};

GrafoH::GrafoH() { size = 0; }
GrafoH::GrafoH(HashBoat nodos) {
  this->nodos = nodos;
  size = 15;
  grafo.resize(size);
}

GrafoH::GrafoH(HashBoat nodos, vector<Vertice<string>> Aristas) {
  this->nodos = nodos;
  size = 15;
  grafo.resize(size);
  for (auto arista : Aristas) {
    int indice = Encontrarnodo(arista.dato);
    if (indice != -1) {

      grafo[indice].push_back(arista);
    } else {
      throw invalid_argument("las aristas no concuerdan con los nodos");
    }
  }
}

int GrafoH::Encontrarnodo(string nodo) { return nodos.getBoat(nodo); }

void GrafoH::insertarNodo(string nodo) { nodos.addBoat(nodo); }

void GrafoH::insertarArista(Vertice<string> arista) {
  int indice = Encontrarnodo(arista.dato);
  if (indice == -1) {
    throw out_of_range("no existen los nodos señalados en las aristas");

  } else {
    grafo[indice].push_back(arista);
  }
}

void GrafoH::DFSR(int indice, vector<bool> &status) {
  cout << nodos[indice] << endl;
  status[indice] = true;
  for (auto Arista : grafo[indice]) {
    int indiceDeArista = Encontrarnodo(Arista.dato);
    if (!status[indiceDeArista]) {
      DFSR(indiceDeArista, status);
    }
  }
}

void GrafoH::DFS(string nodo) {
  int indice = Encontrarnodo(nodo);
  if (indice != -1) {
    vector<bool> status;
    status.resize(size, false);
    DFSR(indice, status);
  } else {
    throw out_of_range("no se encontro el nodo agregado");
  }
}

vector<bool> GrafoH::DijkstraInversa(string origen, string destino) {
  int nodoIndex = Encontrarnodo(origen);
  vector<bool> status(size, false); // El vector de estatus
  if (nodoIndex >= 0) {
    vector<int> cost(size, -1); // El vector de costos
    cost[nodoIndex] = 0;
    vector<int> path(size, -1); // El vector de path
    int bigIndex = getBigIndex(status, cost);
    while (bigIndex >= 0) {
      status[bigIndex] = true;
      for (auto adjVertex : grafo[bigIndex]) {
        int adjIndex = Encontrarnodo(adjVertex.relacion);
        if (!status[adjIndex]) {
          if (cost[adjIndex] < cost[bigIndex] + adjVertex.peso) {
            cost[adjIndex] = cost[bigIndex] + adjVertex.peso;
            path[adjIndex] = bigIndex;
          }
        }
      }
      bigIndex = getBigIndex(status, cost);
    }
    vector<stack<int>> pathStack(size);
    for (int index = 0; index < size; index++) {
      if (cost[index] > -1) {
        pathStack[index].push(index);
        int pathIndex = index;
        while (path[pathIndex] != -1) {
          pathStack[index].push(path[pathIndex]);
          pathIndex = path[pathIndex];
        }
      }
    }
    int indexDestino = Encontrarnodo(destino);
    cout << "ruta mas larga: " << endl;
    for (int i = 0; i <= pathStack[indexDestino].size() + 1; i++) {
      cout << nodos[pathStack[indexDestino].top()] << "->";
      pathStack[indexDestino].pop();
    }
    cout << destino << endl;
    cout << "millas nauticas: " << cost[indexDestino] << endl;
  } else {
    cout << "El vértice inicial no existe" << endl;
  }
  return status;
}

void GrafoH::Dijkstra(string origen, string destino) {
  int nodoIndex = Encontrarnodo(origen);
  if (nodoIndex >= 0) {
    vector<bool> status(size, false); // El vector de estatus
    vector<int> cost(size, INT_MAX);  // El vector de costos
    cost[nodoIndex] = 0;
    vector<int> path(size, -1); // El vector de path
    int smallIndex = getSmallIndex(status, cost);
    while (smallIndex >= 0) {
      status[smallIndex] = true;
      for (auto adjVertex : grafo[smallIndex]) {
        int adjIndex = Encontrarnodo(adjVertex.relacion);
        if (!status[adjIndex]) {

          if (cost[adjIndex] > cost[smallIndex] + adjVertex.peso) {
            cost[adjIndex] = cost[smallIndex] + adjVertex.peso;
            path[adjIndex] = smallIndex;
          }
        }
      }
      smallIndex = getSmallIndex(status, cost);
    }
    vector<stack<int>> pathStack(size);
    for (int index = 0; index < size; index++) {
      if (cost[index] < INT_MAX) {
        pathStack[index].push(index);
        int pathIndex = index;
        while (path[pathIndex] != -1) {
          pathStack[index].push(path[pathIndex]);
          pathIndex = path[pathIndex];
        }
      }
    }
    int indexDestino = Encontrarnodo(destino);
    cout << "ruta mas corta:" << endl;
    for (int i = 0; i <= pathStack[indexDestino].size() + 1; i++) {
      cout << nodos[pathStack[indexDestino].top()] << "->";
      pathStack[indexDestino].pop();
    }
    cout << destino << endl;
    cout << "millas nauticas: " << cost[indexDestino] << endl;
  } else {
    // No existe
    // Imprimir un error
    cout << "El vértice inicial no existe" << endl;
  }
}

int GrafoH::getBigIndex(vector<bool> status, vector<int> cost) {
  // Creamos una variable con el valor menor que sea igual a infinito
  // (minCost)
  int maxCost = -1;
  // Creamos una variable para guardar cual fue el índice menor (minIndex) y
  // la igualamos a -1
  int maxIndex = -1;
  // Recorremos todos los valor del vector de status
  for (int i = 0; i < size; i++) {
    // si el valor del indice actual del ciclo en el vector de status es igual
    // a falso
    if (!status[i]) {
      // si es falso
      // validamos si el costo del indice atual es menor a minCost
      if (cost[i] > maxCost) {
        // si es menor
        // cambiamos el valor de minCost por el costo del indice actual
        maxCost = cost[i];
        // cambiamos el valor de minIndex por el índice actual
        maxIndex = i;
      }
    }
  }
  // Regresar el valor de minIndex
  return maxIndex;
}
int GrafoH::getSmallIndex(vector<bool> status, vector<int> cost) {
  int minCost = INT_MAX;
  int minIndex = -1;
  for (int i = 0; i < size; i++) {
    if (!status[i]) {
      if (cost[i] < minCost) {
        minCost = cost[i];
        minIndex = i;
      }
    }
  }
  return minIndex;
}
void GrafoH::print() {
  for (int i = 0; i < 15; i++) {
    std::cout << nodos[i] << "->";
    if (grafo[i].size() != 0) {
      for (int j = 0; j < grafo[i].size(); j++) {
        std::cout << grafo[i][j].relacion << ",";
      }
      std::cout << std::endl;
    }
  }
}

#endif
