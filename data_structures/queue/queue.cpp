#include "queue.h"

template <typename T>
Queue<T>::~Queue() {
    while (!is_empty()) {
        dequeuue();
    }
}

/**
 * @brief Inserts an element at the end of the queue.
 * 
 * This function inserts a new element containing the provided data 
 * at the end of the queue.
 * 
 * @param data The data to be inserted into the queue.
 */
template <typename T>
void Queue<T>::enqueue(const T& data) {
    Node *new_node = new Node(data);

    if (_size == 0) _head = new_node;
    else _tail->next = new_node;
    
    if (_size == 1) _after_front = new_node;
    _tail = new_node;
  
    ++_size;
}

/**
 * @brief Removes the element at the front of the queue.
 * 
 * This function removes the element at the front of the queue.
 * 
 */
template <typename T>
void Queue<T>::dequeue() {
    // Handle the case where the queue alreay is empty.
    if (_size == 0) return;

    Node *_head_node_holder = _head;
    _head = _after_front;
    delete _head_node_holder;
    _after_front = _after_front->next;

    --_size;
}