#include "./DLL/DoubleLinkedListE.h"
#include "BoatLog.h"
#include <__nullptr>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void swap(DoubleLinkedListE &lista, int a, int b) {
  if (a != b) {
    BoatLog aux = lista[a];
    lista[a] = lista[b];
    lista[b] = aux;
  }
}
int getPivot(DoubleLinkedListE &lista, int start, int end) {

  // Opción 2 (Sin listas temporales)
  // Identificamos el pivote (El último elemento de la lista)
  string pivot = lista[end].key;
  // Creamos un indice auxiliar igual a start -1 (auxIndex)
  int auxIndex = start - 1;
  // Recorremos toda la lista desde start hasta end - 1 (index)
  for (int index = start; index <= end - 1; index++) {
    // Validamos si el valor de la lista en index es menor al pivot
    if (lista[index].key < pivot) {
      // si es menor
      // incrementamos el valor de auxIndex
      auxIndex++;
      // intercambiamos en la lista auxIndex con index
      swap(lista, auxIndex, index);
      // else
      // no vamos a hacer nada
    }
  }
  // incrementamos el valor de auxIndex
  auxIndex++;
  // intercambiamos auxIndex con el pivot(end)
  swap(lista, auxIndex, end);
  // regresar el valor de auxIndex
  return auxIndex;
}

void quickSort(DoubleLinkedListE &lista, int start, int end) {
  // Condición de control mientras start < end
  if (start < end) {
    // Encontrar el pivote y hacer las dos listas
    int pivot = getPivot(lista, start, end);
    // Ordenamos la lista del lado izquierdo
    quickSort(lista, start, pivot - 1);
    // Ordenamos la lista del lado derecho
    quickSort(lista, pivot + 1, end);
  }
}

int getPivotF(DoubleLinkedListE &lista, int start, int end) {

  // Opción 2 (Sin listas temporales)
  // Identificamos el pivote (El último elemento de la lista)
  string pivot = lista[end].mes + lista[end].año;
  // Creamos un indice auxiliar igual a start -1 (auxIndex)
  int auxIndex = start - 1;
  // Recorremos toda la lista desde start hasta end - 1 (index)
  for (int index = start; index <= end - 1; index++) {
    // Validamos si el valor de la lista en index es menor al pivot
    if (lista[index].mes + lista[index].año < pivot) {
      // si es menor
      // incrementamos el valor de auxIndex
      auxIndex++;
      // intercambiamos en la lista auxIndex con index
      swap(lista, auxIndex, index);
      // else
      // no vamos a hacer nada
    }
  }
  // incrementamos el valor de auxIndex
  auxIndex++;
  // intercambiamos auxIndex con el pivot(end)
  swap(lista, auxIndex, end);
  // regresar el valor de auxIndex
  return auxIndex;
}

void quickSortF(DoubleLinkedListE &lista, int start, int end) {
  // Condición de control mientras start < end
  if (start < end) {
    // Encontrar el pivote y hacer las dos listas
    int pivot = getPivotF(lista, start, end);
    // Ordenamos la lista del lado izquierdo
    quickSortF(lista, start, pivot - 1);
    // Ordenamos la lista del lado derecho
    quickSortF(lista, pivot + 1, end);
  }
}

string setkeyitem(DoubleLinkedListE &list, int key) {
  string keyitem;
  // saca las primeras 3 letras de la ubi
  for (int i = 0; i <= 2; i++) {
    keyitem = keyitem + list[key].ubi[i];
  }
  return keyitem;
}

DoubleLinkedListE busquedaBinaria(DoubleLinkedListE &list, string x) {
  int size = list.Size();
  DoubleLinkedListE searchedItemList;
  int key;
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    key = left + (right - left) / 2;
    // saca el key item que son las primeras 3 letras de la ubi
    string keyitem = setkeyitem(list, key);
    // checa si si es igual
    if (keyitem == x) {
      searchedItemList.append(&list[key]);
      if (key != list.Size() - 1) {
        // quita la ubi para que no lo vuelva a llamar
        list[key].ubi = "";
        // abre left y right para que busque en sus alrededores por repetidos
        right = key + 2;
        left = key - 3;
      } else {
        break;
      }
    }
    // si es menor
    else if (x < keyitem) {
      right = key - 1;
    }
    // si es mayor que
    else if (x > keyitem) {
      left = key + 1;
    }
  }
  return searchedItemList;
}

int main() {
  // declaracion de variables
  ifstream archivo;
  archivo.open("canalsuez2.txt");

  string fecha;
  string hora;
  string puntoEntrada;
  string ubi;
  // listas
  DoubleLinkedListE Mediterraneo;
  DoubleLinkedListE Rojo;

  // llenar las listas con los datos del archivo de texto
  while (archivo >> fecha >> hora >> puntoEntrada >> ubi) {
    BoatLog *data = new BoatLog(fecha, hora, puntoEntrada, ubi);
    if (puntoEntrada == "M") {
      Mediterraneo.append(data);

    } else {
      Rojo.append(data);
    }
  }

  // ordenar los datos con el quicksort

  quickSort(Mediterraneo, 0, Mediterraneo.Size());
  quickSort(Rojo, 0, Rojo.Size());
  // busqueda binaria
  string elementoABuscar;
  cout << "escriba que elemento quiere buscar" << endl;
  cin >> elementoABuscar;
  DoubleLinkedListE elementosEncontradosM =
      busquedaBinaria(Mediterraneo, elementoABuscar);
  DoubleLinkedListE elementosEncontradosR =
      busquedaBinaria(Rojo, elementoABuscar);
  // importar todas a una sola lista

  DoubleLinkedListE total;
  if (elementosEncontradosR.Size() != 0) {
    for (int i = 0; i < elementosEncontradosR.Size(); i++) {
      total.append(&elementosEncontradosR[i]);
    }
  }
  if (elementosEncontradosM.Size() != 0) {
    for (int i = 0; i < elementosEncontradosM.Size(); i++) {
      total.append(&elementosEncontradosM[i]);
    }
  }
  // quick sort de los elementos por mes y luego por año
  quickSortF(total, 0, total.Size());

  // declaracion de variables para el output
  int index = 0;
  int Count = 0;
  int cElementosM = 0;
  int cElementosR = 0;

  string meses[13] = {"",    "Jan",  "Feb", "Mar", "Apr", "May", "Jun",
                      "Jul", "Aug ", "Sep", "Oct", "Nov", "Dec"};
  // while loop que saca los oputputs
  //

  while (Count < total.Size()) {
    string fechaABuscar = total[index].mes + " " + total[index].año;
    if (total[Count].mes + " " + total[Count].año == fechaABuscar) {
      if (total[Count].puntoEntrada == "M") {
        cElementosM++;
      } else {
        cElementosR++;
      }
      Count++;
    } else {
      cout << meses[stoi(total[index].mes)] << " " << total[index].año << " M "
           << cElementosM << " R " << cElementosR << endl;
      index = Count;
      cElementosM = 0;
      cElementosR = 0;
    }
  }
  // ultimo output que no se pone en el while
  cout << meses[stoi(total[index].mes)] << " " << total[index].año << " M "
       << cElementosM << " R " << cElementosR << endl;
}
