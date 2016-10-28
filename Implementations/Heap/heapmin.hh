#include "vect.hh"
#include <cassert>
#include <iostream>

using namespace std;

template <typename T> class Heapmin {
private:
  Vector<T> storage;

public:
  Heapmin() : storage() {} // constructor que iniciaaliza storage
  bool empty() const { return storage.size() == 0; } // complejidad o(1)
  T get() { return storage.get(0); }
  int tam() const { return storage.size(); } // complejidad 0(1)

  // complejidada de insertar en un heap logaritmica log en base dos del numero
  // de elementos
  void insert(T elem) {
    storage.add(storage.size(), elem);
    int pos = storage.size() - 1;
    while (storage.get(pos) < storage.get((pos - 1) / 2)) {
      storage.swap(pos, ((pos - 1) / 2));
      pos = (pos - 1) / 2;
    }
  }

  void print() {
    for (int i = 0; i < storage.size(); i++) {
      cout << storage.get(i) << endl;
    }
  }

  void remove() {

    storage.swap(storage.size() - 1, 0);
    storage.remove(storage.size() - 1);
    int pos = 0;
    while ((storage.get(pos) > storage.get(2 * pos + 1) ||
            storage.get(pos) > storage.get(2 * pos + 2)) &&
           pos < storage.size() - 1) {

      if (storage.get(2 * pos + 1) < storage.get(2 * pos + 2)) {
        storage.swap(pos, (2 * pos + 1));
        pos = 2 * pos + 1;

      } else {
        storage.swap(pos, (2 * pos + 2));
        pos = 2 * pos + 2;
      }
    }
  }
};
