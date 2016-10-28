#include "list.h"
#include <iostream>
#include <string> //es una liberia permite ver cadenas
using namespace std;
int main() {
  List<string> phrase;
  phrase.append("hakuna");
  phrase.append("matata");
  phrase.print();
  List<char> word;
  cout << word.size() << endl;
  word.add(0, 'h');
  word.add(1, 'o');
  word.add(2, 'l');
  word.add(3, 'a');
  cout << word.size() << endl;
  word.print();
  List<char> word2;
  cout << word.size() << endl;
  word2.append('h');
  word2.append('o');
  word2.append('l');
  word2.append('a');
  cout << word2.size() << endl;
  word2.print();
  return 0;
}
