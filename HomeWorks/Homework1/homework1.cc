#include <iostream>
#include <cmath>
//#include <chrono>

using namespace std;
#define endl '\n';  //avoid fflush of cout.
void ban(){
  cout <<" _______   _                 _\n"
       <<"|__   __| (_)               | |\n"
       <<"   | |_ __ _  __ _ _ __  ___| | ___\n"
       <<"   | | '__| |/ _` | '_ \\/ _\\| |/ _ \\\n"
       <<"   | | |  | | (_| | | | | (_| | |__/\n"
       <<"   |_|_|  |_|\\__,_|_||_|\\__,|_|\\___|\n"
       <<"                        __/ |\n"
       <<"                       |___/\n"
       <<"   feedback: hfjimenez@utp.edu.co \n"
       <<"Hack the Gibson,Hack your technolust\n";
}
//  Feedback: hfjimenez@utp.edu.co
//  Hector F. Jimenez Saldarriaga
//  Datastructures Class, Assignment 1.
//  Porpouse: Practice the oop and implement some
//  math functions.
//  Useful links :
//  [1]https://people.richland.edu/james/lecture/m116/matrices/applications.html
//  [2]http://www.mathopenref.com/coordtrianglearea.html
//  Create a quick implementation of chronos, to measure the time of execution.



//Point Class Should let me :
//Represent cartesian coordinates.
//make basic operations between coordinates.
  //Task------State
  //move :    Done
  //print :   Done
  //distance: Done

class Point{
    private:
        double x;
        double y;

    public:
      //This is called famously a constructor.
        Point():x(0.0),y(0.0){}

        Point(double a){
            x=a;
            y=a;}
        //off course can exist multiples constructors,
        //you should need to create destructors too.
        Point(double a, double b){
            x=a;
            y=b;}

        Point(const Point &p){
            //memaddres  of Point cannot be modified
            //initialize from an existing point.
            x=p.x;
            y=p.y;
        }

       void print() const{
        cout<<"("<< x << ","<<y<<")" ;
       }

       double distance(const Point &q) const{
            double dx = x-q.x;
            double dy = y-q.y;
            return sqrt(dx*dx + dy*dy );
       }

       bool sameLine(const Point &q, double m) const {
         double p = (q.y - y) / (q.x - x);
         return p == m;
       }
       void movexy(double mx, double my) {
         x = x + mx;
         y = y + my;
       }
       void movex(double mx){
         x = x + mx;
       }
       void movey(double my){
         y = y + my;
       }

       //from mauricio's explanation seems the most obvious but
       //we solve the problem in group with liz.
       void polares() {
         double dx = x;
         double dy = y;
         x = sqrt(x * dx + dy * dy);
         y = atan(dy / dx);
         y = (y * 180) /M_PI;
         }

      void rotate(double a) {
          y = y + a;
      }

};

//Triangle Class Should let me :
  //TASK              |State
  //Create Triangles.  Done.
  //move Triangle.     Done.
  //find the perimeter.Done
  //find the area.     Done
  //is a triangle a triangle according to the math what type is it ?.
  //print Triangle     Done
  //compare triangles. in progress
  //Rotate triangle    Done.
class Triangle{
private:
  Point p1;
  Point p2;
  Point p3;

public:
  Triangle() : p1(0.0, 0.0), p2(0.0, 0.0), p3(0.0, 0.0) {}

  Triangle(const Point &p, const Point &q, const Point &r)
      : p1(p), p2(q), p3(r) {}

  Triangle(const Triangle &t) : p1(t.p1), p2(t.p2), p3(t.p3) {}

  void print() const {
    cout << "{" ;
    p1.print();
    p2.print();
    p3.print();cout << "}" << endl;
  }

  void movetx(double x){
    p1.movex(x);
    p2.movex(x);
    p3.movex(x);
  }

  void movety(double y){
    p1.movey(y);
    p2.movey(y);
    p3.movey(y);
  }

  double perimeter(){
    return (p1.distance(p2)+p2.distance(p3)+p3.distance(p1));}

  double easyarea(double semi){  //see [2] that was implemented
    double result = sqrt( 0.5*(semi * (semi - p1.distance(p2)) * (semi - p2.distance(p3)) * (semi - p3.distance(p1)) ) );
    return result;
  }
    double area( Triangle &k){   //an object that contains multiples objects can not be mapped ?wtf !
    double s, Area;
    //there're different aproache to calculate the
    //the triangle area, matriz[1], heron.
    s=(k.perimeter())*0.5;
    Area = sqrt ( s *( s- (p1.distance(p2)) ) *( s-(p2.distance(p3)))*( s-(p3.distance(p1))) );
    return Area;
  }

  void polares() {
    p1.polares();
    p2.polares();
    p3.polares();
  }
  // Rota el triángulo
  void rotate(Triangle &k, double p) {
    k.polares();
    p1.rotate(p);
    p2.rotate(p);
    p3.rotate(p);
  }

  void triangletype(const Triangle &y){
    //

  }

  bool compare(const Triangle &c1, const Triangle &c2){

    return 0;
  }

};

int main(){
  ban();
  Point a(1.0, 1.0);
  Point b(4.0, 1.0);
  Point c(4.0, 4.0);
  Triangle x(a, b, c);
  cout<<"[+]The Triangle vertex are : ";
  x.print();
  double perimetro=x.perimeter();
  cout<<"[+]The perimeter is : "<<perimetro<<endl;
  cout<<"[*] The Area of the previous Triangle is "<<x.area(x)<<endl;
  cout<<"[+]Moving in x the Triangle(2): ";
  x.movetx(2);
  x.print();
  cout<<"[+]Moving in y the Triangle(1): ";
  x.movety(1);
  x.print();
  cout << "\nInsert the angle to rotate the Triangle :";
  double grades;  cin>>grades;
  x.rotate(x,grades);
  cout <<"\nAfter the rotation the new coordinates are: "<<endl;
  cout<< "[+] : ";
  x.print();
}
