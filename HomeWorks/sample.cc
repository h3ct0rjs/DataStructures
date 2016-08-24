#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

class Point {
private:
  double x;
  double y;

public:
  Point() : x(0.0), y(0.0) {}
  Point(double a, double b) {
    x = a;
    y = b;
  }

  Point(double c) {
    x = c;
    y = c;
  }
  Point(const Point &p) {
    x = p.x;
    y = p.y;
  }
  void print() const {
    // Imprime el punto en pantalla
    cout << "(" << x << "," << y << ")" << endl;
  }
  double distance(const Point &q) const {
    double dx = x - q.x;
    double dy = y - q.y;
    return sqrt(dx * dx + dy * dy);
  }
  bool sameLine(const Point &q, double m) const {
    double p = (q.y - y) / (q.x - x);
    return p == m;
  }
  void move(double mx, double my) {
    x = x + mx;
    y = y + my;
  }
};

class Triangle {
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
    cout << "{" << endl;
    p1.print();
    p2.print();
    p3.print();
    cout << "}" << endl;
  }
};

int main() {
  Point a(1.0, 1.0);
  Point b(1.0, 5.0);
  Point c(3.0, 4.0);
  Triangle t(a, b, c);
  t.print();

  return 0;
}
