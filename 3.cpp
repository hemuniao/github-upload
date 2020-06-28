#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
struct Less {
public:
    bool operator()(const T &a, const T &b) { return a < b; }
};

template <typename T>
struct Greater {
public:
    bool operator()(const T &a, const T &b) { return a > b; }
};

template <typename T>
class myVector {
private:
    int m_capacity;
    int m_size;
public:
    T *m_ele;

    myVector() : m_ele(nullptr), m_size(0), m_capacity(0) {}
    myVector(int N) {
        this->m_ele = new T[N];
        m_size = 0;
        m_capacity = N;
    }
    
    ~myVector() { delete[] m_ele; }; //析构函数

    myVector(const myVector &rhs)
    : m_size(rhs.m_size), m_capacity(rhs.m_capacity) {
        m_ele = new T[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_ele[i] = rhs.m_ele[i];
        }
    }
    myVector(myVector &&rhs)
    : m_size(rhs.m_size), m_capacity(rhs.m_capacity), m_ele(rhs.m_ele) {
        rhs.m_capacity = 0;
        rhs.m_size = 0;
        rhs.m_ele = nullptr;
    }

    // //采用二分查找法在容器中查找元素value，查找成功返回pos,失败返回-1
    int binary_search(const T &value, int left, int right) {
        bubbleSort();
        int ret = -1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (m_ele[mid] == value) {
                ret = mid;
                break;
            }
            else if (m_ele[mid] < value) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ret;
    }
    
    bool erase(T elem) {
        bool ret = false;
        int i, j;
        for (i = 0; i < this->m_size; i++) {
            if (m_ele[i] == elem) {
                ret = true;
                break;
            }
        }
        for (j = i + 1; j < this->m_size; j++, i++) {
            this->m_ele[i] = this->m_ele[j];
        }
        if (ret)
            this->m_size -= 1;
        return ret;
    }

    void insert(T elem) {
        int i;
        int new_size;
        if (this->m_size == this->m_capacity) {
            new_size = m_size + 10;
            T *p = new T[new_size];
            for (i = 0; i < m_size; i++) {
                p[i] = m_ele[i];
            }
            p[i] = elem;
            m_size = i + 1;
            m_capacity = new_size;
            delete[] m_ele;
            m_ele = p;
        } else {
            m_ele[m_size++] = elem;
        }
    }

    template <typename F = Less<T>>
    void selectionSort(F func = F()) {
        int maxid;
        for (int k = m_size - 1; k > 0; k--) {
            maxid = 0;
            for (int i = 0; i <= k; i++) {
                if (func(m_ele[maxid], m_ele[i])) {
                    maxid = i;
                }
            }
            T t;
            t = m_ele[k], m_ele[k] = m_ele[maxid], m_ele[maxid] = t;
        }
    }

    template <typename F = Less<T>>
    void insertionSort(F func = F()) {
        for (int i = 1; i < m_size; i++) {
            int k;
            for (k = i - 1; k >= 0; k--) {
                if (m_ele[k] < m_ele[i]) {
                    break;
                }
            }
            int t = m_ele[i];
            for (int j = i; j > k; j--) {
                m_ele[j] = m_ele[j - 1];
            }
            m_ele[k + 1] = t;
        }
    }
    template <typename F = Less<T>>
    void bubbleSort(F func = F()) {
        for (int k = m_size - 1; k > 0; k--) {
            for (int i = 0; i < k; i++) {
                if (func(m_ele[i + 1], m_ele[i])) {
                    T t = m_ele[i];
                    m_ele[i] = m_ele[i + 1];
                    m_ele[i + 1] = t;
                }
            }
        }
    }

    myVector &operator=(const myVector &rhs) {
        if (this != &rhs) {
            m_size = rhs.m_size;
            m_capacity = rhs.m_capacity;
            T *p = new T[m_capacity];
            for (int i = 0; i < m_size; i++) {
                p[i] = rhs.m_ele[i];
            }
            m_ele = p;
        }
        return *this;
    }
    T &operator[](unsigned int pos) {
        if (pos < m_size)
        {
            return m_ele[pos];
        }
        throw out_of_range("out of range");
    }

    myVector &operator=(myVector &&rhs) {
        m_size = rhs.m_size;
        m_capacity = rhs.capacity;
        m_ele = rhs.m_ele;
        rhs.m_size = rhs.m_capacity = 0;
        rhs.m_ele = nullptr;
        return *this;
    }

    void clear() { this->m_size = 0; }
    int size() const { return this->m_size; }
    int capacity() const { return this->m_capacity; }

    friend ostream &operator<<(ostream &os, const myVector<T> *rhs) {
        T *p = rhs->m_ele;
        int len = rhs->size();
        for (int i = 0; i < len; i++) {
            os << p[i] << " ";
        }
        os << endl;
        return os;
    }
};

int main()
{
    myVector<int> *vec = new myVector<int>();
    myVector<int> *vec2 = new myVector<int>();

    /// 假设从控制台输入10个数据
    int value;
    for (size_t i = 0; i < 10; i++)
    {
        cin >> value;
        vec->insert(value);
    }

    cout << "容器当前元素: " << vec << endl;
    cout << "容器当前元素个数: " << vec->size() << ", 容量: " << vec->capacity() << endl;

    vec->erase(vec->m_ele[1]);

    vec2 = vec;

    vec2->bubbleSort();
    cout << "容器当前元素: " << vec2 << endl;
    cout << "容器当前元素个数: " << vec2->size() << ", 容量: " << vec2->capacity() << endl;

    return 0;
}