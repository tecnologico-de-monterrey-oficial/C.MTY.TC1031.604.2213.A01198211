#ifndef BoatLog_h
#define BoatLog_h
#include <iostream>
#include <string.h>

using namespace std;

struct BoatLog {
  string fecha;
  string hora;
  string puntoEntrada;
  string ubi;
  string key;
  string mes;
  string año;

  BoatLog(string, string, string, string);
  BoatLog();
};

BoatLog::BoatLog(string fecha, string hora, string puntoEntrada, string ubi) {
  this->fecha = fecha;
  this->hora = hora;
  this->puntoEntrada = puntoEntrada;
  this->ubi = ubi;
  this->key = ubi + " " + fecha + " " + hora + " " + puntoEntrada;
  this->mes = fecha.substr(3, 2);
  this->año = fecha.substr(6, 2);
}
BoatLog::BoatLog() {
  this->fecha = "";
  this->hora = "";
  this->puntoEntrada = "";
  this->ubi = "";
  this->mes = "";
}

#endif
