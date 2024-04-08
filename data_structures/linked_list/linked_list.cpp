#include "linked_list.h"

/**
 * @brief Constructor to initialize the linked list.
 * 
 * Initializes the head, tail, and current pointers to point to a sentinel node.
 * Sets the size of the linked list to 0.
 */
template<typename T>
LinkedList<T>::LinkedList() {
    _head = new Node(T());
    _tail = _head; 
    _prev_to_current = _head;
    _size = 0;
}

/**
 * @brief Destructor to free memory allocated for the linked list.
 * 
 * Removes all nodes from the linked list and deallocates memory.
 */
template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
    _head = nullptr;
}

/**
 * @brief Inserts a new node containing data at the current position.
 * 
 * @param s The data to be inserted.
 * @return A pointer to the modified linked list.
 */
template<typename T>
LinkedList<T>* LinkedList<T>::insert_at_current(const T& s) {
    Node* new_node = new Node(s);
    new_node->next = _prev_to_current->next;
    _prev_to_current->next = new_node;
    if (_prev_to_current == _tail) _tail = new_node;
    ++_size;
    return this;
}

/**
 * @brief Inserts a new node containing data at the front.
 * 
 * @param s The data to be inserted.
 * @return A pointer to the modified linked list.
 */
template<typename T>
LinkedList<T>* LinkedList<T>::push_front(const T& s) {
    Node* _prev_to_current_holder = _prev_to_current;
    _prev_to_current = _head;
    insert_at_current(s);
    _prev_to_current = _prev_to_current_holder;    
    return this;
}

/**
 * @brief Inserts a new node containing data at the back.
 * 
 * @param s The data to be inserted.
 * @return A pointer to the modified linked list.
 */
template<typename T>
LinkedList<T>* LinkedList<T>::push_back(const T& s) {
    Node* _prev_to_current_holder = _prev_to_current;     
    _prev_to_current = _tail;
    insert_at_current(s);
    _prev_to_current = _prev_to_current_holder;  
    return this;
}

/**
 * @brief Moves the current position forward by one node.
 * 
 * @return A pointer to the modified linked list, or nullptr if at the end.
 */
template<typename T>
LinkedList<T>* LinkedList<T>::advance_current() {
    if (_prev_to_current == _tail) return nullptr;
    _prev_to_current = _prev_to_current->next;
    return this;
}

/**
 * @brief Gets the data at the current position.
 * 
 * @return The data at the current position, or a default value if at the end.
 */
template<typename T>
T LinkedList<T>::get_current() const {
    T sentinel;
    if (_prev_to_current->next == nullptr) return sentinel;
    return _prev_to_current->next->data;
}

/**
 * @brief Removes the node at the current position.
 * 
 * @return A pointer to the modified linked list.
 */
template<typename T>
LinkedList<T>* LinkedList<T>::remove_at_current() {
    _prev_to_current->next = _prev_to_current->next->next;
    --_size;
    return this;
}

/**
 * @brief Moves the current position to the beginning of the list.
 * 
 * @return A pointer to the modified linked list.
 */
template<typename T>
LinkedList<T>* LinkedList<T>::rewind() {
    _prev_to_current = _head;
    return this;
}

/**
 * @brief Removes all nodes from the list.
 * 
 * Clears the linked list by removing all nodes and resetting pointers.
 */
template<typename T>
void LinkedList<T>::clear() {
    _prev_to_current = _head;
    while (_prev_to_current->next != nullptr) {
        remove_at_current();
    }
    _prev_to_current = _head; _tail = _head;
    _head->next = nullptr;
}

/**
 * @brief Converts the linked list to a string representation.
 * 
 * @return A string representation of the linked list.
 */
template<typename T>
std::string LinkedList<T>::to_string() const {
    std::string repr = "# Linked List - " + std::to_string(_size) + " entries total. Starting at cursor:\n";
    Node* current = _prev_to_current->next;
    for (int i = 0; i <= 25; i++) {
        if (current != nullptr) {
            if (i == 25 && _size > 25) {
                repr += "...";
                break;
            }
            repr += current->data + "\n";
            current = current->next;
        }
    } 
    return repr;
}
