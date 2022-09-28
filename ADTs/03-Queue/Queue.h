#ifndef Queue_h
#define Queue_h
#include "Node.h"
#include <cstddef>
#include <iostream>


using namespace std;

template<class T>
class Queue{
  private:
    Node<T>* front;
    int size;
  public:
    Queue(); //constructor 
    void push(T data); //agregar al final de la fila
    T pop(); // eliminar el primer elemento de la fila
    void print(); // imprime la fila
    T getFront(); // regresa el valor del primer elemento de la fila
    int getSize();

};

template<class T>
Queue<T>::Queue(){
  front = nullptr;
  size = 0;
};

template <class T>
int Queue<T>::getSize(){
  return size;
}

template<class T>
void Queue<T>::push(T data){

  if(size ==0){
    front = new Node<T>(data);
  }
  else{
    Node<T>* aux = front;
    while(aux->next != nullptr){
      aux=aux->next;
    }
    aux->next = new Node<T>(data);
  }
  size++;

}

template <class T>
T Queue<T>::pop(){
  Node<T>* aux = front;
  front = front->next;
  return aux->data;
  delete aux;
}

template <class T>
void Queue<T>::print(){
  Node<T>* aux = front;
  int auxindex=0;
  while(aux!= nullptr){
    cout<<auxindex<<": "<<aux->data<<" "<<endl;
    auxindex++;

    aux=aux->next;
    
  }
  cout<<endl;
}

template <class T>
T Queue<T> ::getFront(){
  return front->data;
}



#endif
