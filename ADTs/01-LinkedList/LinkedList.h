#ifndef LinkedList_h
#define LinkedList_h


#include "Node.h"

template<class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    void append(T data); // Agrega un elemento al final de la lista
    void appendLeft(T data); // Agrega un elemento al principio de la lista
    int findData(T data); // * Regresa el indice donde se encontruentra el valor buscado
    T getData(int index); // * Regresa el valor que se encuentra en el índice dado
    T operator[](int index); // ** Regresa el valor que se encuentra en el índice dado
    void insert(int index, T data); // *Inserta un elemento después del índice dado
    void deleteAt(int index); // *Elimina un elemento en el índice dado
    void deleteData(T data); // *Elimina el elemento dado (El primero que encuentre)
    void print();
    bool isEmpty();
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

// Agrega un elemento al final de la lista
template<class T>
void LinkedList<T>::append(T data) {
    // Encontrar cual es el último elemento de la lista
    // Verificar si la lista esta vacia
    if (isEmpty()) {
        // Agregar un elemento nuevo que apunte a nulo
        // Apuntar head a ese elemento
        head = new Node<T>(data);
    } else {
        // Recorrer la lista desde head hasta que el apuntador al siguiente nodo sea igual a nulo
        // Crear un apuntador de tipo node que sea igual a head (aux)
        Node<T>* aux = head;
        // ciclo mientras el puntador next de aux sea diferente de nulo
        while (aux->next != nullptr) {
            // Recorremos aux al siguiente nodo
            aux = aux->next;
        }
        // Apuntar el apuntador next del último elemento a este nuevo elemento
        aux->next = new Node<T>(data);
    }
    // Incrementar en uno el valor del tamaño de la lista 
    size++;
}

// Agrega un elemento al principio de la lista
template<class T>
void LinkedList<T>::appendLeft(T data) {
    // Apuntar head a un nuevo elemento donde el apuntador next de este nuevo elemento, apunte al valor de head
    head = new Node<T>(data, head);
    // incrementar en uno size
    size++;
}

template<class T>
void LinkedList<T>::insert(int index, T data) {
    // Nos aseguramos que el índice que nos mandaron sea valído
    if (index >= 0 && index < size) {
        // Creamos un apuntador Aux que apunte a Head
        Node<T>* aux = head;
        // Crear un índice auxiliar igual a 0 para saber en que posición de la lista vamos 
        int auxIndex = 0;
        // Recorremos la lista hasta encontrar el índice dado
        while (auxIndex < index) {
            // Incrementar en 1 el valor del índice auxiliar
            auxIndex++;
            // Recorrer Aux
            aux = aux->next;
        }
        // Al salir del ciclo Aux apunta al nodo del indice dado
        // Insertar el nodo nuevo despues de AUX
        // Voy a apuntar el nodo nuevo a donde apuntaba aux
        aux->next = new Node<T>(data, aux->next);
        // Incrementamos en 1 el tamaño de la lista
        size++;
    // No es valido
    } else {
        // Generar una excepción
        throw out_of_range("El índice es inválido");
    }
}

template<class T>
void LinkedList<T>::print() {
    // Recorrer la lista de head hasta que el puntador al siguiente nodo sea igual a nulo
    // imprimir nodo por nodo
    Node<T>* aux = head;
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
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

#endif