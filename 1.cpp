#include <iostream>
using namespace std;

class figure
{
protected:
    double m_x, m_y;

public:
    void set_dim(double i, double j = 0)
    {
        m_x = i;
        m_y = j;
    }
    virtual void area()
    { //定义area()为虚函数
        cout << "该类没有面积计算实现\n";
    }
};
class triangle : public figure
{
public:
    void area() // 在派生类中重写area()函数
    {
        cout << "高和底分别为" << m_x << "和" << m_y << "的三角形面积为:" << 0.5 * m_x * m_y << endl;
    }
};
class square : public figure
{
public:
    void area() // 在派生类中重写area()函数
    {
        cout << "长和宽分别为" << m_x << "和" << m_y << "的矩形面积为:" << m_x * m_y << endl;
    }
};

int main()
{

    figure *p, *q; //定义一个基类指针

    p = new triangle; //基类指针指向派生类对象
    p->set_dim(10.0, 5.0);
    p->area();
    q = new square();
    q->set_dim(10.0, 5.0);
    q->area();


    delete p;
    delete q;
    return 0;
}