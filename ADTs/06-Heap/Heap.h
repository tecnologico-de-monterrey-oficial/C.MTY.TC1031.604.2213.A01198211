#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <cmath>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

template <class T> class Heap {
private:
  vector<T> heap;
  void swap(int, int);
  void downSort(int);
  void upSort(int);

public:
  Heap();            // inicializador vacio
  Heap(vector<T>);   // inicializador con vector
  void push(T data); // agregar un dato al final
  void pop();        // borrar el primer dato
  void print();      // imprimir resultado
  int levelnumber(); // numero de niveles del arbol
  int Size();        // tamaño del vector
  T operator[](int); // operador para sacar el dato en X indice del vector
  bool isEmpty();    // checa si esta vacio
  T getHead();       // obtiene el dato en la cabeza
};

template <class T> bool Heap<T>::isEmpty() { return heap.size() == 0; };

template <class T> T Heap<T>::getHead() {
  if (!isEmpty()) {
    return heap[0];
  } else {
    throw out_of_range("el heap esta vacio");
  }
}

template <class T> void Heap<T>::pop() {
  swap(0, heap.size() - 1);
  heap.pop_back();
  downSort(0);
}

template <class T> int Heap<T>::Size() { return heap.size(); }
template <class T> T Heap<T>::operator[](int index) { return heap[index]; }

template <class T> void Heap<T>::swap(int index1, int index2) {
  T aux = heap[index1];
  heap[index1] = heap[index2];
  heap[index2] = aux;
}
template <class T> Heap<T>::Heap(vector<T> list) {
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

template <class T> int Heap<T>::levelnumber() {
  return trunc(log2(heap.size()));
};

template <class T> void Heap<T>::downSort(int father) {
  // asegurarse que el padre tenga 1 hijo
  int smallSon;
  while (father * 2 + 1 < heap.size()) {
    int son1 = father * 2 + 1;
    // checar si hay otro hijo
    if (father * 2 + 2 < heap.size()) {
      int son2 = father * 2 + 2;
      // comparar hijo 1 y hijo 2 para ver cual es el mas grande (poner el
      // valor de smallSon como el mas grande)
      (heap[son1] > heap[son2]) ? smallSon = son1 : smallSon = son2;

    } else {
      // si solo hay un hijo, smallSon vale son1
      smallSon = son1;
    }

    // checar que el padre sea mayor que el hijo mas grande
    if (heap[father] > heap[smallSon]) {
      father = heap.size();
    } else {
      swap(father, smallSon);
      father = smallSon;
    }
  }
}

template <class T> void Heap<T>::upSort(int son) {
  while (son != 0) {
    int father = (son - 1) / 2;
    if (heap[son] > heap[father]) {
      swap(son, father);
      son = father;
    } else {
      son = 0;
    }
  }
}

template <class T> void Heap<T>::push(T data) {
  heap.push_back(data);
  upSort(heap.size() - 1);
}

template <class T> Heap<T>::Heap() {}

template <class T> void Heap<T>::print() {
  int counter = 0;
  for (int i = 0; i <= levelnumber(); i++) {
    for (int j = 1; j <= pow(2, i); j++) {
      if (counter < heap.size()) {
        cout << heap[counter] << " ";
        counter++;
      } else {
        break;
      }
    }
    cout << endl << endl;
  }
}

#endif
