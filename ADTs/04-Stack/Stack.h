#ifndef Stack_h
#define Stack_h
#include "Node.h"
#include <__nullptr>
#include <iostream>

using namespace std;

template<class T>
class Stack{
  private:
    Node<T>* top;
    int size;

  public:
    Stack();
    T getTop();
    T pop();
    void push(T data);
    void print();
    bool isEmpty();
};

template<class T>
void Stack::Stack(){
  top=nullptr;
}

#endif
