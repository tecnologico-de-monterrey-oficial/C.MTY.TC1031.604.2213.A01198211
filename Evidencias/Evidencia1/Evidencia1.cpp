#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "./log.h"
using namespace std;

// Intercambio de dos elementos de la lista
template <class T>
void swap(vector<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

void printLogs(vector<Log> logs) {
    for (int i=0; i<logs.size(); i++) {
        cout << "UBI: " << logs[i].ubi << " datetime: " << logs[i].date << " " << logs[i].time << endl;
    }
}


int getPivotDate(vector<Log> &list, int start, int end) {
    // Opción 2 (Sin listas temporales)
    // Identificamos el pivote (El último elemento de la lista)
    int pivot = list[end].formatedDate;
    // Creamos un indice auxiliar igual a start -1 (auxIndex)
    int auxIndex = start - 1;
    // Recorremos toda la lista desde start hasta end - 1 (index)
    for (int index=start; index<=end-1; index++) {
        // Validamos si el valor de la lista en index es menor al pivot
        if (list[index].formatedDate<pivot) {
            // si es menor
            // incrementamos el valor de auxIndex
            auxIndex++;
            // intercambiamos en la lista auxIndex con index
            swap(list, auxIndex, index);
        // else
            // no vamos a hacer nada
        }
    }
    // incrementamos el valor de auxIndex
    auxIndex++;
    // intercambiamos auxIndex con el pivot(end)
    swap(list, auxIndex, end);
    // regresar el valor de auxIndex
    return auxIndex;
}

void quickSortDate(vector<Log> &list, int start, int end) {
    // Condición de control mientras start < end
    if (start < end) {
        // Encontrar el pivote y hacer las dos listas
        int pivot = getPivotDate(list, start, end);
        // Ordenamos la lista del lado izquierdo
        quickSortDate(list, start, pivot - 1);
        // Ordenamos la lista del lado derecho
        quickSortDate(list, pivot + 1, end);
    }
}
template <class T>
int getPivot(vector<T> &list, int start, int end) {
    // Opción 2 (Sin listas temporales)
    // Identificamos el pivote (El último elemento de la lista)
    T pivot = list[end];
    // Creamos un indice auxiliar igual a start -1 (auxIndex)
    int auxIndex = start - 1;
    // Recorremos toda la lista desde start hasta end - 1 (index)
    for (int index=start; index<=end-1; index++) {
        // Validamos si el valor de la lista en index es menor al pivot
        if (list[index]<pivot) {
            // si es menor
            // incrementamos el valor de auxIndex
            auxIndex++;
            // intercambiamos en la lista auxIndex con index
            swap(list, auxIndex, index);
        // else
            // no vamos a hacer nada
        }
    }
    // incrementamos el valor de auxIndex
    auxIndex++;
    // intercambiamos auxIndex con el pivot(end)
    swap(list, auxIndex, end);
    // regresar el valor de auxIndex
    return auxIndex;
}

template <class T>
void quickSort(vector<T> &list, int start, int end) {
    // Condición de control mientras start < end
    if (start < end) {
        // Encontrar el pivote y hacer las dos listas
        int pivot = getPivot(list, start, end);
        // Ordenamos la lista del lado izquierdo
        quickSort(list, start, pivot - 1);
        // Ordenamos la lista del lado derecho
        quickSort(list, pivot + 1, end);
    }
}

vector<string> split(string str, char pattern) {
    
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}


template<class T>
string  setkeyitem(vector<T> list , int key){
    string keyitem ;
    for(int  i= 0 ; i<=2 ; i++){
        keyitem = keyitem + list[key].ubi[i];
    }
    return keyitem;

}

vector<Log> busquedaBinaria(vector<Log> list, string x)
{
  int size = list.size();
  vector<Log> searchedItemList;
  int key;
  int left =0; 
  int right = size-1;
  while (left<=right){
    key = left + (right -left)/2;
    string keyitem = setkeyitem(list, key);
    if (keyitem==x ){
        searchedItemList.push_back(list[key]);
        list[key].ubi="";
        right = key+2;
        left=key-3;
    }
    else if (x<keyitem){
      right=key-1; 
    }
    else if (x>keyitem) {
      left=key+1;
    }
    else{
        cout<<"no esta en la lista"<<endl;
        break;
    }
  }
  return searchedItemList;
}

int main()
{

    ifstream file;

    // Abrimos el archivo de entrada
    file.open("canalsuez.txt");

    string date;
    string time;
    string entry;
    string ubi;

    vector<Log> logs;
    
    // Recorremos todo el archivo para crear agregar los renglones al vector
    while (file >> date >> time >> entry >> ubi) {
        vector<string> sDate;
        sDate = split(date, '-');        
        swap(sDate , 0 , 2);
        string formatedDate;
        for (int i = 0; i<= 2; i++) {
          formatedDate=formatedDate+sDate[i];
        } 
        
        Log log(date, stoi(formatedDate) , time, entry, ubi);
        logs.push_back(log);
    };
    
    quickSort(logs, 0, logs.size()-1);
    printLogs(logs);

    string elementoABuscar;
    cout<<"que elemento quieres buscar (primeras 3 letras de la ubicacion)"<<endl;
    cin>>elementoABuscar;
    vector<Log> resultados = busquedaBinaria(logs, elementoABuscar);
    cout<<endl<<endl<<endl;
    quickSortDate(resultados, 0, resultados.size()-1);
    printLogs(resultados);


    return 0;
};
