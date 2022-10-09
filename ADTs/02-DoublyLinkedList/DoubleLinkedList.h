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
    T& getData(int index);
    void deleteAt(int index);
    int findData(T data); // * Regresa el indice donde se encontruentra el valor buscado
    int Size();
    void insert(int index, T data); // *Inserta un elemento después del índice dado
    void deleteData(T data); // *Elimina el elemento dado (El primero que encuentre)
};

template <class T>
void DoubleLinkedList<T>::deleteData(T data){
  NodeD<T>* aux = head;
  int auxIndex = 0;
  while (auxIndex<=size && aux->data != data){
    auxIndex++;
    aux=aux->next;
  }
  aux->next->prev = aux->prev;
  aux->prev->next = aux->next;
  delete aux;

}

template <class T>
int DoubleLinkedList<T>::Size(){
    return size;

}

template <class T>
void DoubleLinkedList<T>::insert(int index, T data){
  if(index>=0 && index <size){
      NodeD<T>*dataN;
    if(index == 0){
      dataN = new NodeD<T>(data ,head->next , head); 
      head->next->prev = dataN;
      head->next= dataN;
    }
    else {
      
     NodeD<T>*aux;
     int auxIndex;
     if(index<=size/2){
       aux = head->next;
       auxIndex=1;
       while (auxIndex<index){
         aux=aux->next;
         auxIndex++;
       }
     }
     else {
       aux = tail;
       auxIndex=size;
       while (auxIndex>index+1){
         aux=aux->prev;
         auxIndex--;
       }
     }
       dataN= new NodeD<T>(data, aux->next , aux);
       aux->next->prev = dataN;
       aux->next=dataN;
     
    }
    size ++;
  }
  else {
    throw out_of_range("el indice es invalido");
  }
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(){
  this->head=nullptr;
  this->tail =nullptr;
  this->size=0;

}

template <class T>
int DoubleLinkedList<T>::findData(T data){
    int auxIndex = 0;
    NodeD<T>*aux = head;

    while(auxIndex<= size){
        if(aux->data == data){
            break;
        }
        else {
            auxIndex++;
            aux = aux->next;
        }
    }
        return auxIndex;


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
        cout << aux->data << endl;
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
    tail = new NodeD<T>(data , nullptr , tail);

    if(head ==nullptr){
        head = tail;
    }
    else {
        tail->prev->next=tail;
    }
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



template<class T>
T&  DoubleLinkedList<T>::getData(int index){
    // validar que el dato exista
    if(index>=0 && index <=size){
        if(index==0){
            return head->data;
        }
        else {
            NodeD<T>* aux;
            int auxIndex;
            if(index <=size/2){
                auxIndex= 1;
                aux = head->next;
                while(auxIndex<index){
                    auxIndex++;
                    aux = aux->next;
                }

            }else {
                auxIndex= size;
                aux = tail;
                while(auxIndex>index){
                    auxIndex--;
                    aux = aux->prev;
                }
            }
            return aux->data;
        }


    }
    else {
        throw out_of_range("el indice es invalido");
    }
}
template<class T>
void DoubleLinkedList<T>::deleteAt(int index){
    if (index>=0 &&index<size){
        if(size==1){
            NodeD<T>*aux = head;
            head = nullptr;
            tail= nullptr;
            delete aux;
        }
        else {
            NodeD<T>*aux;
            if(index == size -1 ){
                aux=tail;
                tail=tail->prev;
                tail->next=nullptr;
                delete aux;
            }
            else{
                if(index<size/2){
                    aux = head->next;
                    int auxIndex = 1;
                    while(auxIndex<index){
                        aux=aux->next;
                        auxIndex++;
                    }
                }
                else {
                    NodeD<T>*aux = tail;
                }
            }
            aux->next= aux->prev;
            aux->next->prev = aux->prev;
            delete aux;
        }
        size--;
    }

    
}

#endif
