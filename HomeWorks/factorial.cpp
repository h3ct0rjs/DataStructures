#include <chrono>
#include <iostream>

using namespace std;

double fact(double n) {
  if (n <= 1)
    return 1;
  return n * fact(n - 1);
}

int main() {
  cout << "Factorial" << endl;
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();
  fact(1000);
  end = chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end - start;
  cout << "time: " << elapsed_seconds.count() << "s\n";

}
