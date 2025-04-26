#include <bits/stdc++.h>
using namespace std;
class Socan7 {
    int a; 
    int b; 
public:    
    //ktao - huy
    Socan7 (int, int);
    ~Socan7();
    //get - set
    int getA();
    void setA(int);
    int getB();
    void setB(int);
    //hotro
    void nhap();
    void xuat() const;
    //ph�p +
    friend Socan7 operator + (const Socan7& p, const Socan7& e){
        return Socan7(p.a + e.a, p.b + e.b);
    }
    //ph�p -
    friend Socan7 operator - (const Socan7& p, const Socan7& e){
        return Socan7(p.a - e.a, p.b - e.b);
    }
    //d?i d?u
    Socan7 operator - () const {
        return Socan7(-a, -b);
    }
    //ph�p * 
    /*
    p = a + bv7
    e = c + dv7
    p * e = (a + bv7)(c + dv7) = (ac + 7bd) + (ad + bc)v7
    */
    friend Socan7 operator * (const Socan7& p, const Socan7& e) { 
    int new_a = p.a * e.a + 7 * p.b * e.b;
    int new_b = p.a * e.b + p.b * e.a;
    return Socan7(new_a, new_b);
    }
};
Socan7 :: Socan7 (int x = 0, int y = 0){
    a = x;
    b = y;
}
Socan7 :: ~Socan7(){}
int Socan7 :: getA(){
    return a;
}
void Socan7 :: setA(int t){
    a = t;
}
int Socan7 :: getB(){
    return b;
}
void Socan7 :: setB(int t){
    b = t;
}
void Socan7 :: nhap(){
    cin >> a;
    cin >> b;
}
void Socan7 :: xuat() const {
    if (b == 0){
        cout << a << endl;
    }else if (a == 0){
        cout << b << "v7" << endl;
    }else if (b > 0){
        cout << a << "+" << b << "v7" << endl;
    }else {
        cout << a << b << "v7" << endl;
    }
}

int main (){
    Socan7 x, y;
    x.nhap();
    y.nhap();
    x.xuat();
    y.xuat();
    (x + y).xuat();
    (x - y).xuat();
    (x * y).xuat();
    (-x).xuat();
    (-y).xuat();
    Socan7 c(1, 3);
    c.xuat();
    Socan7 d;
    d.xuat();
    return 0;
}
