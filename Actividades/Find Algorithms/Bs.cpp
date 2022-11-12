#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void startTime(chrono::high_resolution_clock::time_point &begin) {
  // start time
  begin = std::chrono::high_resolution_clock::now();
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que
// se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin,
             chrono::high_resolution_clock::time_point end) {
  end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

  printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}
int sequencialSearch(vector<int> list, int n) {
  for (int i = 0; i < list.size(); i++) {
    if (n == list[i]) {
      return i;
    }
  }
  return -1;
}

template <class T> int busuqedaBinaria(vector<T> list, T x) {
  int size = list.size();
  int key;
  int left = 0;
  int right = size - 1;
  while (left <= right) {

    key = (left + right) / 2;
    if (list[key] == x) {
      return key;
      break;
    } else {
      if (x < list[key]) {
        right = key - 1;
      } else {
        left = key + 1;
      }
    }
  }
  return -1;
};

int main() {
  vector<int> list;
  for (int i = 1; i <= 100; i++) {
    list.push_back(i * 2);
  }

  cout << "dime que numero quieres buscar" << endl;
  int n;
  cin >> n;
  cout << "busqueda secuencial: " << sequencialSearch(list, n) << endl;
  cout << "busqueda binaria: " << busuqedaBinaria(list, n) << endl;
  return 0;
}
