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
  int sz;          // almacena cuantos elementos hay en el vector
  int capacity;    // Dice cuantos elementos caben en el vector
  T *storage;      // Dirección a un pedazo de memoria donde se guardan los
                   // elementos del vector
  int numResizes;  // este atributo nos va a servir para sacar conclusiones de
                   // nuestro experimento
  int numResizes2; // Este atrubuto nos servirá para sacar concucliones de
                   // nuestro
                   // experimento

public:
  Vector() : sz(0), capacity(4), numResizes(0) {
    // allocates memory for an array of capacity elements.
    storage = new T[capacity];
  }

  // Función para saber cuantos elementos hay en el vector
  int size() const {
    return sz;
  } // complejidad constante porque siempre que llamo a size hace una operación

  // Función para ahorrar memoria, en caso de que haya mucho desperdicio
  void borrarb() {
    if (sz <= (2 * capacity) / 3) {
      int nc = sz;
      T *ns = new T[nc]; // Disminuyo el tamaño del arreglo para ahorrar memoria

      for (int i = 0; i < sz; i++) // copio los elementos
        ns[i] = storage[i];

      delete[] storage; // Destruir la memoria utilizada anteriormente
      capacity = nc;
      storage = ns;
      // complejidad de borrarb lineal en el tamaño actual del arreglo
    }
  }

  // Funciónj para desplazar todos los elementos del vector una posición hacia
  // la izquierda
  void moveOneLeft(int i) {
    for (int j = i; j < sz; j++)
      storage[j] = storage[j + 1];
  }

  // Función para remover un elemento del vector
  void removeNaive(int i) {
    assert(i >= 0 && i <= sz); // verificar que i es válida

    moveOneLeft(i);          // Se elimina el elemento especificado
    sz = sz - 1;             // Se disminuye en uno la cantidad de elementos
    capacity = capacity - 1; // se esta borrando un elemento
  }

  void remove(int i) {
    assert(i >= 0 && i <= sz); // verificar que i es válida

    cout << "capacidad actual " << capacity << endl;
    cout << "waste " << waste() << endl;
    moveOneLeft(i);  // Se elimina el elemento especificado
    borrarbPunto4(); // Resizing al array para ahorrar memoria
    cout << "Capacidad después de ahorrar memoria " << capacity << endl;
    sz = sz - 1;             // Se disminuye en uno la cantidad de elementos
    capacity = capacity - 1; // se esta borrando un elemento
  }

  // Función para desplazar los elementos del vector una posición hacia la
  // derecha
  void moveOneRight(int i) {
    for (int j = sz; j > i; j--)
      storage[j] = storage[j - 1];
  }

  // Función para aumentar el tamañao del vector
  void resize() {
    numResizes = numResizes + 1;
    int nc = capacity + 1; // Politica de crecimiento para el resize
    T *ns = new T[nc]; // le pido al sistema opertaivo mas espacio para un nuevo
                       // arreglo

    for (int i = 0; i < sz; i++) // copio los elementos
      ns[i] = storage[i];

    delete[] storage; // Destruir la memoria utilizada anteriormente
    storage = ns;
    capacity = nc;
    // complejidad de resize lineal en el tamaño actual del arreglo
  }

  // Función para añadir un elemento al vector
  void add(int i, const T &x) { // esta función no retorna nada tengo que
    assert(i >= 0 && i <= sz);  // verificar que i es válida

    if (sz == capacity)
      resize(); //  array is full

    moveOneRight(i);
    storage[i] = x; // Se añade el elemento al vector
    sz = sz + 1;    // no puedo colocar
                    // const porque va a cambiar
  }

  // Función para obtener un elemento del vector
  T get(int i) { return storage[i]; }

  // Función para saber el desperdicio de memoria
  int waste() const { return capacity - sz; } // espacio sin utilizar

  // Función para saber la cantidad de resizings que se le han hecho al vector
  int resizes() const { return numResizes; }

  int resizes2() const { return numResizes2; }

  // Función para vaciar vaciar un vector
  void eliminate() {
    delete[] storage;
    capacity = 4;
    sz = 0;
    storage = new T[capacity];
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

  for (int i = 0; i < n; i++)
    a.add(i, 1);
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

long testVector(long n) {
  Timer v("");
  vectorInsertion(n);
  return v.elapsed();
}

long testArray(long n) {
  Timer v("");
  arrayInsertion(n);
  return v.elapsed();
}

long mean(Vector<long> &data) {
  long sum = 0;
  for (int i = 0; i < data.size(); i++)
    sum += data.get(i);
  return sum / data.size();
}

long var(Vector<long> &data) {
  long sum = 0;
  long m = mean(data);
  long n = data.size() - 1;
  for (int i = 0; i <= n; i++) {
    sum = sum + pow((data.get(i) - m), 2);
  }
  return (sum / n);
}

long desvest(Vector<long> &data) { return sqrt(var(data)); }

Vector<long> testAdd(Vector<int> &a) {
  Vector<int> b = produce(100, 0, a.size()); // posiciones validas

  Vector<int> c = produce(100, 10, 100); // cantidad de veces que se inserta 10

  Vector<long> times;
  cout << "#10"
       << "        " << c.get(0) << endl;
  for (int i = 0; i < c.get(0); i++) {
    cout << "posición"
         << " " << b.get(i) << endl;
    Timer h("");
    a.add(b.get(i), 10);
    times.add(i, h.elapsed());
  }
  return times;
}

void displayTimes(Vector<long> &t) {
  cout << endl << "Tiempos" << endl;
  for (int i = 0; i < t.size(); i++) {
    cout << t.get(i) << endl;
  }
}

Vector<long> testRemove(Vector<int> &a) {

  Vector<int> b = produce(100, 0, a.size()); // posiciones validas
  Vector<int> c =
      produce(100, 10, 100); // la cantidad de veces que se inserta el 10
  Vector<long> times;
  cout << "removes"
       << "      " << c.get(0) << endl;
  for (int i = 0; i < c.get(0); i++) {
    cout << "posición"
         << " " << b.get(i) << endl;
    Timer h("");
    a.remove(b.get(i));
    times.add(i, h.elapsed());
  }
  return times;
}

// función que muestra el desperdicio y num resizes de la función borrarb
void testRemove2(Vector<int> &a) {
  Vector<int> b = produce(100, 0, a.size()); // posiciones validas
  Vector<int> c = produce(100, 10, 100);
  cout << "removes"
       << "      " << c.get(0) << endl;
  for (int i = 0; i < c.get(0); i++) {
    a.remove(b.get(i));
    cout << "waste" << a.waste() << endl;
  }
  cout << "resizes " << a.resizes2() << endl;
}
