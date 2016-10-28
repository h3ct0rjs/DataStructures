#include "priorityqueue.hh"

int main() {

  Pqueue<int, string> a;
  a.insert(8, "mauros");
  a.insert(1000, "liz");
  a.insert(1, "leidy");
  a.insert(165, "gutavo");
  a.insert(9, "cris");
  a.insert(0, " yo");
  a.print();
  a.remove();
  cout << "borrando..." << endl;
  a.print();
  return 0;
}
