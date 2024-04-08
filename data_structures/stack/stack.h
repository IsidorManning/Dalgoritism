#include <iostream>
#include <vector>

#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* _top;
    size_t _size;

public:
    Stack() : _top(nullptr), _size(0) {}
    ~Stack();

    void push(const T& data);
    size_t size() const { return _size; };
    void pop();
    T top() const;
    bool is_empty() const { return (_size == 0 ? true : false); }
};

#endif
