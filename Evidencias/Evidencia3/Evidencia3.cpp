#include "BoatLog.h"
#include "Heap.h"
#include "minHeap.h"
#include <__nullptr>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T> void HeapSortD(vector<T> &list) {
  // Creamos un heap en base a la lista
  Heap<T> heap(list);
  // removemos todos los elementos de la lista
  list.clear();
  // Eliminamos todos los elementos del heap hasta que este vacío
  while (!heap.isEmpty()) {
    // Insertamos en la lista el primer elemento del heaplist
    list.push_back(heap.getTop());
    // Removemos el primer elemento del heap
    heap.pop();
  }
}

template <class T> void HeapSortA(vector<T> &list) {
  // Creamos un heap en base a la lista
  minHeap<T> heap(list);
  // removemos todos los elementos de la lista
  list.clear();
  // Eliminamos todos los elementos del heap hasta que este vacío
  while (!heap.isEmpty()) {
    // Insertamos en la lista el primer elemento del heap
    list.push_back(heap.getTop());
    // Removemos el primer elemento del heap
    heap.pop();
  }
}
int main() {
  // declaracion de variables
  ifstream archivo;
  archivo.open("canalsuez3.txt");

  string fecha;
  string hora;
  string puntoEntrada;
  string ubi;
  // listas
  vector<BoatLog> Mediterraneo;
  vector<BoatLog> Rojo;

  // llenar las listas con los datos del archivo de texto
  while (archivo >> fecha >> hora >> puntoEntrada >> ubi) {
    BoatLog *data = new BoatLog(fecha, hora, puntoEntrada, ubi);
    if (puntoEntrada == "M") {
      Mediterraneo.push_back(*data);

    } else {
      Rojo.push_back(*data);
    }
  }
}
