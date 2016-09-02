#include <iostream>
#include <chrono>
#include <ctime>
using namespace std; 

int fact(unsigned n)
{
    if (n <=1) return n;
   return n* fact(n -1 );
}
 
int main()
{
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    cout << "f(42) = " << fact(5) << '\n';
    end = chrono::system_clock::now();
 
    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);
 
    cout << "finished computation at " << ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
