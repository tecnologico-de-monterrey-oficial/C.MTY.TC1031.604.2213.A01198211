#include <iostream>
using namespace std;

int sumInt(int a , int b, int c){
    return a + b+c;
}

double sumDouble(double a, double b, double c ){

    return a + b+ c;
}

float sumFloat (float a , float b ,float c){
    return a + b+c;
}


int main()
{

    // Act 1 
    // Realiza 3 funciones para sumar 3 numeros 
    // vas a recibir los 3 numeros como parametros 
    // 1 funcion con enteros 
    // 1 funcion con double 
    // 1 funcion con flotante
    //
    // Sumint , Sumdouble , sumfloat

    cout<<"suma de enteros 1 , 2 y 3: "<< sumInt(2, 1,3)<<endl;
    cout<<"suma de doubles 1 ,2 y 3: "<< sumDouble(2, 1, 3)<<endl;
    cout<<"suma de floats 1, 2 y 3: "<< sumFloat(2, 1, 3)<<endl;

return 0;
}

