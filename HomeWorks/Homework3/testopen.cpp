#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    int c=0;
    while ( getline (myfile,line) )
    {
       //istringstream iss(line);
      cout << line <<" "<< c<< '\n';
      c++;
    }
    myfile.close();
  }

  else cout << "Unable to open file";
  return 0;
}
