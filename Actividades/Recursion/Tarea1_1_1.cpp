#include <iostream>
#include <math.h>
#include <iterator>
using namespace std;
// fibonachi
int fibonacchi_recursivo(int n, int lastnumber =0  , int numberbefore= 1 ){
    if(n>0){
        int x = lastnumber;
        lastnumber = lastnumber+numberbefore;
        numberbefore = x;
        fibonacchi_recursivo(n-1 , lastnumber , numberbefore );
    }
    else {        
        cout<<lastnumber<<endl;

    }

}
int fibonacchi_iterativo(int n){
    int lastnumber= 0 ;
    int numberbefore = 1;
    for (int i = 0 ;i<n ;i++){
        int x = lastnumber;
        lastnumber = lastnumber +numberbefore;
        numberbefore = x;
    }
    cout<<lastnumber<<endl;
}

// Bacterias 

float bacteriarecursiva(int n , float bacterias = 1){
    if(n> 0){
        bacteriarecursiva(n-1 ,bacterias*(3.78/2.34));
    }
    else{
        cout<<truncf(bacterias)<<endl;
    };
}
float bacteriaiterativa(int n){
    float bacterias = 1;
    for(int i = 0 ; i<n ;i++){
        bacterias=bacterias*(3.78/2.34);

    }
    cout<<truncf(bacterias)<<endl;
}

// Interes compuesto

float inversionRecursiva(int meses , float cantidad){
    if(meses>0){
        inversionRecursiva(meses-1, cantidad-(cantidad*0.1875));
    }
    else{
        cout<<cantidad<<endl;
    };
}

float inversionIterativa(int meses , float cantidad){
    for(int i = 0 ;i<meses ;i++){
        cantidad=cantidad-(cantidad*0.1875);
    };
    cout<<cantidad;
};

// potencia

int  potenciaRecursiva(int x , int y){
   if(y>1){
       potenciaRecursiva(x*x, y-1);
   } 
   else{
       cout<<x;
   };
}
int potenciaIterativa(int x , int y){
    for(int i = 0;i<1;i++){
        x = x*x;
    }
    cout<<x;
}

int main(){
    
}
