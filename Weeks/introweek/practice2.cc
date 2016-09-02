#include <iostream> 
#include <cmath>
using namespace std;
//Homeworks and ToDo's :
//Read about c++ oop: **Done** 
//What is the best way to access public and private, protected. 
//Mathematical Background 1.3.1-1.3.2::Exaustiva.
//1.3.3 Informativa.

/*
typedef struct{
	int x;
	int y;

}Point
*/

class Point{ 
	private:
		int x;
		int y;
  public: 
		Point(){        //This is called a constructor without argument
        x=0;
        y=0;
        } 
        Point(int a,int b){
            x=a;
            y=b;
        }
		
        void print(){
		cout<< "("<<x <<","<<y<<")" <<endl; 
        } 

        //method to calculate distance
        double distance(const Point &q){    //Referencing an object
            return(sqrt(((x-q.x)*(x-q.x))+((y-q.y)*(y-q.y))));
        
        }

        //method to determine if a x point is in the same line .
        bool sameline(const Point &q,double m){
           double mcalc= (q.y - y)/(q.x - x);
           return mcalc==m;
        }

        void move(double mx, double my){
        
        }

};


class Triangle{
private: 
    Point p1;
    Point p2 ;
    Point p3;
public :
    Triangle():    p1(0.0,0.0),p2(0.0,0.0),p3(0.0,0.0){}
    Triangle(const Point &p,const Point &q,const Point &r )
        :p1(p), p2(q),p3(r){}
};

int main(){
Point p;	//This will create and object. 

return 0;		//For the case, it's just too important in the main. Please 	 
}
