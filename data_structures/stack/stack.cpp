#include "stack.h"


/**
 * @brief Destroy the Stack object.
 * 
 * Deletes all nodes in the stack to free memory.
 */
template <typename T>
Stack<T>::~Stack() {
    while (!is_empty()) {
        pop();
    }
}

/**
 * @brief Pushes an element onto the top of the stack.
 * 
 * @param data The data to be pushed onto the stack.
 */
template <typename T>
void Stack<T>::push(const T& data) {
    Node* new_node = new Node(data);
    
    if (_top == nullptr) _top = new_node;
    
    else {
        new_node->next = _top;
        _top = new_node;
    }

    ++_size;
}

/**
 * @brief Removes and returns the element at the top of the stack.
 * 
 * @return The data of the element at the top of the stack.
 */
template <typename T>
void Stack<T>::pop() {
    if (is_empty())  return; 

    Node* temp = _top;
    _top = _top->next;
    delete temp;
    --_size;
}

/**
 * @brief Returns the data of the element at the top of the stack.
 * 
 * Does not remove the element from the stack.
 * 
 * @return The data of the element at the top of the stack.
 */
template <typename T>
T Stack<T>::top() const {
    if (is_empty()) return -1;
    return _top->data;
}

