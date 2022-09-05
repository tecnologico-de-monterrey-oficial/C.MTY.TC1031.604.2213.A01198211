#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
template <class T>
void  Bubble_sort(vector<T> &list){
   for(int i = 0; i <list.size()-1; i++){
       for(int j = 0 ; j<list.size()-i-1; j++){
           if(list[j]>list[j+1]){
                T item = list[j];
                list[j]=list[j+1];
                list[j+1]=item;
           }
       }
   } 
   for(int i = 0 ; i<= list.size(); i++){
      cout<<list[i]<<" ";
   }
}


template <class T>
void Selection_sort(vector<T> &list){
    for(int i = 0 ; i<=list.size()-1;i++){
        T item = list[i];
        T lowest = list[i];
        int index = i;
        for(int j = i ; j<=list.size() -1; j++){
           if(list[j]<lowest){
               index = j;
               lowest = list[j];
          }
        }

        list[index] = list [i];
        list [i]= lowest;

    }
        for(int j = 0 ; j<=list.size() -1; j++){
           cout<<list[j]<<",";
        }
        cout<<endl;
}

template <class T>
void InsertionSort(vector<T> &list){
   for(int i = 1; i<= list.size()-1;i++){
      T key = list[i];
      int j = i-1;
      while (j>=0 && list[j]>key) {
         list[j+1]=list[j];
         j--;
      }
      list[j+1]=key;
   }
      for (int k = 0 ; k<=list.size()-1; k++) {
         cout<<list[k]<<",";
      }
      cout<<endl;
}

template <class T>
void printList(vector<T> &list, int msg) {
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}

template<class T>
void Merge(vector<T> &list , int inf , int mid , int sup){
   int i , j , k;
   int elementosI = mid - inf + 1;
   int elementosD = sup-mid;
   vector<T> left(elementosI);
   vector<T> right(elementosD);
   for(i = 0; i<elementosI; i++){
      left[i]= list[inf+i];
   }
   for(j = 0; j< elementosD; j++){
      right[j]= list[mid+1+j];
   }
   i = 0; 
   j = 0; 
   k = inf;
   while( i<elementosI && j<elementosD){
      if(left[i]<=right[j]){
         list[k] = left[i];
         i++;
      }
      else{
         list[k] = right[j];
         j++;
      }
      k++;
   }
   while (i<elementosI) {
      list[k]=left[i];
      i++ ; k++;
   }
   while (j<elementosD) {
      list[k]=right[j];
      j++ ; k++;
   }

}

template<class T>
void  MergeSort(vector<T> &list , int inf , int sup){
   int mid;
   if(inf<sup){
      mid = inf+(sup-inf)/2;
      MergeSort(list, inf, mid);
      MergeSort(list, mid + 1, sup);
      Merge(list , inf , mid , sup);
   }
}

template<class T>
void Swapsort(vector<T> &list, int &comparisons , int &swaps){
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
};


int main(){
    vector<int> listabase,list;
    for(int i = 0 ; i <= 10 ; i++){
        listabase.push_back(rand()%100+1);
    }
    cout<<"ordenado Bubble"<<endl;
   list = listabase; 
    Bubble_sort<int>(list);
    cout<<endl<<endl<<endl;
    cout<<"ordenamiento de seleccion"<<endl;
   list = listabase; 
    Selection_sort<int>(list);
    cout<<endl<<endl<<endl;

    cout<<"ordenamiento de insercion"<<endl;
   list = listabase; 
    InsertionSort<int>(list);
    cout<<endl<<endl<<endl;

    cout<<"ordenamiento de merge"<<endl;
   list = listabase; 
    MergeSort(list , 0 , list.size()-1);
    printList(list,1);
    cout<<endl<<endl<<endl;
    
    cout<<"ordenamiento de swap"<<endl;
   list = listabase; 
   int comparisons = 0;
   int swaps = 0;
    Swapsort(list , comparisons, swaps);
    printList(list,1);
    cout<<endl<<endl<<endl;
    
    return 0;
};


