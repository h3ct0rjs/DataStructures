#include "vector.hh"
#include <iostream>

using namespace std;
int main() {
  cout << "Vectors!!!" << endl;
  Vector<int> v;
  for (int i = 0; i < 1000; i++) {
    v.add(i, -i);
    // cout << v.get(i) << endl;
  }
  cout << "Waste: " << v.waste() << endl;
  cout << "Resizes: " << v.resizes() << endl;
  return 0;
}
