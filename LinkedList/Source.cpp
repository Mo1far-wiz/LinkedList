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


    return 0;
}