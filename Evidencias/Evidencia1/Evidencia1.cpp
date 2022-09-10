
#include <iostream>
#include <vector>
#include <fstream>
#include "./log.h"

using namespace std;

int main() {
 ifstream archivo;
 archivo.open("casualsuez.txt");

   string date;
   string time;
   string entry;
   string ubi;

   vector<Log> logsfile;

   while (archivo >> date >> time >> entry >> ubi) {
    Log log(date, time, entry, ubi);
    cout << log.ubi << endl;
    logsfile.push_back(log);
   }

   for (auto l : logs) {
    cout << l.ubi << endl;
   }
   return 0;

}

