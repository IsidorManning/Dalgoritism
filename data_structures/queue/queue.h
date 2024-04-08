#include <iostream>
#include <vector>

#ifndef Queue_h
#define Queue_h

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node *next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    Node *_head, *_tail, *_after_front;
    size_t _size = 0;

public:
    ~Queue();

    void enqueue(const T& data);
    void dequeue();

    bool is_empty() { return (_size == 0 ? true : false); }
    size_t size() { return _size; }
    T peek() { return _head->data; }
};
#endif
