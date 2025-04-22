#include <iostream>
#include <cmath>
using namespace std;

struct point {
    int x;
    int y;
};

class line {
private:
    point A;
    point B;
public:
    line() {
        A.x = 0;
        A.y = 0;
        B.x = 0;
        B.y = 0;
    }
    line(int a1, int a2, int b1, int b2) {
        A.x = a1;
        A.y = a2;
        B.x = b1;
        B.y = b2;
    }
    ~line() {
        cout << "The Line is deleted" << endl;
    }
    void setLine(int a1, int a2, int b1, int b2) {
        A.x = a1;
        A.y = a2;
        B.x = b1;
        B.y = b2;
    }
    float calculateLength() {
        return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
    }
    void print() {
        cout << "Point A(" << A.x << "," << A.y << ")" << endl;
        cout << "Point B(" << B.x << "," << B.y << ")" << endl;
        cout << "Length = " << calculateLength() << endl;
    }
    void lineFunction() {
        cout << "(x - " << A.x << ")/" << B.x - A.x << " = " << "(y - " << A.y << ")/" << B.y - A.y << endl;
    }
};

int main(){
    line* d = new line;
    d->setLine(2, 3, 1, 4);
    d->calculateLength();
    cout << "infomation of line : " << endl;
    d->print();
    cout << "the line function is : ";
    d->lineFunction();
    return 0;
}