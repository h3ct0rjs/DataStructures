
#include "vect.hh" //incluir los metodos y las clases que estan en el archivo v.hh
#include <iostream>

using namespace std;

int main() {
  Vector<int> prueba = produce(100, 10000, 100000);
  cout << "Random Values=100";
  cout << "Normal Distribution Parameters"<<endl;
  cout << "s=200,l=50000,u=1000000"<<endl;
  cout<<"\t"<<"Array"<<"\tVector"<<endl;
  for (int i = 0; i < 100; i++) {
    cout<< i <<" ";
    cout << prueba.get(i);
    cout <<"\n" <<endl;
    for(int j=0;j<100;j++){
      cout<<"t"<<j<<"\t";
    testArray(prueba.get(i));
    cout<< "\t";
    testVector(prueba.get(i));
      cout << endl;
  }

  }
  return 0;
}
