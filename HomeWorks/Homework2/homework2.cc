#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define endl '\n';  //avoid fflush of cout.
//  feedback: hfjimenez@utp.edu.co
//  Hector F. Jimenez Saldarriaga
//  Datastructures Class, Assignment 2.
//  Porpouse: implement the nth fibonacci number in O(log n)
//  Useful links :
//  [1]http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormula.html
//  [2]https://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form
//  [3]http://www.lab.dit.upm.es/~lprg/material/apuntes/o/
//  
typedef vector <vector <int>> Matriz;

Matriz Suma(const Matriz &a, const Matriz &b){
if(a.size() != b.size()) return ;               //same technique as  in the gustavo's class.
int filas= a.size();
int cols=a[0].size();
Matriz Resultante(filas,vector<int>(ncols));    //store matriz resultant.
    for(int i=0;i<filas;i++)
       for(int j=0; j<cols;j++)
           Resultante[i][j]=a[i][j]+b[i][j];    //fill the result. Complexity for this is O(n) [3]
    
    return Resultante;                          //return the sum matriz 
}

//Multiplicar matrices se realiza de la forma  fila*columna, y se suma los productos
//Sea Aij, Bmn matrices se pueden multiplicar siempre y cuando:
//  j==m indices.
//  Dara como resultado una Matriz ABin.
// Acontinuacion se implementa
Matriz  Multi(const Matriz& m1, const Matriz& m2) {
    int n = m1.size();
    int m = m1[0].size();
    int p = m2[0].size();
    Matriz Resultado(n, vector<int>(p));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            int sum = 0;
            for (int k = 0; k < m; ++k) {
                sum = sum + a[i][k]*b[k][j];
            }
            Resultado[i][j] = sum;
        }
    }
    return Resultado;
}

void Transponer(Matriz &t){
    for(int i=0;i<(t.size())-1;i++)
        for(int j=i+1;j<t.size();j++)
            swap(t[i][j],t[j][i]);                  //filas, cambio por columnas
}

// Elevar matriz, se puede usar realizando multiplicaciones sucesivas
// epro 
Matriz pow(Matriz a, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return Multi(a, pow(a, p-1));
    Matriz X = pow(a, p/2);
    return Multi(X, X);
}


int main(){


}
