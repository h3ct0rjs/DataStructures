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
  Vector() : sz(0), capacity(4) { storage = new T[capacity]; }
  int size() const {
    return sz;
  } // complejidad constante porque siempre que llamo a size hace una operación

  /*  void add(int i, const T &x) { // esta función no retorna nada tengo que
                                  // verificar que i es válida
                                  // no puedo colocar const porque va a cambiar
      assert(i >= 0 && i <= sz);
      if (capacity > size())
    }*/
};
int main() {
  cout << "Vectores" << endl;
  Vector > int > x;
  cout << x.size() << endl;
  return 0;
}
