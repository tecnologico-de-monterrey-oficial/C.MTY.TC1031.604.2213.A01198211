#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

template <class T>
void  Bubble_sort(vector<T> &list){
    int swaps= 0; int comparisons = 0;
   for(int i = 0; i <list.size()-1; i++){
       for(int j = 0 ; j<list.size()-i-1; j++){
            comparisons++;
           if(list[j]>list[j+1]){
                T item = list[j];
                list[j]=list[j+1];
                list[j+1]=item;
                swaps++;
           }
       }
   } 
   for(int i = 0 ; i<= list.size(); i++){
      cout<<list[i]<<" ";
   }
   cout<<endl<<"comparasiones: "<<comparisons<<" Intercambios: "<<swaps<<endl;
}
// Intercambio de dos elementos de la lista
template <class T>
void swap(vector<T> &list, int a, int b)
{
    if (a != b)
    {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}
template <class T>
int getPivot(vector<T> &list, int start, int end)
{
    // Opción 2 (Sin listas temporales)
    // Identificamos el pivote (El último elemento de la lista)
    T pivot = list[end];
    // Creamos un indice auxiliar igual a start -1 (auxIndex)
    int auxIndex = start - 1;
    // Recorremos toda la lista desde start hasta end - 1 (index)
    for (int index = start; index <= end - 1; index++)
    {
        // Validamos si el valor de la lista en index es menor al pivot
        if (list[index] < pivot)
        {
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
void quickSort(vector<T> &list, int start, int end)
{
    // Condición de control mientras start < end
    if (start < end)
    {
        // Encontrar el pivote y hacer las dos listas
        int pivot = getPivot(list, start, end);
        // Ordenamos la lista del lado izquierdo
        quickSort(list, start, pivot - 1);
        // Ordenamos la lista del lado derecho
        quickSort(list, pivot + 1, end);
    }
}

template <class T>
void Selection_sort(vector<T> &list){
     int swaps= 0; int comparisons = 0;
   for(int i = 0 ; i<=list.size()-1;i++){
        T item = list[i];
        T lowest = list[i];
        int index = i;
        for(int j = i ; j<=list.size() -1; j++){
            comparisons++;
           if(list[j]<lowest){
               swaps++;
               index = j;
               lowest = list[j];
          }
        }

        list[index] = list [i];
        list [i]= lowest;

    }
        cout<<endl;
   cout<<endl<<"comparasiones: "<<comparisons<<" Intercambios: "<<swaps<<endl;
}

template <class T>
void InsertionSort(vector<T> &list){
    int swaps= 0; int comparisons = 0;
   for(int i = 1; i<= list.size()-1;i++){
      T key = list[i];
      int j = i-1;
      while (j>=0 && list[j]>key) {
        comparisons++;
         list[j+1]=list[j];
         j--;
      }
      list[j+1]=key;
          swaps++;
   }
   cout<<endl<<"comparasiones: "<<comparisons<<" Intercambios: "<<swaps<<endl;
}

template <class T>
void printList(vector<T> &list) {
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}
template <class T>
void merge(vector<T> &list, int inf, int mid, int sup)
{
    // crear la lista temporal del lado izquierdo
    // crear un vector vacío (left)
    vector<T> left;
    // recorremos la lista desde inf hasta mid
    for (int i = inf; i <= mid; i++)
    {
        // agregamos el elemento a la lista izquierda (left)
        left.push_back(list[i]);
    }
    // crear la lista temporal del lado derecho
    // crear un vector vacío (right)
    vector<T> right;
    // recorremos la lista desde mid+1 hast sup
    for (int i = mid + 1; i <= sup; i++)
    {
        // agregamos el elemento a la lista derecha (right)
        right.push_back(list[i]);
    }

    // Merge
    // creamos el índice de la izquierda igual a 0 (idxLeft)
    int idxLeft = 0;
    // creamos el índice de la derecha igual a 0 (idxRight)
    int idxRight = 0;
    // creamos el indice de la lista igual a índice inf (idx)
    int idx = inf; // Ojo que sea igual a inf
    // Hacemos un ciclo mientras el índice de la izquierda < al tamaño de la lista izquierda y (&&)
    // el índice de la derecha < al tamaño de la lista derecha
    while (idxLeft < left.size() && idxRight < right.size())
    {
        // Comparamos si el valor que se encuentra en el índice de la izquierda (idxLeft) es menor
        // al valor que se encuentra en el índice de la derecha (idxRight)
        if (left[idxLeft] < right[idxRight])
        {
            // Si es menor
            // asignamos el valor de la lista izquierda que se encuentra en la posición del índice izquierdo (idxLeft)
            // en la posición de índice de la lista (idx)
            list[idx] = left[idxLeft];
            // incrementar el índice de la lista (idx)
            idx++;
            // incrementar el índice de la lista izquierda (idxLeft)
            idxLeft++;
        }
        else
        {
            // No es menor
            // asignamos el valor de la lista derecha que se encuentra en la posición del índice derecho (idxRight)
            // en la posición de índice de la lista (idx)
            list[idx] = right[idxRight];
            // incrementar el índice de la lista (idx)
            idx++;
            // incrementar el índice de la lista derecha (idxRight)
            idxRight++;
        }
    }
    // Hacemos un ciclo mientras el índice de la izquierda < al tamaño de la lista izquierda
    while (idxLeft < left.size())
    {
        // asignamos el valor de la lista izquierda que se encuentra en la posición del índice izquierdo (idxLeft)
        // en la posición de índice de la lista (idx)
        list[idx] = left[idxLeft];
        // incrementar el índice de la lista (idx)
        idx++;
        // incrementar el índice de la lista izquierda (idxLeft)
        idxLeft++;
    }
    // Hacemos un ciclo mientras el índice de la derecha < al tamaño de la lista derecha
    while (idxRight < right.size())
    {
        // asignamos el valor de la lista derecha que se encuentra en la posición del índice derecho (idxRight)
        // en la posición de índice de la lista (idx)
        list[idx] = right[idxRight];
        // incrementar el índice de la lista (idx)
        idx++;
        // incrementar el índice de la lista derecha (idxRight)
        idxRight++;
    }
}

template <class T>
void MergeSort(vector<T> &list, int inf, int sup)
{
    // Condición de control para validar que ya no puedo separar las sublistas
    // Si el indice inferior = indice superior
    if (inf < sup)
    {
        // Cuando el indice inferior sea menor al indice superior
        // Calcular el índice del medio ((inf+sup)/2)
        int mid = (inf + sup) / 2;
        // Volver a llamar a la función con la sublista del lado izquierdo (list,inf,mid)
        MergeSort(list, inf, mid);
        // Volver a llamar a la función con la sublista del lado derecho (list,mid+1,sup)
        MergeSort(list, mid + 1, sup);

        // Ocurre la magia - Juntar la sublista izquierda con la sublista derecha que ya estan ordenadas
        merge(list, inf, mid, sup);
    }
}
template<class T>
void Swapsort(vector<T> &list){
    int comparisons , swaps;
   for(int i = 0 ; i<list.size()-1;i++){
      for(int j = i+1 ; j<list.size();j++){
         comparisons++;
         if(list[i]>list[j]){
            T item = list[i];
            list[i]=list[j];
            list[j]= item;
            swaps++;
         }
      }
   }
   cout<<endl<<"comparasiones: "<<comparisons<<" Intercambios: "<<swaps<<endl;

};


// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}
template<class T>
void  crearvector(vector<T> &lista , int size){
    T elemento;
    for(int i = 0 ; i<= size-1; i++){
        cout<<"Que elemento quieres agregar?: ";
        cin>>elemento;
        lista.push_back(elemento);
    }
}

template<class T>
void sequencialSearch(vector<T> list, T n) {
    for(int i = 0; i < list.size(); i++) {
        if (n == list[i]) {
            cout<<n<<" esta en la posicion:"<<i<<endl;
        }
        else if(i>=list.size()){cout<<"no esta en la lista"<<endl;}
    }
}

template <class T>
void  busquedaBinaria(vector<T> list, T x)
{
  int size = list.size();
  int key;
  int left =0; 
  int right = size-1;
  while (left<=right){
    key = left + (right -left)/2;
    if (list[key]==x ){
      cout<<x <<"esta en la posicion"<<key<<endl; 
      break;
    }
    else if (x<list[key]){
      right=key-1; 
    }
    else if (x>list[key]) {
      left=key+1;
    }
    else{
        cout<<"no esta en la lista"<<endl;
        break;
    }
  }
}

int main(){
    srand(time(0));
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
    vector<string> listastr;
    vector<int> listaint;

    while (true) {
        char option;
        cout<<"a) crear listas"<<endl<<"b) busqueda secuencial"<<endl<<"c) busqueda binaria"<<endl<<"d) Bubble sort"<<endl<<"e) selection sort"<<endl<<"f) insertion sort"<<endl<<"g)MergeSort"<<endl<<"h) Swap sort" <<endl<<"i) quick sort"<<endl<<"q) cerrar programa"<<endl;
        cin>>option;
        if(option=='a'){
            int size;
            cout<<"que tan grande seran tus listas?"<<endl;
            cin>>size;
            cout<<"creacion de lista string"<<endl;
            crearvector<string>(listastr, size);
            printList<string>(listastr);
            cout<<"creacion de lista int"<<endl;
            crearvector<int>(listaint, size);
            printList(listaint);
        }
        else if(option=='b'){
            string busquedastring;
            cout<<"Que quieres buscar en el vector de strings? ";
            cin>>busquedastring;
            startTime(begin);
            sequencialSearch(listastr, busquedastring);
            getTime(begin, end);
            int busquedaint ;
            cout<<"Que quieres buscar en el vector de int? ";
            cin>>busquedaint;
            startTime(begin);
            sequencialSearch(listaint, busquedaint);
            getTime(begin, end);
        }
        else if(option == 'c'){
            string busquedastring;
            cout<<"Que quieres buscar en el vector de strings? ";
            cin>>busquedastring;
            startTime(begin);
            busquedaBinaria<string>(listastr, busquedastring);
            getTime(begin, end);
            int busquedaint ;
            cout<<"Que quieres buscar en el vector de int? ";
            cin>>busquedaint;
            startTime(begin);
            busquedaBinaria<int>(listaint, busquedaint);
            getTime(begin, end);
        }
        else if(option == 'd'){
            vector<string> nuevalistastr= listastr;
            startTime(begin);
            Bubble_sort(nuevalistastr);
            getTime(begin , end);
            printList(nuevalistastr);
            vector<int> nuevalistaint= listaint;
            startTime(begin);
            Bubble_sort(nuevalistaint);
            getTime(begin , end);
            printList(nuevalistaint);

        }
        else if(option == 'e'){
            vector<string> nuevalistastr= listastr;
            startTime(begin);
            Selection_sort(nuevalistastr);
            getTime(begin , end);
            printList(nuevalistastr);
            vector<int> nuevalistaint= listaint;
            startTime(begin);
            Selection_sort(nuevalistaint);
            getTime(begin , end);
            printList(nuevalistaint);

        }
        else if(option == 'f'){
            vector<string> nuevalistastr= listastr;
            startTime(begin);
            InsertionSort(nuevalistastr);
            getTime(begin , end);
            printList(nuevalistastr);
            vector<int> nuevalistaint= listaint;
            startTime(begin);
            InsertionSort(nuevalistaint);
            getTime(begin , end);
            printList(nuevalistaint);
        }
        else if(option == 'g'){
            vector<string> nuevalistastr= listastr;
            startTime(begin);
            MergeSort(nuevalistastr , 0 , nuevalistastr.size() );
            getTime(begin , end);
            printList(nuevalistastr);
            vector<int> nuevalistaint= listaint;
            startTime(begin);
            MergeSort(nuevalistaint , 0 , nuevalistaint.size());
            getTime(begin , end);
            printList(nuevalistaint);
        }
        else if(option == 'h'){
            vector<string> nuevalistastr= listastr;
            startTime(begin);
            Swapsort(nuevalistastr);
            getTime(begin , end);
            printList(nuevalistastr);
            vector<int> nuevalistaint= listaint;
            startTime(begin);
            MergeSort(nuevalistaint , 0 , nuevalistaint.size());
            getTime(begin , end);
            printList(nuevalistaint);
        }
        else if(option == 'i'){
            vector<string> nuevalistastr= listastr;
            startTime(begin);
            quickSort(nuevalistastr, 0, nuevalistastr.size());
            getTime(begin , end);
            printList(nuevalistastr);
            vector<int> nuevalistaint= listaint;
            startTime(begin);
            quickSort(nuevalistaint , 0 , nuevalistaint.size());
            getTime(begin , end);
            printList(nuevalistaint);
        }
        else if(option=='q'){
            break;
        }
    }

return 0;
};


