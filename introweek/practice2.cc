#include <iostream> 
using namespace std;
//Homeworks and ToDo's :
//Read about c++ oop
//What is the best way to access public and private, protected. 
//Mathematical Background 1.3.1-1.3.2::Exaustiva.
//1.3.3 Informativa.

/*
typedef struct{
	int x;
	int y;

}Point;
*/

class Point{ 
	private:
		int x;
		int y;
  public: 
		
		void print(){
		cout<< "("<<x <<","<<y<<")" <<endl; }

};

int main(){
Point p;		//This will create and object. 
Point line[4];//Four Objects
for(int i=0;i<4;i++){
		line[i].x=i*i;
		line[i].y=i+10;
}

return 0;		//For the case, it's just too important in the main. Please 	
}
