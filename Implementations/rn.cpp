#include "animals.hh"
#include "RBTs/RBT.hh"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  RBT<string> zoo;
  vector<string> animals = someAnimals();
  /*
    for (int i = 0; i < animals.size(); i++) {
      zoo.insert(animals[i]);
    }
    */
  while (animals.size() > 0) {
    int p = rand() % animals.size();
    zoo.insert(animals[p]);
    swap(animals[p], animals.back());
    animals.pop_back();
  }

  // cout << zoo.size() << endl;
  zoo.inorder();
  zoo.print();
  ;
  // cout << zoo.size() << endl;
  return EXIT_SUCCESS;
}
