#include "animals.hh"
#include "bst.hh"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {

  BST<string> zoo;
  BST<string> m;

  m.insert("Emanuel");
  m.insert("Byron ");
  m.insert("Liz");
  m.insert("Angelica");
  /*  BST<int> numeros;
    numeros.insert(1);
    numeros.insert(42);
    numeros.insert(37);*/

  vector<string> animals = someAnimals();
  while (animals.size() > 0) {
    int p = rand() % animals.size(); // posicion valida
    zoo.insert(animals[p]);
    swap(animals[p], animals.back()); // intercambiar del vector
    animals.pop_back(); // remover el ultimo elemento del vector de animales
    // lo insertamos en el arbol lo eliminamos del vecto
  }

  /*if (zoo.find("Hector")) {
    cout << " Hallo it Exist" << endl;
  } else {
    cout << "It does't exits !" << endl;
  }
*/
  zoo.print();
  // cout << " size = " << zoo.preOrden() << endl;

  // cout << "iguales? " << zoo.iguales(m) << endl;

  // numeros.print();
  return 0;
}
