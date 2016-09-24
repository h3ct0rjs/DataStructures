#include "timer.hh"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>
//hfjimenez@utp.edu.co , camilo980818@gmail.com
//Datastructure Class 2016-2. UTP
//Porpouse: Implement my own vector class implementation.
using namespace std;

template <typename T> class Vector {

private:
  int sz;
  int capacity;
  T *storage;
  int numResizes;

public:
  Vector() : sz(0), capacity(4), numResizes(0) {
    // allocates memory for an array of capacity elements.
    storage = new T[capacity];
  }

 ~Vector(){     //destroy the storage allocation.
   delete[] storage;
 }

  int size() const {return sz;}   //Complexity O(1)

  void moveOneLeft(int i) {     //Complexity  O(n)
    for (int j = i; j < sz; j++)
      storage[j] = storage[j + 1];
    sz = sz - 1;
    capacity = capacity - 1;
  }

  void moveOneRight(int i) {
    for (int j = sz; j > i; j--)
      storage[i] = storage[j - 1];
  }

  void resize() {
    numResizes = numResizes + 1;
    int nc = capacity * 1.5;
    T *ns = new T[nc];
    for (int i = 0; i < sz; i++)
      ns[i] = storage[i];

    delete[] storage;
    storage = ns;
    capacity = nc;

  }

  void add(int i, const T &x) { // esta función no retorna nada tengo que
    assert(i >= 0 && i <= sz);
    if (sz == capacity) {
      resize();                 //  array is full
    }
    moveOneRight(i);
    storage[i] = x;
    sz = sz + 1; // verificar que i es válida             // no puedo colocar
                 // const porque va a cambiar
  }

  T pob_back(){
    return storage[sz-1];//Return the last element in the vector list.
  }

  T get(int i) { return storage[i]; }

  int waste() const { return capacity - sz; } // espacio sin utilizar

  int resizes() const {
    return numResizes;
  } // Devuelve el número de resizes, dice cuantas veces se hace resize para ese
  // vector


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
        // comp
      }
    }

      void remove(int i) {
        assert(i >= 0 && i <= sz);
        moveOneLeft(i);
        borrarb();
      }
};


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

void arrayInsertion(int n) {
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    a[i] = 1;
  }
}

void testArray(int n) {
  Timer v("");
  arrayInsertion(n);

}

void vectorInsertion(int n) {
  Vector<int> a;
  for (int i = 0; i < n; i++) {
    a.add(i, 1);
  }

}
void testVector(int n) {
  Timer v("");
  vectorInsertion(n);
}
