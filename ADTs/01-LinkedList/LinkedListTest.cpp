#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
    LinkedList<string> list;
    list.appendLeft("Z");
    list.print();
    list.append("A");
    list.append("C");
    list.append("D");
    list.appendLeft("Y");
    try {
        list.insert(2,"B");
    } catch(out_of_range &e) {
        cout << e.what() << endl;
    }
    try{
        string aux = list.getData(2);
        cout<<"el valor de la posicion 2 es"<<aux<<endl;
    }
    catch(out_of_range&error){
        
    }
    list[0] = "X";
    cout << list[0] << endl;

    list.print();
    try{
        list.deleteAt(2);
        list.print();
    }
    catch(out_of_range &error){
        cout<<error.what()<<endl;
    }

    
    
    return 0;
}
