#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

template <class T>
vector<T> Swap(vector<T> list, int index){
    T item = list[index];
    list[index]=list[index+1];
    list[index+1]=item;
    return list;
}


template <class T>
vector<T> Bubble_sort(vector<T> list){
   for(int i = 0; i <= list.size()-1 ; i++){
       for(int j = 0 ; j<=list.size()-1; j++){
           if(list[j]>list[j+1]){
                T item = list[j];
                list[j]=list[j+1];
                list[j+1]=item;
           }
           cout<<list[j]<<",";
       }
       cout<<endl;
   } 
   return list;
}


template <class T>
vector<T> Selection_sort(vector<T> list){
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

        for(int j = 0 ; j<=list.size() -1; j++){
           cout<<list[j]<<",";
        }
        cout<<endl;
    }
    return list;
}



int main(){
    vector<int> list;
    for(int i = 0 ; i <= 10 ; i++){
        list.push_back(rand()%100+1);
    }
    cout<<"ordenado Bubble"<<endl;
    Bubble_sort<int>(list);
    cout<<endl<<endl<<endl;
    cout<<"ordenamiento de seleccion"<<endl;
    Selection_sort(list);
    cout<<endl<<endl<<endl;
    return 0;
};


