//#include "IQueue.h"
#include<iostream>

using namespace std;

template<typename T>
class QueueList// : public IQueue<T>
{

private:
    size_t _size;
    struct Node
    {
        T _element;
        Node* _next;
        Node() : _next(nullptr) {}
    };

    Node* _head, * _tail;

public:

    class BadQueueList {};

    explicit QueueList<T>() : _head(0), _tail(0), _size(0)
    {
        cout << "Empty queue list was created" << endl;
    }

    ~QueueList<T>()
    {
        Node* next = _head;
        Node* current;

        while (next)
        {
            current = next;
            next = next->_next;
            delete current;
        }

        cout << "Queue list was deleted" << endl;
    }

    size_t capacity() const
    {
        return _size;
    }

    size_t size() const
    {
        return _size;
    }

    bool empty() const
    {
        return _size == 0;
    }

    bool full() const
    {
        return false;
    }

    const T& front() const
    {
        if (empty())
            throw BadQueueList();

        return _head->_element;
    }

    void pop()
    {
        if (empty())
            throw BadQueueList();

        _size--;
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
    }

    void put(const T& value)
    {
        if (empty())
        {
            _head = new Node();
            _tail = _head;
            _head->_element = value;
            _head->_next = nullptr;
        }
        else
        {
            Node* newTail = new Node();
            newTail->_element = value;
            _tail->_next = newTail;
            _tail = newTail;
            _tail->_next = nullptr;
        }

        _size++;
    }
    void putFront(const T& value) {
        Node* next = new Node();
        next->_element = value;
        next->_next = _head;
        _head = next;

        if (empty())
            _tail = _head;

        ++_size;
    }
    void popBack() {
        if (empty())
            throw BadQueueList();
        else if (_size == 1) {
            pop();
            return;
        }

        Node* head_tmp = _head;

        while (head_tmp->_next->_next != nullptr)
            head_tmp = head_tmp->_next;

        delete head_tmp->_next;
        head_tmp->_next = nullptr;
            tail = head_tmp;

        --_size;
    }
};