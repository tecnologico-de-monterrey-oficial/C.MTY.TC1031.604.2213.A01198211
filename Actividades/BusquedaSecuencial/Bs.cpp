#include <iostream>
#include <vector>
using namespace std;

bool sequencialSearch(vector<int> list, int n) {
    bool variable = false;
    for(int i = 0; i < list.size(); i++) {
        if (n == list[i]) {
            variable = true;
        }
    }
        if (variable == true) {
        cout << "Si esta en la lista";
        }
        else {
        cout << "No esta en la lista";
        }
}

int main() {
    vector<int> list;
    list.push_back(2);
    cout<<list[0];
   int n;
   cin >> n;
   sequencialSearch(list, n);
   return 0;
}

