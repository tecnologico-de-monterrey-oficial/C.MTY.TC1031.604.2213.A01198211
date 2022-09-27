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
    list[0] = "X";
    cout << list[0] << endl;

    list.print();

    
    
    return 0;
}
