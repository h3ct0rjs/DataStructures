#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>

// implementación vector
class Vector {
private:
  int sz;       // almacena cuantos elementos hay en mi vector
  int capacity; // Dice cuantos elementos me caben en un vector, es el número de
                // elementos hasta donde mi sec
  T *storage;   // Dirección a un pedazo de memoria donde voy aguardar los
                // elementos del vector
public:
  Vector() : sz(0), capacity(4) {
    // allocates memory for an array of capacity elements.
    storage = new T[capacity];
  }
  int size() const {
    return sz;
  } // complejidad constante porque siempre que llamo a size hace una operación
  // private:
  void moveOneRight(int i) {
    for (int j = sz; j > i; j--)
      storage[i] = storage[j - 1];
  }
  void resize() {
    cout << "Resizing  the internal array" << endl;
    // int nc = capacity * 2;
    // int nc = capacity * 3;
    int nc = capacity * 1.8;
    T *ns = new T[nc]; // le pido al sistema opertaivo mas espacio para un nuevo
                       // arreglo
    for (int i = 0; i < sz; i++) // copio los elementos
      ns[i] = storage[i];
    delete[] storage; // Destruir la memoria utilizada anteriormente
    storage = ns;
    capacity = nc;
    // complejidad de resize lineal en el tamaño actual del arreglo
  }
  void add(int i, const T &x) { // esta función no retorna nada tengo que
    assert(i >= 0 && i <= sz);
    if (sz == capacity) {
      resize(); //  array is full
    }

    moveOneRight(i);
    storage[i] = x;
    sz = sz + 1; // verificar que i es válida
                 // no puedo colocar const porque va a cambiar
  }
  T get(int i) { return storage[i]; }
}

;
