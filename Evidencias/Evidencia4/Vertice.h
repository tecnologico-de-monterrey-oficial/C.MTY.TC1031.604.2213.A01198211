#ifndef Vertice_h
#define Vertice_h

template <class T> struct Vertice {
  T dato;
  T relacion;
  int peso;
  Vertice();
  Vertice(T, T, int);
};

template <class T> Vertice<T>::Vertice() {}
template <class T> Vertice<T>::Vertice(T dato, T relacion, int peso) {
  this->dato = dato;
  this->relacion = relacion;
  this->peso = peso;
}

#endif
