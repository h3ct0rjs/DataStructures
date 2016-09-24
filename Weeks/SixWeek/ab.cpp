#include "bst.hh"
#include "animals.hh"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  BST<string> zoo;
  vector<string> animals = someAnimals();

  while (animals.size() > 0) {
    size_t p = rand() % animals.size();
    zoo.insert(animals[p]);
    swap(animals[p], animals.back());
    animals.pop_back();
  }
  zoo.print();
  return EXIT_SUCCESS;
}
