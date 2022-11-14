#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "Vertex.h"
#include <iostream>
#include <vector>

template <class T> class Graph {
private:
  std::vector<std::vector<Vertex<T>>> graph;
  std::vector<T> vertices;
  int size;
  int findVertex(T vertex);
  void DFSR(int vertexIndex, std::vector<bool> &status);

public:
  Graph();
  Graph(std::vector<T> vertices);
  Graph(std::vector<T> vertices, std::vector<T> edges);
  void AddEdges();
};
template <class T> Graph<T>::Graph() { size = 0; }
template <class T> Graph<T>::Graph(std::vector<T> vertices) {
  this->vertices = vertices;
  size = vertices.size();
  graph.resize(size);
}
template <class T>
Graph<T>::Graph(std::vector<T> vertices, std::vector<T> edges) {
  this->vertices = vertices;
  size = vertices.size();
  graph.resize(size);
}

#endif
