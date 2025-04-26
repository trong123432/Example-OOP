#include <iostream>
#include <cmath>
using namespace std;

class polynomial {
    int n;
    int* data;
public:
    polynomial(int _n = 0, int val = 0) {
        n = _n;
        if (n!=0) {
            data = new int[n];
            for (int i = 0; i <= n; i++)
                data[i] = val;
        }
    }
    // ~polynomial() {
    //     delete[] data;
    // }
    friend istream& operator>>(istream& is, polynomial& arg) {
        for (int i = 0; i <= arg.n; i++)
            is >> arg.data[i];
        return is;
    }
    friend ostream& operator<<(ostream& os, polynomial arg) {
        bool flag = 0;
        for (int i = arg.n; i >= 0; i--) {
            if (arg.data[i]==0) continue;
            if (flag) os << "+";
            flag = 1;
            if (i==0) os << arg.data[i];
            else if (i==1 && arg.data[i]!=1) os << arg.data[i] << "x";
            else if (i==1 && arg.data[i]==1) os << "x";
            else if (i!=1 && arg.data[i]==1) os << "x^" << i;
            else os << arg.data[i] << "x^" << i;
        }
        return os;
    }
    void input() {
        for (int i = 0; i <= n; i++)
            cin >> data[i];
    }
    void print() {
        bool flag = 0;
        for (int i = n; i >= 0; i--) {
            if (data[i]==0) continue;
            if (flag) cout << "+";
            flag = 1;
            if (i==0) cout << data[i];
            else if (i==1 && data[i]!=1) cout << data[i] << "x";
            else if (i==1 && data[i]==1) cout << "x";
            else if (i!=1 && data[i]==1) cout << "x^" << i;
            else cout << data[i] << "x^" << i;
        }
    }
    int calculate(int val) {
        int result = 0;
        for (int i = 0; i <= n; i++)
            result += (int)pow(val, i) * data[i];
        return result;
    }
    friend polynomial operator+(polynomial arg_1, polynomial arg_2) {
        polynomial result(arg_1.n>arg_2.n?arg_1.n:arg_2.n);
        for (int i = 0; i <= result.n; i++) {
            if (i <= (arg_1.n<arg_2.n?arg_1.n:arg_2.n))
                result.data[i] = arg_1.data[i] + arg_2.data[i];
            else
                result.data[i] = (arg_1.n>arg_2.n?arg_1.data[i]:arg_2.data[i]);
        }
        return result;
    }
    friend polynomial operator-(polynomial arg_1, polynomial arg_2) {
        for (int i = 0; i <= arg_2.n; i++)
            arg_2.data[i] = -arg_2.data[i];
        return arg_1 + arg_2;
    }
    friend polynomial operator*(polynomial arg_1, polynomial arg_2) {
        polynomial result(arg_1.n+arg_2.n);
        for (int i = 0; i <= arg_1.n; i++) {
            for (int j = 0; j <= arg_2.n; j++) {
                result.data[i+j] += (arg_1.data[i] * arg_2.data[j]);
            }
        }
        return result;
    }
    int& operator[](int index) {
        return data[index];
    }
    polynomial operator++() {
        polynomial result(this->n + 1);
        result[0] = 0;
        for (int i = 1; i <= result.n; i++)
            result[i] = this->data[i-1];
        return result;
    }
    polynomial operator--() {
        polynomial result(this->n - 1);
        result[0] = this->data[0] + this->data[1];
        for (int i = 1; i < result.n; i++) {
            result[i] = this->data[i+1];
        }
        return result;
    }
    polynomial derivative() {
        polynomial result(n - 1);
        for (int i = 0; i <= result.n; i++)
            result.data[i] = data[i+1] * (i+1);
        return result;
    }
    polynomial primative() {
        polynomial result(n+1);
        for (int i = 1; i <= result.n; i++) {
            if (i-1==0 && data[i-1]==0)
                result[0] = 0;
            else
                result[i] = data[i-1]/i;
        }
        return result;
    }
    double integral(double a, double b) {
        return primative().calculate(b) - primative().calculate(a);
    }
};

int main() {
    int n;
    cin >> n;
    polynomial fx(n);
    cin >> fx;
    cout << fx << endl;
    cout << fx.primative() << endl;
    cout << fx.integral(1, 2);

    // cout << fx.derivative();
    // int m;
    // cin >> m;
    // polynomial gx(m);
    // cin >> gx;
    // cout << gx << endl;
    // cout << fx - gx;
    return 0;
}