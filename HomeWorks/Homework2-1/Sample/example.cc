#include <iostream>
#include "timer.hh"

using namespace std;

double fib(int n) {
  if (n <= 2) return 1;
  return fib(n - 1) + fib(n - 2);
}
void test(int n) {
  Timer f("fibonacci");
  fib(n);
}

int main() {
  cout << "Timer example" << endl;
  test(45);
  return 0;
}