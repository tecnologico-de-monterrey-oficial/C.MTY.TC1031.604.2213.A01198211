#include <iostream>
#include <string>
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

string sumString (string a , string b , string c){
    return a + b + c ;
}
template <class T> 
T sumall(T a , T b , T c){
    return a + b + c;
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

    cout<<"suma de enteros 1.6 , 2.6 y 3.6: "<< sumInt(2.6, 1.6,3.6)<<endl;

    cout<<"suma de doubles 1.6 ,2.6 y 3.6: "<< sumDouble(2.6, 1.6, 3.6)<<endl;

    cout<<"suma de floats 1.6 , 2.6 y 3.6: "<< sumFloat(2.6, 1.6, 3.6)<<endl;

    cout<<"suma de strings 'hola'+ 'a' + 'todos'"<<sumString("hola","a","todos");

return 0;
}

