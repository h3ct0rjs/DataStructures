
#include "vect.hh" //incluir los metodos y las clases que estan en el archivo v.hh
#include <iostream>

using namespace std;

int main() {
  Vector<int> prueba = produce(200, 1000, 10000);
  cout << "i";
  cout << "n-random";
  cout << "             ";
  cout << "VectorInsertion[ns]";
  cout << "             ";
  cout << "ArrayInsertion[ns]" << endl;
  for (int i = 0; i < 200; i++) {
    cout<< i <<" ";
    cout << prueba.get(i);
    cout << " ";
    testVector(prueba.get(i));
    cout << " ";
    testArray(prueba.get(i));
    cout << endl;
  }

  return 0;
}
