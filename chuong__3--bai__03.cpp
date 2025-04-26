#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Array {
protected:
    int m_sopt;
    int m_data[100];
public:
    Array(int sopt = -1, int defaultValue = 0) {
        m_sopt = sopt;
        for (int i = 0; i < m_sopt; i++)
            m_data[i] = defaultValue;
    }

    int getSopt(){return m_sopt;}
    void setSopt(int sopt) {
        if (sopt==m_sopt || sopt<0)
            return;
        m_sopt = sopt;
    }

    void input() {
        cin >> *this;
    }
    void output() {
        cout << *this << endl;
    }

    friend istream& operator>>(istream& is, Array& param) {
        param.m_sopt = 0;
        int temp;
        while (is>>temp)
            param.m_data[param.m_sopt++] = temp;
        return is;
    }
    friend ostream& operator<<(ostream& os, Array param) {
        for (int i = 0; i < param.m_sopt; i++)
            os << param.m_data[i] << " ";
        return os;
    }
    int& operator[](int index) {
        return m_data[index];
    }
};

class Stack : public Array {
public:
    Stack(int sopt = -1, int defaultValue = 0) : Array(sopt, defaultValue) {
        cout << "Stack is constructed\n";
    }
    ~Stack() {
        cout << "Stack is destructed";
    }
    bool isEmpty() {
        return m_sopt==-1?1:0;
    }
    void push(int val) {
        if (isEmpty())
            m_sopt = 0;
        m_data[m_sopt] = val;
        m_sopt++;
    }
    int pop() {
        if (!isEmpty()) {
            m_sopt--;
            return m_data[m_sopt];
        }
    }
};

class Binary : public Stack {
public:
    Binary(int sopt = -1, int defaultValue = 0) : Stack(sopt, defaultValue) {
        cout << "It's used translate binary\n";
    }
    ~Binary() {
        cout << "Binary is destructed. ";
    }
    string translateBinary(int n) {
        if (n==0)
            return "0";
        string result;
        while (n!=0) {
            push(n%2);
            n /= 2;
        }
        while (m_sopt!=0)
            result += to_string(pop());
        return result;
    }
};

int main() {
    Stack st;
    int temp;
    while (cin>>temp)
        st.push(temp);
    Binary proccessor;
    for (int i = 0; i < st.getSopt(); i++)
        cout << proccessor.translateBinary(st[i]) << " ";
    return 0;
}