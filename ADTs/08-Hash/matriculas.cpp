#include "HastMat.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  fstream file("matriculas.txt");
  HashMat mat;
  string matricula;

  while (file >> matricula) {
    mat.addMatricula(matricula);
  }

  mat.print();
}
