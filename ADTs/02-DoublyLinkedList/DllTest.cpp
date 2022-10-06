#include <iostream>
#include <string>
#include "DoubleLinkedList.h"

using namespace std;

int main(){
  
  DoubleLinkedList<string> lista;
  lista.append("Adrian");
  lista.append("Alex");
  lista.append("Angel");
  lista.append("Alejandro");
  lista.append("Blanca");
  lista.print();

  cout<<"el elemento en la posicion 2 es "<<lista.getData(2)<<endl;
  cout<<"El nombre Alejandro se encuentra en la posicion "<<lista.findData("Alejandro")<<endl;

  lista.insert(3, "Aldape");
  lista.print();
  lista.deleteData("Aldape");
  lista.print();

  return 0 ;
}

