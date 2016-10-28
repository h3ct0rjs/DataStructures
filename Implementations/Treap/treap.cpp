#include "treap.hh"

int main() {
  Treap<int> a;
  a.insert(45);
  a.insert(67);
  a.insert(89);
  a.insert(100);
  a.insert(2);
  a.insert(12);
  a.insert(220);
  a.remove(45);
  // a.remove(12);
  // a.remove(2);
  // a.remove(100);
  // a.remove(89);
  // a.remove(67);
  // cout << a.size() << endl;
  a.preOrder();
}
