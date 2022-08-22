#include <iostream>
using namespace std;


int Sumaiterativa(int *arg , int size){
    int totalsum = 0;
   for(int i = 0 ; i<=size; i++){
        if(arg[i]%2 != 0){
            totalsum += arg[i];
        }
   } 
   return totalsum;
}

int SumaRecursiva(int *arg , int size , int totalsum = 0 ){
    if(size >= 0 ){
        if(arg[size]%2 != 0 ){
            return SumaRecursiva(arg, size-1 , totalsum +arg[size] );
        }
        else {
            return SumaRecursiva(arg, size-1 , totalsum);
        }
    }
    else{
        return totalsum;
    }
}
int main(){
    // crear array de ejemplo (del 1 a el tamaño n)
    int *arg; //array
    int n;//tamaño del array 
    cout<<"de que tomaño va a ser tu array"<<endl;
    cin>>n;
    arg = new int[n];
    for(int i = 0 ;i<n;i++){
        arg[i] = i+1;
    }
    

    cout<<"suna iterativa: "<<Sumaiterativa(arg, n)<<endl;
    cout<<"suma recursiva: "<<SumaRecursiva(arg, n)<<endl;

};


