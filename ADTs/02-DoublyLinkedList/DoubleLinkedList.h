#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h
#include <__nullptr>
#include <iostream>
#include "NodeD.h"

template<class T>
class DoubleLinkedList{
  private:
    NodeD<T>*head;
    NodeD<T>*tail;
    int size;
  public:
    DoubleLinkedList();
    bool isEmpty();
    void print();
    void printReverse();
    void append(T data);
    void appendLeft(T data);
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(){
  this->head=nullptr;
  this->tail =nullptr;
  this->size=0;

}

template<class T>
bool DoubleLinkedList<T>::isEmpty(){
  return size==0;
}




template<class T>
void DoubleLinkedList<T>::print() {
    // Recorrer la lista de head hasta que el puntador al siguiente nodo sea igual a nulo
    // imprimir nodo por nodo
    NodeD<T>* aux = head;
    // ciclo mientras el puntador next de aux sea diferente de nulo
    while (aux != nullptr) {
        // Imprimimos el valor del nodo
        cout << aux->data << " ";
        // Recorremos aux al siguiente nodo
        aux = aux->next;
    }
    // Saltamos una línea
    cout << endl;
}


template<class T>
void DoubleLinkedList<T>::printReverse() {
    // Recorrer la lista de head hasta que el puntador al siguiente nodo sea igual a nulo
    // imprimir nodo por nodo
    NodeD<T>* aux = tail;
    // ciclo mientras el puntador next de aux sea diferente de nulo
    while (aux != nullptr) {
        // Imprimimos el valor del nodo
        cout << aux->data << " ";
        // Recorremos aux al previo nodo
        aux = aux->prev;
    }
    // Saltamos una línea
    cout << endl;
}


template<class T>
void DoubleLinkedList<T>::append(T data) {
    // Encontrar cual es el último elemento de la lista
    // Verificar si la lista esta vacia
    if (isEmpty()) {
        // Agregar un elemento nuevo que apunte a nulo
        // Apuntar head a ese elemento
        head = new NodeD<T>(data);
    } else {
        // Recorrer la lista desde head hasta que el apuntador al siguiente nodo sea igual a nulo
        // Crear un apuntador de tipo node que sea igual a head (aux)
        NodeD<T>* aux = head;
        // ciclo mientras el puntador next de aux sea diferente de nulo
        while (aux->next != nullptr) {
            // Recorremos aux al siguiente nodo
            aux = aux->next;
        }
        // Apuntar el apuntador next del último elemento a este nuevo elemento
        aux->next = new NodeD<T>(data);
    }
    // Incrementar en uno el valor del tamaño de la lista 
    size++;
}


template<class T>
void DoubleLinkedList<T>::appendLeft(T data) {

    head= new NodeD<T>(data , head , nullptr);

    if(tail==nullptr){
        // la lista estaba vacia
        tail=head;
    }
    else{
    // la lista no esta vacia
     head->next->prev=head;
    }
    size++;
}

#endif
