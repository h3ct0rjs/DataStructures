#include "heapmin.hh"

int main() {

  Heapmin<int> a;
  a.insert(8);
  a.insert(1000);
  a.insert(1);
  a.insert(165);
  a.insert(9);
  a.insert(0);
  a.insert(2);
  a.insert(365);
  a.insert(859);
  a.insert(-1);
  a.insert(16);
  a.insert(5);
  a.insert(260);
  a.insert(120);
  a.print();
  cout << " cantidad de elementos del heap " << a.tam() << endl;
  cout << "removiendo" << endl;
  a.remove();
  // cout << " minimo del heap " << a.get() << endl;

  // cout << " cantidad de elementos del heap " << a.tam() << endl;
  // cout << " vacio ?" << a.empty() << endl;
  a.print();
  return 0;
}
