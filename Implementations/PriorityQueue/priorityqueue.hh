#include "vect.hh"
#include <cassert>
#include <iostream>
#include <utility>
using namespace std;

template <typename P, typename T> class Pqueue {
private:
  Vector<pair<P, T>> storage;

public:
  Pqueue() : storage() {} // constructor que iniciaaliza storage
  bool empty() const { return storage.size() == 0; } // complejidad o(1)
  T get() { return storage.get(0).second; }
  P getPrio() { return storage.get(0).first; } // complejidad constante
  int tam() const { return storage.size(); }   // complejidad 0(1)

  void insert(P priori, T elem) {
    pair<P, T> b;
    b = make_pair(priori, elem);

    storage.add(storage.size(), b);
    int pos = storage.size() - 1;
    while (storage.get(pos).first < storage.get((pos - 1) / 2).first) {
      storage.swap(pos, ((pos - 1) / 2));
      pos = (pos - 1) / 2;
    }
  }

  void print() {
    for (int i = 0; i < storage.size(); i++) {
      cout << storage.get(i).first << " ";
      cout << storage.get(i).second << endl;
    }
  }

  void heapsort(int i) {
    if ((storage.get(i).first >= storage.get(2 * i + 1).first ||
         storage.get(i).first >= storage.get(2 * i + 2).first) &&
        i <= storage.size() - 1) {
      if (storage.get(i * 2 + 1).first <= storage.get(i * 2 + 2).first) {
        storage.swap(i * 2 + 1, i);
        if (i * 2 + 1 > storage.size() - 1)
          return;
        heapsort(i * 2 + 1);
      } else {
        storage.swap(i * 2 + 2, i);
        if (i * 2 + 2 > storage.size() - 1)
          return;
        heapsort(i * 2 + 2);
      }
    } else {
      return;
    }
  }

  void remove() {

    storage.swap(0, storage.size() - 1);
    storage.remove(storage.size() - 1);
    heapsort(0);
  }
};
