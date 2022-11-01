#ifndef DoubleLinkedListE_h
#define DoubleLinkedListE_h
#include <__nullptr>
#include <iostream>
#include "NodeD.h"
#include "../BoatLog.h"

class DoubleLinkedListE{
  private:
    NodeD<BoatLog>*head;
    NodeD<BoatLog>*tail;
    int size;
  public:
    BoatLog& getTail();
    DoubleLinkedListE();
    bool isEmpty();
    void print();
    void printReverse();
    void append(BoatLog *data);
    void appendLeft(string data);
    BoatLog& getData(int index);
    void deleteAt(int index);
    int findData(string data); // * Regresa el indice donde se encontruentra el valor buscado
    int Size();
    void insert(int index, BoatLog data); // *Inserta un elemento después del índice dado
    void deleteData(string); // *Elimina el elemento dado (El primero que encuentre)
    BoatLog& operator[](int index);
    bool operator <=(BoatLog);
};

void DoubleLinkedListE::deleteData(string data){
  NodeD<BoatLog>* aux = head;
  int auxIndex = 0;
  while (auxIndex<=size && aux->data.key != data){
    auxIndex++;
    aux=aux->next;
  }
  aux->next->prev = aux->prev;
  aux->prev->next = aux->next;
  delete aux;

}

int DoubleLinkedListE::Size(){
    return size;

}

DoubleLinkedListE::DoubleLinkedListE(){
  this->head=nullptr;
  this->tail =nullptr;
  this->size=0;

}



void DoubleLinkedListE::print(){
    // Recorrer la lista de head hasta que el puntador al siguiente nodo sea igual a nulo
    // imprimir nodo por nodo
    NodeD<BoatLog>*aux=head;
    // ciclo mientras el puntador next de aux sea diferente de nulo
    while (aux != nullptr) {
        // Imprimimos el valor del nodo
        cout << aux->data.key << endl;
        // Recorremos aux al siguiente nodo
        aux = aux->next;
    }
    // Saltamos una línea
    cout << endl;
}



void DoubleLinkedListE::append(BoatLog *data) {
    tail = new NodeD<BoatLog>(*data , nullptr , tail);
    if(head ==nullptr){
        head = tail;
    }
    else {
        tail->prev->next=tail;
    }
    size++;
}

BoatLog& DoubleLinkedListE::getData(int index){
    // validar que el dato exista
    if(index>=0 && index <=size){
        if(index==0){
            return head->data;
        }
        else {
            NodeD<BoatLog>* aux;
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
                while(auxIndex>index+1){
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
BoatLog& DoubleLinkedListE::getTail(){
  return tail->data;
}

BoatLog& DoubleLinkedListE::operator[](int index){
    // validar que el dato exista
    if(index>=0 && index <=size){
      if(index==0){
        return head->data;
      }
      else {
        NodeD<BoatLog>* aux;
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
          while(auxIndex>index+1){
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
#endif
