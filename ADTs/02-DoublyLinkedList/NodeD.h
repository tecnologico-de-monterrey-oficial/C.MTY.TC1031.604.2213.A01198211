#pragma once
#include <__nullptr>
#include <iostream>

using namespace std;

template<class T>
struct NodeD {
    T data;
    NodeD<T>* next;
    NodeD<T>* prev;
    NodeD();
    NodeD(T data);
    NodeD(T data, NodeD<T>* next);
};

template<class T>
NodeD<T>::NodeD() {
    next = nullptr;
}

template<class T>
NodeD<T>::NodeD(T data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

template<class T>
NodeD<T>::NodeD(T data, NodeD<T>* next) {
    this->data = data;
    this->next = next;
    this->prev =prev;
}
