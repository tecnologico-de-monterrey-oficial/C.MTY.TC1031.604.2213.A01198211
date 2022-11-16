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

public:
  Graph();                        // constructor vacio
  Graph(std::vector<T> vertices); // vector de vertices
  Graph(std::vector<T> vertices,
        std::vector<Vertex<T>> edges); // vector de vertices y edges (edges son
                                       // las conecciones entre los grafos)
  void AddEdges();
  void print();
};

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

#endif
