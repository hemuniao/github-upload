#include <iostream>

using namespace std;

template <class T>
class Calculator
{
private:
    T a;
public:
    Calculator() : a(0) {}
    Calculator(T a) : a(a) {}
    //重载+运算符
    T operator+(Calculator<T>& rhs) const
    {
        return this->a + rhs.a;
    }
    //重载-运算符
    T operator-(Calculator<T>& rhs) const
    {
        return this->a - rhs.a;
    }
    //重载*运算符
    T operator*(Calculator<T>& rhs) const
    {
        return this->a * rhs.a;
    }
    //重载/运算符
    T operator/(Calculator<T>& rhs) const
    {
        return this->a / rhs.a;
    }
    //重载输入>>运算符
    friend istream& operator>>(istream& in, Calculator<T>& rhs)
    {
        in >> rhs.a;
        return in;
    }
    //重载输出<<运算符
    friend ostream& operator<<(ostream& out, const Calculator<T>& rhs)
    {
        out << rhs.a;
        return out;
    }
};

int main()
{
    Calculator<int> a(20), b(30), c, d, e, f;
    Calculator<double> g, h(5.5), i, j, k, l;
    cin >> g;
    c = a + b;
    d = a - b;
    e = a * b;
    f = a / b;
    i = g + h;
    j = g - h;
    k = g * h;
    l = g / h;
    cout <<"e ="<< e << endl;
}