#include "Heap.h"
#include "minHeap.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> ejemplolista = {0, 1, 2, 10, 5, 4};
  minHeap<int> mheap(ejemplolista);
  Heap<int> heap(ejemplolista);
  // minheap
  cout << "minheap" << endl;
  mheap.push(3);
  mheap.push(6);
  mheap.print();
  // heap
  cout << "heap" << endl;
  heap.push(3);
  heap.push(6);
  heap.print();
}
