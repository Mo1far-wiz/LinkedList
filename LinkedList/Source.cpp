#include <iostream>
#include "LinkedList.h"

struct A {
    int x;
    char y;
    A(int a, char b) : x(a), y(b) {
        std::cout << "A ctor" << std::endl;
    }

    A(const A& o) : x(o.x), y(o.y) {
        std::cout << "A copy ctor" << std::endl;
    }

    A(A&& o) noexcept : x(std::move(o.x)), y(std::move(o.y)) {
        std::cout << "A move ctor" << std::endl;
    }

    A& operator=(const A& other) {
        if (this == &other)
            return *this;

        x = other.x;
        y = other.y;

        return *this;
    }

    ~A() {
        std::cout << "A dtor" << std::endl;
    }

    friend std::ostream& operator <<(std::ostream& os, const A& a) {
        return os << a.x << " " << a.y;
    }
};

int main() {
    LinkedList<int> list;
    list.push_front(1);
    list.push_back(12);
    list.push_back(18);
    list.push_back(61);
    list.display(); 
    std::cout << std::endl;
    list.pop_front();
    LinkedList<int> nlist (list);
    list.push_front(0);

    list.display();
    std::cout << std::endl;
    nlist = list;
    nlist.pop_back();
    nlist.display();

    std::cout << std::endl << "move" << std::endl;

    nlist = std::move(list);
    nlist.pop_front();
    nlist.pop_front();
    nlist.display();
    std::cout << std::endl;

    LinkedList<int> l(std::move(nlist));

    l.pop_back();
    l.pop_back();
    l.pop_back();
    l.pop_back();
    l.pop_back();
    l.display();

    l.push_front(1);
    l.push_back(12);
    l.push_back(18);
    l.push_back(61);

    auto iter_begin = l.begin();
    auto iter_end = l.end();

    std::cout << iter_begin->_val << std::endl;


    for (; iter_begin != iter_end; ++iter_begin) {
        std::cout << iter_begin->_val << std::endl;
    }

    return 0;
}