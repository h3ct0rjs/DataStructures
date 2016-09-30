#include "xbst.hh"
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
  if(zoo.find("Ape")) cout<<"Found Request!"<<endl;
  else cout <<"Bad Request"<<endl;
  return EXIT_SUCCESS;
}
