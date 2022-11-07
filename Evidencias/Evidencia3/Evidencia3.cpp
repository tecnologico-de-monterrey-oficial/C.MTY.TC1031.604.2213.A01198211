#include "BSTBL.h"
#include "BoatLog.h"
#include "HeapBL.h"
#include "minHeapBL.h"
#include <__nullptr>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <class T> void HeapSortD(vector<T> &list) {
  // Creamos un heap en base a la lista
  HeapBL heap(list);
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
  minHeapBL heap(list);
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

void printlist(vector<BoatLog> list) {
  for (int i = 0; i <= list.size(); i++) {
    std::cout << list[i].key << endl;
  }
  std::cout << endl;
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
  // creacion de listas para ordenar
  vector<BoatLog> MediterraneoOrdenadoAscendente = Mediterraneo;
  vector<BoatLog> RojoOrdenadoAscendente = Rojo;
  vector<BoatLog> MediterraneoOrdenadoDecendente = Mediterraneo;
  vector<BoatLog> RojoOrdenadoDecendente = Rojo;
  // ordenamiento de listas
  HeapSortA(MediterraneoOrdenadoAscendente);
  HeapSortA(RojoOrdenadoAscendente);
  HeapSortD(MediterraneoOrdenadoDecendente);
  HeapSortD(RojoOrdenadoDecendente);

  // creacion bst
  BSTBL<BoatLog> RojoBst;
  BSTBL<BoatLog> MediterraneoBst;

  // insertar datos en RojoBat
  for (int i = 0; i < Rojo.size(); i++) {
    RojoBst.insert(Rojo[i]);
  }

  // insertar datos en MediterraneoBst
  for (int i = 0; i < Mediterraneo.size(); i++) {
    MediterraneoBst.insert(Mediterraneo[i]);
  }
  // menu de opciones
  while (true) {
    int opcion;
    std::string busqueda;
    std::cout << "menu de opciones" << std::endl
              << "1) Ordenar Mediterraneo de manera Ascendente" << std::endl
              << "2) Ordenar Rojo de manera Ascendente" << std::endl
              << "3) Ordenar Mediterraneo de manera Descendente" << std::endl
              << "4) Ordenar Rojo de manera Descendente" << std::endl
              << "5) buscar un dato en Rojo" << std::endl
              << "6) buscar un dato en Mediterraneo " << std::endl
              << "7) cerrar" << std::endl;
    std::cin >> opcion;
    if (opcion == 1) {
      printlist(MediterraneoOrdenadoAscendente);
    } else if (opcion == 2) {
      printlist(RojoOrdenadoAscendente);
    } else if (opcion == 3) {
      printlist(MediterraneoOrdenadoDecendente);
    } else if (opcion == 4) {

      printlist(RojoOrdenadoDecendente);
    } else if (opcion == 5) {
      std::cin >> busqueda;
      std::cout << RojoBst.find(busqueda).key << std::endl;

    } else if (opcion == 6) {
      std::cin >> busqueda;
      std::cout << MediterraneoBst.find(busqueda).key << std::endl;
    } else if (opcion == 7) {
      break;
    } else {
      throw std::out_of_range("no diste una opcion valida");
    }
  }
}
