#include <iostream> 
using namespace std;

typedef struct{
	int x;
	int y;

}Point;

int  ident(int *n, int *m) {
	cout << "Memaddress n: "<< &n<<endl;
	cout << "Value of n inside function: "<<*n<<endl;
	*n=8;		//If you know the memadddress
	return *n+*m;
}



int main(){
	
	Point p;
	p.x=0;
	p.y=10;
	cout << "Memaddress of an struct: "<<&p<<endl;
	cout << "Memaddress of p.x "<<&p.x<<endl;
	cout << "Memaddress of p.x "<<&p.y<<endl;
	//It is posible to create a pointer to an struct
	// and it looks like this :
	Point *ptr=&p;
	//you can change the value of the variable 
	
	(*ptr).x=42;  //This things are the same thing.
	ptr->y=100;		//-> operator 

	cout << "Value of p.x: "<<p.x<<endl;
	cout << "Value of p.y: "<<p.y<<endl;
	//Second Test. 
	/*				
	int x=10;
	int y=100 ;
	int r=ident(&x,&y);
	cout << "Value of r: "<<r<< endl;	*/
/*//First Test
cout << "Pointers!"<<endl;
double pi = 3.1415;
int p;
cout <<"Memory Address pi: " << &pi <<endl ;
cout << "Memory Address p: " << &p << endl ;
int *ptr;  //This will create an int Pointer.
cout <<"Memory Address, Pointer: "<< &ptr<<endl;
ptr=&p;    //Assign the memaddress of variable p to ptr.
cout <<"Content of  Pointer: "<< ptr<<endl;
*ptr=10;  //Yay we can modify the pointer :) 
cout <<"Content of Pointer: "<<*ptr<<endl;
*/
return 0;		//For the case, it's just too important in the main. Please 	
}
