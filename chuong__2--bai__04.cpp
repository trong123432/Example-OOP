#include <bits/stdc++.h>
using namespace std;
class Point {
    int x, y;
public:
    //ktao - huy
    Point (int , int);
    ~Point ();
    //get - set
    int getX();
    void setX(int);
    int getY();
    void setY(int);
    //ho tro
    void Set (int x, int y);
};
Point :: Point(int a = 0, int b = 0){
    x = a;
    y = b;
}
Point :: ~Point(){}
int Point :: getX() { 
    return x; 
}
void Point :: setX(int t)  { 
    x = t; 
}
int Point :: getY() { 
    return y;
}
void Point :: setY(int t) { 
    y = t;
}


class Line {
    Point A, B;
public:
    //ktao - huy
    Line(int , int , int , int );
    ~Line();
    //get - set
    Point getA();
    void setA(Point);
    Point getB();
    void setB(Point);
    //ho tro
    void set(int, int, int, int);
    float tinhDoDai (); // d = can b?c 2 ((x2 - x1)^2 + (y2 - y1)^2)
    void Print();
    void xuatPhuongTrinh(); /*
                                ax+by+c=0:
                                    a = y2 - y1
                                    b = x1 - x2
                                    c = x1*y2 - y1*x2
                            */
};
Line :: Line(int a1 = 0, int a2 = 0, int b1 = 0, int b2 = 0) {
        A.setX(a1);
        A.setY(a2);
        B.setX(b1);
        B.setY(b2);
}
Line :: ~Line(){}
Point Line :: getA () {
    return A;
}
void Line :: setA (Point t) {
    A = t;
}
Point Line :: getB () {
    return B;
}
void Line :: setB (Point t) {
    B = t;
}
void Line :: set(int x1, int y1, int x2, int y2){
    A.setX (x1);
    A.setY (y1);
    B.setX (x2);
    B.setY (y2);
}
float Line :: tinhDoDai (){
    return sqrt(pow(B.getX() - A.getX(), 2) + pow(B.getY() - A.getY(), 2));
}
void Line :: Print(){
    cout << "Diem A(" << A.getX() << "; " << A.getY() << ")" << endl;
    cout << "Diem B(" << B.getX() << "; " << B.getY() << ")" << endl;
}
void Line :: xuatPhuongTrinh(){
    int a, b, c;
    a = B.getY() - A.getY();
    b = A.getX() - B.getX();
    c = A.getX() * B.getY() - A.getY() * B.getX();
    cout << "Phuong trinh duong thang: "<< a << "x + " << b << "y + " << c << " = 0" << endl;
}
int main () {
    int z, x, c, v;
    cin >> z >> x >> c >> v;
    Line a;
    a.set(1, 7, 4, 6);
    a.Print ();
    cout << "Do dai doan thang AB la: " << a.tinhDoDai () << endl;
    a.xuatPhuongTrinh();
    Line b;
    b.set(z, x, c, v);
    b.Print ();
    cout << "Do dai doan thang AB la: " << b.tinhDoDai () << endl;
    b.xuatPhuongTrinh();
    Line t;
    t.Print();
    cout << "Do dai doan thang AB la: " << t.tinhDoDai () << endl;
    t.xuatPhuongTrinh();
    return 0;
}
