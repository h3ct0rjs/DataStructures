#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N ;
int main() {
  int * bigarray = new int[100000];
  for(unsigned int k = 0; k<100000; ++k)
    bigarray[k] = k;
    
  int sum = total(bigarray,100000);
  delete [] bigarray;
  cout<< sum<<endl;

  return 0;
}
