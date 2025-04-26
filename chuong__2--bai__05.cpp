#include <iostream>
#include <cmath>
using namespace std;

struct point2D {
    int x;
    int y;
};

float lineLength(point2D a, point2D b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

class triangle {
    point2D a;
    point2D b;
    point2D c;
public:
    triangle() {
        a.x = 0;
        a.y = 0;
        b.x = 0;
        b.y = 0;
        c.x = 0;
        c.y = 0;
    }
    triangle(int ax, int ay, int bx, int by, int cx, int cy) {
        a.x = ax;
        a.y = ay;
        b.x = bx;
        b.y = by;
        c.x = cx;
        c.y = cy;
    }
    void print() {
        cout << "A(" << a.x << ", " << a.y << "), ";
        cout << "B(" << b.x << ", " << b.y << "), ";
        cout << "C(" << c.x << ", " << c.y << ")" << endl;
    }
    void setTriangle(int ax, int ay, int bx, int by, int cx, int cy) {
        a.x = ax;
        a.y = ay;
        b.x = bx;
        b.y = by;
        c.x = cx;
        c.y = cy;
    }
    float calPerimeter() {
        float A = lineLength(b, c);
        float B = lineLength(a, c);
        float C = lineLength(a, b);
        return A + B + C;
    }
    float calArea() {
        float A = lineLength(b, c);
        float B = lineLength(a, c);
        float C = lineLength(a, b);
        float p = calPerimeter()/2;
        return sqrt(p*(p-A)*(p-B)*(p-C)/A) * A * 0.5;
    }
    int distribute() {
        float A = round(lineLength(b, c) * 100)/100;
        float B = round(lineLength(a, c) * 100)/100;
        float C = round(lineLength(a, b) * 100)/100;
        bool square1 = fabs((A*A - B*B - C*C)) < 1e-6;
        bool square2 = fabs((B*B - A*A - C*C)) < 1e-6;
        bool square3 = fabs((C*C - A*A - B*B)) < 1e-6;
        bool isosceles = (A == B) || (B == C) || (C == A);
        bool even = (A == B) && (B == C);
        if (even) return 4;
        else if ((square1||square2||square3) && isosceles) return 3;
        else if (isosceles) return 2;
        else if (square1 || square2 || square3) return 1;
        else return 0;
    }
};

int main() {
    triangle* ABC = new triangle(3, 1, 5, 2, 7, 6);
    cout << "after" << endl;
    ABC->print();
    ABC->setTriangle(0, 0, 4, 0, 2, 3);
    cout << "before" << endl;
    ABC->print();
    cout << "perimeter = " << ABC->calPerimeter() << endl;
    cout << "area = " << ABC->calArea() << endl;
    cout << "the triangle : " << ABC->distribute();
    return 0;
}