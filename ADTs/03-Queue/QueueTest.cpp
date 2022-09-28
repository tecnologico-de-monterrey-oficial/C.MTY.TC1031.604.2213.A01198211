#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

int main(){
  Queue<string> filadepersonas;
  filadepersonas.push("Adrian");
 filadepersonas.push("Alex");
 filadepersonas.push("Angel");
  filadepersonas.print();
  cout<<"deleted "<<filadepersonas.pop()<<" fron list"<<endl;
  filadepersonas.print();
  cout<<"first in the list is "<<filadepersonas.getFront()<<endl;
return 0;
};


