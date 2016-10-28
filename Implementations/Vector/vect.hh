#include "timer.hh"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

template <typename T>
// implementación vector
class Vector {
private:
  int sz;       // almacena cuantos elementos hay en mi vector
  int capacity; // Dice cuantos elementos me caben en un vector, es el número de
                // elementos hasta donde mi sec
  T *storage;   // Dirección a un pedazo de memoria donde voy aguardar los
  int numResizes; // este atributo nos va a servir para sacar conclusiones de
                  // nuestro experimento                // elementos del vector
public:
  Vector() : sz(0), capacity(4), numResizes(0) {
    // allocates memory for an array of capacity elements.
    storage = new T[capacity];
  }

  int size() const {
    return sz;
  } // complejidad constante porque siempre que llamo a size hace una operación

  void swap(int i, int j) {
    if (i > sz - 1 || j > sz - 1) {
      return;
    } else {
      T cambiar = storage[i];
      storage[i] = storage[j];
      storage[j] = cambiar;
    }
  }
  // Función para ahorrar memoria.
  void borrarb() {
    if (waste() > capacity / 3) {
      int nc = (capacity - capacity / 3);
      T *ns = new T[nc]; // Disminuyo el tamaño del arreglo para ahorrar memoria
      for (int i = 0; i < sz; i++) // copio los elementos
        ns[i] = storage[i];
      delete[] storage; // Destruir la memoria utilizada anteriormente
      capacity = nc;
      storage = ns;
    }
  }

  void moveOneLeft(int i) {
    for (int j = i; j < sz; j++)
      storage[j] = storage[j + 1];
    sz = sz - 1; // sz es la cantidad de elementos que hay, se resta uno porque
    capacity = capacity - 1; // se esta borrando un elemento
  }

  void remove(int i) {
    assert(i >= 0 && i <= sz);
    if (i == sz - 1) {
      sz--;
    } else {
      moveOneLeft(i); // Se elimina el elemento especificado
      borrarb();      // Resizing al array para ahorrar memoria
      // cout << "capacidad después de ahorrar memoria: " << capacity << endl;
      // cout << "Espacios no usados: " << capacity - sz << endl;
    }
  }

  void moveOneRight(int i) {
    for (int j = sz; j > i; j--)
      storage[i] = storage[j - 1];
  }

  void resize() {
    numResizes = numResizes + 1;
    // int nc = capacity * 2; // Diferentes politicas para hacer mi resize
    // int nc = capacity + 1; // Pide espacio solo para una casilla demás
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
    sz = sz + 1; // verificar que i es válida             // no puedo colocar
                 // const porque va a cambiar
  }

  T get(int i) { return storage[i]; }

  int waste() const { return capacity - sz; } // espacio sin utilizar

  int resizes() const {
    return numResizes;
  } // Devuelve el número de resizes, dice cuantas veces se hace resize para ese
  // vector

  bool search(T a) {
    for (int i = 0; i < sz; i++) {
      if (storage[i] == a)
        return true;
    }
    return false;
  }
};

void arrayInsertion(int n) {
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    a[i] = 1;
  }
}

void vectorInsertion(int n) {
  Vector<int> a;
  for (int i = 0; i < n; i++) {
    a.add(i, 1);
  }
}

Vector<int> produce(int s, int l, int u) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(l, u);
  Vector<int> result;
  for (int n = 0; n < s; n++) {
    result.add(n, dis(gen));
  }
  return result;
}

void testVector(int n) {
  Timer v("");
  vectorInsertion(n);
}

void testArray(int n) {
  Timer v("");
  arrayInsertion(n);
}
