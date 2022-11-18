#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "Vertex.h"
#include <iostream>
#include <stdexcept>
#include <vector>

template <class T> class Graph {
private:
  std::vector<std::vector<Vertex<T>>>
      graph; // el grafo en si, es una hash table que guarda las conecciones que
             // tiene en el indice del elemento definido
  std::vector<T> vertices; // los elementos del grafo
  int size;                // el tamaño del grafo
  void DFSR(int vertexIndex, std::vector<bool> &status);
  int findVertex(T vertex); // te da la posicion de un elemento en vertices
  int getSmallIndex(std::vector<bool> status, std::vector<int> cost);

public:
  Graph();                        // constructor vacio
  Graph(std::vector<T> vertices); // vector de vertices
  Graph(std::vector<T> vertices,
        std::vector<Vertex<T>> edges); // vector de vertices y edges (edges son
                                       // las conecciones entre los grafos)
  void addEdges(std::vector<Vertex<T>>); // agrega nuevas relaciones
  void addEdge(Vertex<T>);               // agrega una nueva relacion
  void DFS(T vertex);                    // busqueda mediante depth first
  void print();

  void Dijkstra(T vertex);
};

template <class T> void Graph<T>::addEdge(Vertex<T> edge) {
  int sourceIndex = findVertex(edge.source);
  if (sourceIndex != -1) {
    graph[sourceIndex].push_back(edge);
  }
}

template <class T> void Graph<T>::addEdges(std::vector<Vertex<T>> edges) {
  for (int i = 0; i < edges.size(); i++) {
    int sourceIndex = findVertex(edges[i].source);
    if (sourceIndex != -1) {
      graph[sourceIndex].push_back(edges[i]);
    }
  }
}

template <class T> Graph<T>::Graph() { size = 0; }
template <class T> Graph<T>::Graph(std::vector<T> vertices) {
  this->vertices = vertices;
  size = vertices.size();
  graph.resize(size);
}
template <class T> int Graph<T>::findVertex(T Vertex) {
  typename std::vector<int>::iterator it =
      find(vertices.begin(), vertices.end(), Vertex);
  if (it != vertices.end()) {

    return it - vertices.begin();
  } else {
    return -1;
  }
}

template <class T>
Graph<T>::Graph(std::vector<T> vertices, std::vector<Vertex<T>> edges) {
  // agrega el vector de vertices
  this->vertices = vertices;
  // declara size
  size = vertices.size();
  // declara el tamaño de graph
  graph.resize(size);
  // se asegura que cada elemento en edges se encuentre en el vector de vertices
  for (auto edge : edges) {
    int sourceIndex = findVertex(edge.source);
    // si no se encuentra, lanza un error
    if (sourceIndex == -1) {
      throw std::out_of_range("el vertice no se encuenta en el grafo");
      return;
    }
    // si si se encuentra, lo agrega a graph
    graph[sourceIndex].push_back(edge);
  }
}

template <class T> void Graph<T>::print() {
  for (int i = 0; i < vertices.size(); i++) {
    std::cout << vertices[i] << "->";
    if (graph[i].size() != 0) {
      for (int j = 0; j < graph[i].size(); j++) {
        std::cout << graph[i][j].target << ",";
      }
      std::cout << std::endl;
    }
  }
}
template <class T> void Graph<T>::DFSR(int index, std::vector<bool> &status) {
  std::cout << vertices[index];
  status[index] = true;
  for (auto Adj : graph[index]) {
    int indexOfAdj = findVertex(Adj.target);
    if (!status[indexOfAdj]) {
      DFSR(indexOfAdj, status);
    }
  }
}

template <class T> void Graph<T>::DFS(T vertex) {
  int index = findVertex(vertex);
  std::vector<bool> status;
  if (index <= -1) {
    throw std::out_of_range("ese elemento no existe en el grafo");
  } else {
    for (int i = 0; i <= vertices.size(); i++) {
      status.push_back(false);
    }
    DFSR(index, status);
  }
}

template <class T> void Graph<T>::Dijkstra(T vertex) {
  // Obtener el índice del vértice que recibimos de parámetro
  int vertexIndex = findVertex(vertex);
  // Validar que si exista el vértice en la tabla de vértices
  if (vertexIndex >= 0) {
    // Si existe
    // Inicializamos las tablas de trabajo
    // Creamos una vector del tamaño de size y la inicializamos en falso
    // (status)
    std::vector<bool> status(size, false); // El vector de estatus
    // Creamos una vector del tamaño de size y la inicializamos con infinito
    // (cost)
    std::vector<int> cost(size, INT_MAX); // El vector de costos
                                          // Al valor del índice que corresponde
                                          // al vértice inicial le asignamos 0
    cost[vertexIndex] = 0;
    // Creamos una vector del tanaño de size y la inicializamos en -1
    std::vector<int> path(size, -1); // El vector de path
    // Creamos un varibale smallIndex y le asignamos el valor de la funcion
    // getSmallIndex
    int smallIndex = getSmallIndex(status, cost);
    // Ciclo mientras smallIndex >= 0
    while (smallIndex >= 0) {
      // Actualizar el estado en el vector de status del smallIndex
      status[smallIndex] = true;
      // Recorremos todos los índice adyacentes del vertice con smallIndex
      for (auto adjVertex : graph[smallIndex]) {
        // Buscamos el índice del vértice adyacente y se lo asignamos a adjIndex
        int adjIndex = findVertex(adjVertex.target);
        // Validamos que en el vector de status en adjIndex sea falso
        if (!status[adjIndex]) {
          // Si es Falso
          // Validamos si el costo de adjIndex es mayor al costo de smallIndex +
          // el peso del vértice adyacente
          if (cost[adjIndex] > cost[smallIndex] + adjVertex.weight) {
            // Si es mayor
            // Cambiamos el costo de adjIndex al valor de la suma del costo de
            // smallIndex + el peso del vértice adyacente
            cost[adjIndex] = cost[smallIndex] + adjVertex.weight;
            // Cambiamos el valor del path de adjIndex por el valor de
            // smallIndex
            path[adjIndex] = smallIndex;
          }
        }
      }
      // actualizams el valor de smallIndex con el valor de la funcion
      // getSmallIndex
      smallIndex = getSmallIndex(status, cost);
    }
    // imprimimos el valor de los vectores de trabajo
    for (auto st : status) {
      std::cout << st << " ";
    }
    std::cout << std::endl;
    // imprimimos el valor de los vectores de trabajo
    for (auto cs : cost) {
      std::cout << cs << " ";
    }
    std::cout << std::endl;
    // imprimimos el valor de los vectores de trabajo
    for (auto pt : path) {
      std::cout << pt << " ";
    }
    std::cout << std::endl;
    // Aquí termina la primera parte del algoritmo
    // Empieza la segunda parte

    // Creamos un vector de pilas de números enteros del tamaño de size
    // (pathStack) vetor< stack<int> > pathStack Recorremos todos los vértices
    // de mi tabla de vértices Validamos si el valor del vector cost en la
    // posición del índice actual es < menor a infinito Si es menor Insertar el
    // índice actual en la pila en la posición del vector de pilas
    // correspondiente al índice actual (pathStack[i].push(i)) Creamos una
    // variable para guardar el valor actual del path (pathIndex) pathIndex = i
    // Ciclo mientras valor del vector path de la posición pathIndex != -1
    // insertar el valor que se encuentra en el vector path en la posición
    // pathIndex en la pila en la posición del vector de pilas correspondiente
    // al índice actual (pathStack[i].push(path[pathIndex])) Actualizamos el
    // valor de pathIndex con el valor del vector de path en la posición de
    // pathIndex

  } else {
    // No existe
    // Imprimir un error
    std::cout << "El vértice inicial no existe" << std::endl;
  }

  template <class T>
  int Graph<T>::getSmallIndex(vector<bool> status, vector<int> cost) {
    // Creamos una variable con el valor menor que sea igual a infinito
    // (minCost)
    int minCost = INT_MAX;
    // Creamos una variable para guardar cual fue el índice menor (minIndex) y
    // la igualamos a -1
    int minIndex = -1;
    // Recorremos todos los valor del vector de status
    for (int i = 0; i < size; i++) {
      // si el valor del indice actual del ciclo en el vector de status es igual
      // a falso
      if (!status[i]) {
        // si es falso
        // validamos si el costo del indice atual es menor a minCost
        if (cost[i] < minCost) {
          // si es menor
          // cambiamos el valor de minCost por el costo del indice actual
          minCost = cost[i];
          // cambiamos el valor de minIndex por el índice actual
          minIndex = i;
        }
      }
    }
    // Regresar el valor de minIndex
    return minIndex;
  }
#endif
