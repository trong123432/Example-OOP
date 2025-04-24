#include <iostream>
using namespace std;

template <typename T>
class Array {
    int size;
    int capacity;
    T* data;
public:
    Array(int _size = 0, T defaultValue = T()) {
        size = _size;
        capacity = size;
        if (size!=0) {
            data = new T[size];
            for (int i = 0; i < size; i++)
                data[i] = defaultValue;
        } else {
            data = nullptr;
        }
    }
    Array(const Array<T>& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    ~Array() {
        delete[] data;
    }
    void pushBack(T val) {
        if (size==capacity) {
            int newCapacity = capacity==0?1:capacity*2;
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; i++)
                newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size++] = val;
    }
    int getSize(){return size;}
    void setSize(int newSize) {
        if (newSize==size || newSize<0)
            return;
        if (newSize>capacity)
            capacity = newSize * 2;
        T* newData = new T[capacity];
        if (newSize<size)
            for (int i = 0; i < newSize; i++)
                newData[i] = data[i];
        else
            for (int i = 0; i < newSize; i++) {
                if (i < size)
                    newData[i] = data[i];
                else
                    newData[i] = T();
            }
        delete[] data;
        data = newData;
        size = newSize;
    }
    void add(T val, int index) {
        if (index<0 || index>size)
            return;
        if (size==capacity) {
            int newCapacity = capacity==0?1:capacity*2;
            T* newData = new T[newCapacity];
            for (int i = 0; i < index; i++)
                newData[i] = data[i];
            for (int i = size; i > index; i--)
                newData[i] = data[i-1];
            delete[] data;
            data = newData;
            capacity = newCapacity;
        } else {
            for (int i = size; i > index; i--)
                data[i] = data[i-1];
        }

        size++;
        data[index] = val;
    }
    void remove(int index) {
        if (index<0 || index >= size)
            return;
        for (int i = 0; i < size; i++) {
            if (i<index)
                data[i] = data[i];
            else
                data[i] = data[i+1];
        }
        size--;
        data[size] = T();
    }
    void sort() {
        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                if (data[i]>data[j]) {
                    T temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }
    T min() {
        T minVal = data[0];
        for (int i = 1; i < size; i++)
            if (data[i]<minVal)
                minVal = data[i];
        return minVal;
    }
    T sum() {
        T s = T();
        for (int i = 0; i < size; i++)
            s = s + data[i];
        return s;
    }
    T& operator[](int index) {return data[index];}
    friend istream& operator>>(istream& is, Array<T>& param) {
        delete[] param.data;
        T temp;
        while (is>>temp)
            param.pushBack(temp);
        return is;
    }
    friend ostream& operator<<(ostream& os, Array<T> param) {
        for (int i = 0; i < param.getSize(); i++)
            os << param[i] << " ";
        return os;
    }
    Array& operator=(const Array<T>& other) {
        if (this==&other)
            return *this;
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
        return *this;
    }
};

int main() {
    Array<int> a;
    cin >> a;
    cout << "mang a :" << endl;
    cout << "mang ban dau: " << a << endl;
    a.sort();
    cout << "sau khi sort: " << a << endl;
    cout << "minimum: " << a.min() << endl;
    cout << "total: " << a.sum() << endl;
    Array<int> b(5, 10);
    cout << "mang b:" << endl;
    cout << "mang ban dau: " << b << endl;
    b.add(213, 3);
    cout << "mang sau khi add: " << b << endl;
    b.remove(2);
    cout << "mang sau khi remove: " << b << endl;
    return 0;
}