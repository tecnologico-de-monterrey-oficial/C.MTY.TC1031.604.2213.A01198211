#include <iostream>
#include <math.h>
#include <iterator>
using namespace std;
// fibonachi
int fibonachiRecursivo(int n, int lastnumber =0  , int numberbefore= 1 ){
    if(n>0){
        int x = lastnumber;
        lastnumber = lastnumber+numberbefore;
        numberbefore = x;
        return fibonachiRecursivo(n-1 , lastnumber , numberbefore );
    }
    else {        
        return lastnumber;

    }

}
int fibbonachiIterativo(int n){
    int lastnumber= 0 ;
    int numberbefore = 1;
    for (int i = 0 ;i<n ;i++){
        int x = lastnumber;
        lastnumber = lastnumber +numberbefore;
        numberbefore = x;
    }
    return lastnumber;
}

// Bacterias 

float bacteriasRecursiva(int n , float bacterias = 1){
    if(n> 0){
        return bacteriasRecursiva(n-1 ,bacterias*(1+3.78-2.34));
    }
    else{
        return truncf(bacterias);
    };
}
float bacteriasIterativas(int n){
    float bacterias = 1;
    for(int i = 0 ; i<n ;i++){
        bacterias=bacterias*(1+3.78-2.34);
        

    }
    return truncf(bacterias);
}

// Interes compuesto

float inversionRecursiva(int meses , float cantidad){
    if(meses>0){
        return inversionRecursiva(meses-1, cantidad-(cantidad*0.1875));
    }
    else{
        return cantidad;
    };
}

float inversionIterativa(int meses , float cantidad){
    for(int i = 0 ;i<meses ;i++){
        cantidad=cantidad-(cantidad*0.1875);
    };
    return cantidad;
};

// potencia

int  potenciaRecursiva(int x , int y){
   if(y>1){
       return potenciaRecursiva(x*x, y-1);
   } 
   else{
       return x;
   };
}
int potenciaIterativa(int x , int y){
    for(int i = 0;i<=1;i++){
        x = x*x;
    }
    return x;
}

int main(){
    // llamar fibonachi con 10 iteraciones
    cout<<"fibonachi recursivo: ";
    cout<<fibonachiRecursivo(10);
    cout<<endl;
    cout<<"fibonachi iterativo: ";
    cout<<fibbonachiIterativo(10);
    cout<<endl;
    // llamar funciones bacterias con 10 dias
    cout<<"bacteria recursiva: ";
    cout<<bacteriasRecursiva(10);
    cout<<endl;
    cout<<"bacteria iterativa: ";
    cout<<bacteriasIterativas(10);
    cout<<endl;
    // llamar interes compuesto con 10 meses con 10000 pesos 
    cout<<"inversion recursiva: ";
   cout<< inversionRecursiva(10 , 10000);
    cout<<endl;
    cout<<"inversion iterativa: ";
    cout<<inversionIterativa(10 , 10000);
    cout<<endl;
   // Potencia de 10^5
    cout<<"potencia recursiva: ";
    cout<<potenciaRecursiva(10,3);
    cout<<endl;
    cout<<"potencia Iterativa:";
    cout<<potenciaIterativa(10,3);
    cout<<endl;
}

