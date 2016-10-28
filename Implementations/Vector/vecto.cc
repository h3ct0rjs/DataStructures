#include "vecto.hh" //incluir los metodos y las clases que estan en el archivo v.hh #include <iostream>

using namespace std;

void punto1() {
  Vector<int> prueba = produce(100, 500, 8000);
  Vector<long> timesVector;
  // Vector<long> timesArray;

  int j = 0;
  while (j < 10) {
    cout << endl << endl << endl;
    cout << prueba.get(j) << "            " << j << endl << endl;

    for (int i = 0; i < 50; i++) {
      timesVector.add(i, testVector(prueba.get(j)));
      // timesArray.add(i, testArray(prueba.get(j)));
      cout << timesVector.get(i) << endl;
      // cout << timesArray.get(i);
      cout << endl;
    }
    cout << "Promedio" << endl;
    cout << mean(timesVector) << endl;
    // cout << mean(timesArray) << endl;
    cout << "Desviación Estándar" << endl;
    cout << desvest(timesVector) << endl;
    // cout << desvest(timesArray) << endl;
    timesVector.eliminate();
    // timesArray.eliminate();
    j++;
  }
}

void punto2() {
  Vector<int> prueba = produce(2000000, 0, 5000000);
  Vector<long> t = testAdd(prueba);
  displayTimes(t);
}
void punto3() {
  Vector<int> prueba = produce(2000000, 0, 5000000);
  Vector<long> t = testRemove(prueba);
  displayTimes(t);
}

void punto4A() {
  Vector<int> prueba = produce(50, 1000, 30000);
  Vector<long> a;
  cout << "#Elementos "
       << "waste "
       << "resizes " << endl;

  int j = 0;
  while (j < 50) {
    for (int i = 0; i < prueba.get(j); i++) {
      a.add(i, prueba.get(i));
    }
    cout << a.size() << " ";
    cout << a.waste() << " ";
    cout << a.resizes() << endl;
    a.eliminate();
    j++;
  }
}

int main() {
  // punto1();
  // punto2();
  // punaato3();
  punto4A();

  return 0;
}
