#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node *next;
        Node(const T& s = T()) : data(s), next(nullptr) {}
    };
    Node *_head, *_tail, *_prev_to_current;
    size_t _size;

public:
    LinkedList();
    ~LinkedList();
    LinkedList* insert_at_current(const T& s);
    LinkedList* push_front(const T& s);
    LinkedList* push_back(const T& s);

    LinkedList* advance_current();
    T get_current() const;
    LinkedList* remove_at_current();
    void clear();

    size_t get_size() const { return _size; };
    LinkedList* rewind();

    std::string to_string() const;
};
#endif 
