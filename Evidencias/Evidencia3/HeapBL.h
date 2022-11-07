#ifndef HEAPBL_H_INCLUDED
#define HEAPBL_H_INCLUDED
#include "BoatLog.h"
#include <cmath>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

class HeapBL {
private:
  vector<BoatLog> heap;
  void swap(int, int);
  void downSort(int);
  void upSort(int);

public:
  HeapBL();                // inicializador vacio
  HeapBL(vector<BoatLog>); // inicializador con vector
  void push(BoatLog data); // agregar un dato al final
  void pop();              // borrar el primer dato
  void print();            // imprimir resultado
  int levelnumber();       // numero de niveles del arbol
  int Size();              // tamaño del vector
  BoatLog operator[](int); // operador para sacar el dato en X indice del vector
  bool isEmpty();          // checa si esta vacio
  BoatLog getTop();        // obtiene el dato en la cabeza
};

bool HeapBL::isEmpty() { return heap.size() == 0; };

BoatLog HeapBL::getTop() {
  if (!isEmpty()) {
    return heap[0];
  } else {
    throw out_of_range("el heap esta vacio");
  }
}

void HeapBL::pop() {
  swap(0, heap.size() - 1);
  heap.pop_back();
  downSort(0);
}

int HeapBL::Size() { return heap.size(); }
BoatLog HeapBL::operator[](int index) { return heap[index]; }

void HeapBL::swap(int index1, int index2) {
  BoatLog aux = heap[index1];
  heap[index1] = heap[index2];
  heap[index2] = aux;
}
HeapBL::HeapBL(vector<BoatLog> list) {
  // copiar la lista actualizada al heap
  heap = list;
  // Encontrar cual es el primer nodo padre (((list.size()-1)-1)/2)
  int father = (list.size() - 2) / 2;
  // Recorremos todos los padres desde el primero de los padres hasta el nodo
  // raíz Recorrer desde el primer nodo padre hasta el nodo raíz
  while (father >= 0) {
    // Hacemos el downSort del father
    downSort(father);
    // Decrementamos el valor de father
    father--;
  }
};

int HeapBL::levelnumber() { return trunc(log2(heap.size())); };

void HeapBL::downSort(int father) {
  // asegurarse que el padre tenga 1 hijo
  int smallSon;
  while (father * 2 + 1 < heap.size()) {
    int son1 = father * 2 + 1;
    // checar si hay otro hijo
    if (father * 2 + 2 < heap.size()) {
      int son2 = father * 2 + 2;
      // comparar hijo 1 y hijo 2 para ver cual es el mas grande (poner el
      // valor de smallSon como el mas grande)
      (heap[son1].key > heap[son2].key) ? smallSon = son1 : smallSon = son2;

    } else {
      // si solo hay un hijo, smallSon vale son1
      smallSon = son1;
    }

    // checar que el padre sea mayor que el hijo mas grande
    if (heap[father].key > heap[smallSon].key) {
      father = heap.size();
    } else {
      swap(father, smallSon);
      father = smallSon;
    }
  }
}

void HeapBL::upSort(int son) {
  while (son != 0) {
    int father = (son - 1) / 2;
    if (heap[son].key > heap[father].key) {
      swap(son, father);
      son = father;
    } else {
      son = 0;
    }
  }
}

void HeapBL::push(BoatLog data) {
  heap.push_back(data);
  upSort(heap.size() - 1);
}

HeapBL::HeapBL() {}

void HeapBL::print() {
  int counter = 0;
  for (int i = 0; i <= levelnumber(); i++) {
    for (int j = 1; j <= pow(2, i); j++) {
      if (counter < heap.size()) {
        cout << heap[counter].key << " ";
        counter++;
      } else {
        break;
      }
    }
    cout << endl << endl;
  }
}

#endif
