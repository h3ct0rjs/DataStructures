#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>

class Vector {
private:
  T *storage;
  int sz;
  int capacity;

public:
  Vector() : sz(0), capacity(5) { storage = new T[capacity]; }

private:
  void moveOneRight(int i) {
    for (int j = sz; j > i; j--)
      storage[j] = storage[j - 1];
  }

  void moveOneLeft(int i) {
    for (i; i < sz - 1; i++) {

      storage[i] = storage[i + 1];
    }
  }
  void resize() {
    int nc = capacity * 2;
    T *ns = new T[nc];

    for (int i = 0; i < sz; i++)
      ns[i] = storage[i];

    delete[] storage;
    storage = ns;
    capacity = nc;
  }
  void compact() {
    int nc = sz;
    T *ns = new T[nc];
    for (int i = 0; i < sz; i++)
      ns[i] = storage[i];
    delete[] storage;
    storage = ns;
    capacity = nc;
  }

public:

  int izquierdo(int pos){

    int posizq=(pos*2)+1;

    if(posizq>=sz){
      return pos;
      }
      else{
          return posizq;
        }
}

  int derecho(int pos){

    int posder=(pos*2)+2;

    if(posder>=sz){
      return pos;
      }
      else{
        return posder;
        }

  }





  int size() const { return sz; }; // O(1)

  void add(int i, const T &x) {
    assert(i >= 0 && i <= sz);
    if (sz == capacity)
      resize();
    moveOneRight(i);
    *(storage + i) = x;
    sz++;
  }

void append(T data){
  add (sz,data);
}


  T get(int i) { return storage[i]; }

  void set(int i, const T &x) {
    assert(i >= 0 && i <= sz);
    storage[i] = x;
  }

  void remove(int i) {
    assert(i >= 0 && i < sz);
    moveOneLeft(i);
    sz--;
    if (sz <= 2.0 / 3 * capacity)
      compact();
  }
  void pop_back() { remove(sz - 1); }

  void print() const {
    for (int i = 0; i < sz; i++) {
      std::cout << " " << storage[i];
      cout << " ";
    }
  }
  void swap(const int &i, const int &j) {
    T temp = storage[i];
    storage[i] = storage[j];
    storage[j] = temp;
  }
  int back() { return sz - 1; }
  void reset() {
    sz = 0;
    capacity = 4;
    T *ns = new T[capacity];
    delete storage;
    storage = ns;
  }
};
