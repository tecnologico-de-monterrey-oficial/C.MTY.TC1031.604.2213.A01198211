#ifndef HashMatE_h
#define HashMatE_h
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <vector>

class HashMatE {
private:
  std::vector<std::vector<std::string>> hashTable[99];

public:
  HashMatE();
  int hashFunction(std::string matricula);
  bool getMatricula(std::string matricula);
  void addMatricula(std::string matricula);
  void deleteMatricula(std::string matricula);
  void print();
};

HashMatE::HashMatE() {}

int HashMatE::hashFunction(std::string matricula) {
  try {
    int numMatricula = stoi(matricula.substr(1, 8));
    return numMatricula % 99;
  } catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
    return -1;
  }
}

bool HashMatE::getMatricula(std::string matricula) {
  int index = hashFunction(matricula);
  if (index >= 0) {
    std::vector<std::string>::iterator it =
        find(hashTable[index].begin(), hashTable[index].end(), matricula);
    if (it != hashTable[index].end()) {
      return true;
    } else {
      return false;
    }
  }
  throw std::out_of_range("no existe la matricula");
}

void HashMatE::addMatricula(std::string matricula) {
  int index = hashFunction(matricula);
  if (index >= 0) {
    std::vector<std::string>::iterator it;
    it = find(hashTable[index].begin(), hashTable[index].end(), matricula);
    if (it == hashTable[index].end()) {
      hashTable[index].push_back(matricula);
    } else {
      throw std::invalid_argument("la matricula ya se encuentra");
    }
  }
}

void HashMatE::deleteMatricula(std::string matricula) {
  int index = hashFunction(matricula);
  std::vector<std::string>::iterator it;
  it = find(hashTable[index].begin(), hashTable[index].end(), matricula);
  if (it != hashTable[index].end()) {
    hashTable[index].erase(it);
  }
}

void HashMatE::print() {
  for (int i = 0; i < 99; i++) {
    std::cout << i << ": ";
    for (int j = 0; j < hashTable[i].size(); i++) {
      std::cout << hashTable[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

#endif
