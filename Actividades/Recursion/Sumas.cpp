#include <iostream>

using namespace std;

int suma_Iterativa(int n){
    int sum = 0;
    for(int i = 0 ;i<=n ; i++){
        sum = sum +i;
    };
    cout<<sum<<endl;
}

int suma_Recursiva(int n, int sum = 0,int count = 1){
    if(count<=n){
        suma_Recursiva(n , sum+count , count+1);
        
    }
    else{
        cout<<sum<<endl;
    }

    
}
int suma_Directa(int n){
    int sum = n*(n+1)/2;
    cout<<sum<<endl;
}

int main(){
    int k;
    cin>>k;
    for (int i = 0; i< k ;i++){
        int num;
        cin>>num;
        suma_Iterativa(num);
        suma_Recursiva(num);
        suma_Directa(num);

    }
}
