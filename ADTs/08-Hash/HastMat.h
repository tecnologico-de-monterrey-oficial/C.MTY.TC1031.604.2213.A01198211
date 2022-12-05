#ifndef HashMat_h
#define HashMat_h
#include <iostream>
#include <stdexcept>
#include <string.h>

class HashMat {
private:
  std::string hashTable[99];
  bool status[99];

public:
  HashMat();
  int hashFunction(std::string matricula);
  bool getMatricula(std::string matricula);
  void addMatricula(std::string matricula);
  void deleteMatricula(std::string matricula);
  void print();
};

HashMat::HashMat() {}

int HashMat::hashFunction(std::string matricula) {
  try {

    int numMatricula = stoi(matricula.substr(1, 8));
    return numMatricula % 99;
  } catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
    return -1;
  }
}

bool HashMat::getMatricula(std::string matricula) {
  // obtenemos la direccion base con la funcion hash
  int index = hashFunction(matricula);
  int baseIndex = index;
  if (index >= 0) {
    while (hashTable[index] != "" || status[index]) {
      if (hashTable[index] == matricula) {
        return true;
      } else {
        index = (index + 1) % 99;
        // validamos si ya le dimos la vuelta
        if (index == baseIndex) {
          return false;
        }
      }
    }
    return false;
  }
}

void HashMat::addMatricula(std::string matricula) {
  int index = hashFunction(matricula);
  int baseIndex = index;
  if (index >= 0) {
    while (hashTable[index] != "") {
      index = (index + 1) % 99;
      // validamos si ya le dimos la vuelta
      if (index == baseIndex) {
        throw std::invalid_argument("la Tabla esta llena");
        return;
      }
    }
    hashTable[index] = matricula;
  }
}

void HashMat::deleteMatricula(std::string matricula) {
  // obtenemos la direccion base con la funcion hash
  int index = hashFunction(matricula);
  int baseIndex = index;
  if (index >= 0) {
    while (hashTable[index] != "" || status[index]) {
      if (hashTable[index] == matricula) {
        hashTable[index] = "";
        status[index] = true;
      } else {
        index = (index + 1) % 99;
        // validamos si ya le dimos la vuelta
        if (index == baseIndex) {
          throw std::invalid_argument("la matricula no se encuentra");
          return;
        }
      }
    }
    throw std::invalid_argument("la matricula no se encuentra");
  }
}

void HashMat::print() {
  for (auto i : hashTable) {
    std::cout << i << std::endl;
  }
}
#endif
