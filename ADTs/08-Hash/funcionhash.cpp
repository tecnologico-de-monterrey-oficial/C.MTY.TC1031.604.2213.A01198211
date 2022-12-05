#include <iostream>
#include <string>

int hashfunction(std::string matricula) {
  int numMatricula = stoi(matricula.substr(1, 8));
  return numMatricula % 99;
}

int main() {
  std::cout << hashfunction("A01198211") << std::endl;
  return 0;
}
