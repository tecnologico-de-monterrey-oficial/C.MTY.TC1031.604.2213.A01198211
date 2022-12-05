#ifndef HashBoat_h
#define HashBoat_h
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

class HashBoat {
private:
  string hash[15];
  bool status[15];
  int hashFunction(string);

public:
  HashBoat();
  int getBoat(string);
  void addBoat(string);
  void deleteBoat(string);
  void print();
  string operator[](int);
};

HashBoat::HashBoat(){};

string HashBoat::operator[](int indice) { return hash[indice]; }

int HashBoat::hashFunction(string boat) {
  char letra0 = boat.at(0);
  char letra1 = boat.at(1);
  char leltra2 = boat.at(2);
  return (int(letra0) + int(letra1) + int(leltra2)) % 15;
};

int HashBoat::getBoat(string boat) {
  int index = hashFunction(boat);
  int baseIndex = index;
  while (hash[index] != "" || status[index]) {
    if (hash[index] == boat) {
      return index;
    } else {
      index = (index + 1) % 15;
      if (index == baseIndex) {
        return -1;
      }
    }
  }
  return -1;
};

void HashBoat::addBoat(string boat) {

  int index = hashFunction(boat);
  int baseIndex = index;
  if (index >= 0) {
    while (hash[index] != "") {
      index = (index + 1) % 15;
      // validamos si ya le dimos la vuelta
      if (index == baseIndex) {
        throw std::invalid_argument("la Tabla esta llena");
        return;
      }
    }
    hash[index] = boat;
  }
}

void HashBoat::deleteBoat(string boat) {
  // obtenemos la direccion base con la funcion hash
  int index = hashFunction(boat);
  int baseIndex = index;
  if (index >= 0) {
    while (hash[index] != "" || status[index]) {
      if (hash[index] == boat) {
        hash[index] = "";
        status[index] = true;
      } else {
        index = (index + 1) % 15;
        // validamos si ya le dimos la vuelta
        if (index == baseIndex) {
          throw std::invalid_argument("la boat no se encuentra");
          return;
        }
      }
    }
    throw std::invalid_argument("la boat no se encuentra");
  }
}

void HashBoat::print() {
  for (auto hashh : hash) {
    std::cout << hashh << std::endl;
  }
}

#endif
