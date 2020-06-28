#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
class mySet
{
private:
    vector<T> m_ele;

public:
    mySet() = default;
    mySet(const vector<T> &elem) : m_ele(elem) { }
    mySet(const mySet<T> &r) : m_ele(r.m_ele) { }
    ~mySet() { vector<T>().swap(m_ele); }
    mySet &operator=(const mySet<T> &rhs) { this->m_ele = rhs.m_ele; }
    bool is_elem(const T elem) const {
        for (int i = 0; i < m_ele.size(); i++) {
            if (m_ele[i] == elem) {
                return true;
            }
        }
        return false;
    }
    
    void insert(T elem) {
        int i;
        for (i = 0; i < m_ele.size(); i++) {
            if (elem == m_ele[i]) {
                break;
            }
        }
        if (i == m_ele.size())
            m_ele.push_back(elem);
    }

    void erase(T elem) {
        for(auto it = m_ele.begin(); it != m_ele.end(); it++)
        {
            if (*it == elem) {
                m_ele.erase(it);
                break;
            }
        }
    }

    void clear() {
        m_ele.clear();
    }

    int getcount() const {
        return m_ele.size();
    }
    
    mySet tintersection(const mySet<T> &rhs) {
        map<T,int> d;
        for (int i = 0; i < this->m_ele.size(); i++) {
            d[m_ele[i]] = d[m_ele[i]] + 1;
        }
        for (int i = 0; i < rhs.m_ele.size(); i++) {
            d[rhs.m_ele[i]] = d[rhs.m_ele[i]] + 1;
        }

        vector<T> v;
        for (auto it = d.begin(); it != d.end(); it++) {
            if (it->second > 1) {
                v.push_back(it->first);
            }
        }
        return mySet(v);
    }

    mySet tunion(const mySet &rhs) const {
        mySet ret(*this);
        for (int i = 0; i < rhs.m_ele.size(); i++) {
            ret.insert(rhs.m_ele[i]);
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const mySet<T> &rhs)
    {
        os << "(";
        for (int i = 0; i < rhs.m_ele.size(); i++) {
            os << rhs.m_ele[i];
            if (i + 1 != rhs.m_ele.size())
                os << ",";
        }
        os << ")\n";
        return os;
    }
};

int main()
{
    mySet<int> s;
    mySet<int> s1;
    s.insert(9);
    s.insert(6);
    s.insert(0);
    s.insert(4);
    s1.insert(8);
    s1.insert(9);
    s1.insert(5);
    cout << "集合s:" << s;
    cout << "集合s1:" << s1;
    
    cout << "集合s的元素个数:" << s.getcount() << endl;

    cout << "交集：" << s.tintersection(s1) << "并集：" << s.tunion(s1);
  
}