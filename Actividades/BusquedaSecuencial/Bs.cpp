#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int sequencialSearch(vector<int> list, int n) {
    for(int i = 0; i < list.size(); i++) {
        if (n == list[i]) {
            return i;
        }
        else if(i>=list.size()){cout<<"no esta en la lista"<<endl;}
    }
}

int busuqedaBinaria(vector<int> list, int x)
{
  int size = list.size();
  int key;
  int left =0; 
  int right = size-1;
  while (left<=right){
    key = left + (right -left)/2;
    if (list[key]==x ){
      return key; 
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
        return -1;
        break;
    }
  }
}



int main() {
    vector<int> list;
    for(int i = 0 ;i<=10 ;i++){
        list.push_back(rand()%100+1);
    }
    
    cout<<"dime que numero quieres buscar"<<endl;
   int n;
   cin >> n;
   cout<<"busqueda secuencial: "<<sequencialSearch(list, n)<<endl;
   cout<<"busqueda binaria: "<<busuqedaBinaria(list, n)<<endl;
   return 0;
}

