#include <iostream>
#include <math.h>
using namespace std;

class TamGiac {
protected:
    float a, b, c;

public:
    TamGiac(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    bool kiemtratamgiac() {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    float tinhchuvi() {
        if (!kiemtratamgiac()) {
            cout << "Cac canh khong tao thanh tam giac hop le!" << endl;
            return -1;
        }
        return a + b + c;
    }

    float tinhdientich() {
        if (!kiemtratamgiac()) {
            cout << "Cac canh khong tao thanh tam giac hop le!" << endl;
            return -1;
        }
        float p = tinhchuvi() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void print() {
        cout << "Canh a: " << a << ", canh b: " << b << ", canh c: " << c << endl;
    }
};

class TamGiacDeu : public TamGiac {
public:
    TamGiacDeu(float canh) : TamGiac(canh, canh, canh) {
    }

    void set(float canh) {
        a = b = c = canh;
    }

    void print() {
        cout << "Tam giac deu co canh: " << endl;
        TamGiac::print();
        float chuvi = tinhchuvi();
        if (chuvi != -1) {
            cout << "Chu vi: " << chuvi << endl;
        }
        float dientich = tinhdientich();
        if (dientich != -1) {
            cout << "Dien tich: " << dientich << endl;
        }
    }
};

int main() {
    TamGiacDeu m(5);
    m.print();
    return 0;
}
