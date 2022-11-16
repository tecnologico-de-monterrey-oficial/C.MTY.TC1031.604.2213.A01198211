#ifndef Stack_h
#define Stack_h
#include "Node.h"
#include <__nullptr>
#include <iostream>

using namespace std;

template <class T> class Stack {
private:
  Node<T> *top;
  int size;

public:
  Stack();
  T getTop();
  T pop();
  void push(T data);
  void print();
  bool isEmpty();
};

template <class T> Stack<T>::Stack() {
  size = 0;
  top = nullptr;
}

template <class T> void Stack<T>::push(T data) {
  if (isEmpty()) {
    top = new Node<T>(data);
  } else {
    Node<T> *aux = top;
    while (aux->next != nullptr) {
      aux = aux->next;
    }
    aux->next = new Node<T>(data);
  }
  size++;
}

template <class T> T Stack<T>::pop() {
  if (!isEmpty()) {
    Node<T> *aux = top;
    for (int i = 0; i < size - 2; i++) {
      aux = aux->next;
    }
    Node<T> *next = aux->next;
    aux->next = nullptr;
    T nextdata = next->data;
    delete next;
    size--;
    return nextdata;
  } else {
    throw out_of_range("La fila esta vacía");
  }
}

template <class T> T Stack<T>::getTop() {
  if (!isEmpty()) {
    Node<T> *aux = top;
    while (aux->next != nullptr) {
      aux = aux->next;
    }
    return aux->data;
  } else {
    throw out_of_range("La fila esta vacía");
  }
}

template <class T> void Stack<T>::print() {
  Node<T> *aux = top;
  while (aux != nullptr) {
    cout << aux->data << " ";
    aux = aux->next;
  }
  cout << endl;
}

template <class T> bool Stack<T>::isEmpty() { return size == 0; }

#endif
