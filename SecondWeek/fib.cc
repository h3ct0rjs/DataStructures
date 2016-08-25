#include <iostream>
#include <chrono> 
//hfjimenez@utp.edu.co 
//Fibonacci
//
using namespace std ;

int fibRec(int n){
    if (n<= 2)
            return 1;
    else
        return( fibRec(n-1) +fibRec(n-2));

}

 long long fibFor(long long  n){
long long  fib[n];  
fib[ 0 ] = 0;  //1  
fib[ 1 ] = 1;  //1
for (int i = 2; i <= n; ) { //1 ,n veces 
        fib[i] = fib[i - 1] + fib[i - 2];    
        i++;
}   
return fib[n];
}

long long fig
int main(){
    cout<<"Fibonacci "<<endl;
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    int r= fibFor(3);
    cout<< r<< endl ;
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "time: " << elapsed_seconds.count() << "s\n";
    cout << "Second Chance " <<endl;
    int r2= fibFor(10);
    cout<< r2<< endl ;
    return 0;
}
