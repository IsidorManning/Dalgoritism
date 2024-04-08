#include "circular_queue.h"

/**
 * @brief Constructor for the CircularQueue class.
 * 
 * @param size Initial size of the circular queue.
 */
template <typename T> 
CircularQueue<T>::CircularQueue(size_t size) {
    _data.resize(size + 1); // + 1 to accommodate for circular behavior

    _head = 0;  
    _tail = 0;
}

/**
 * @brief Get the element at the front of the queue without removing it.
 * 
 * @return The element at the front of the queue.
 */
template<class T> 
const T &CircularQueue<T>::peek() const {
    if (is_empty()) return _sentinel;

    return _data[_head];
}

/**
 * @brief Add an element to the back of the queue.
 * 
 * @param elem The element to be added.
 * @return true if the element was successfully added, false otherwise.
 */
template<class T> 
bool CircularQueue<T>::enqueue(const T& elem) {
    if (_head == (_tail + 1) % _data.size()) return false;

    // Insert element at the end of the queue
    _data[_tail] = elem;
    ++_tail;

    return true;
}

/**
 * @brief Remove the element from the front of the queue.
 * 
 * @return true if the element was successfully removed, false otherwise.
 */
template<class T> 
bool CircularQueue<T>::dequeue() {
    if (is_empty()) return false;

    // Remove (mark as removed) the front element of the queue
    _data[_head] = 0;
    ++_head;

    return true;
}

/**
 * @brief Resize the circular queue.
 * 
 * @param size The new size of the circular queue.
 */
template<class T> 
void CircularQueue<T>::resize(size_t size) {
  CircularQueue new_queue(size);

  while (!(is_empty())) {
    T front_element = peek();

    new_queue.enqueue(front_element);
    dequeue();
  }

  // Update the current instance's state to match the new_queue
  _data = new_queue._data;
  _head = new_queue._head;
  _tail = new_queue._tail;
}

/**
 * @brief Removes all elements from the given CircularQueue.
 * 
 * @tparam T Type of elements stored in the queue.
 * @param q The CircularQueue from which elements are to be removed.
 */
template <class T>
void popalot(CircularQueue<T>& q) { 
  while (!q.is_empty()) {
    q.dequeue();
  }
}

/**
 * @brief Convert the circular queue to a string.
 * 
 * @param limit Maximum number of elements to include in the string.
 * @return A string representation of the circular queue.
 */
template<class T> 
std::string CircularQueue<T>::to_string(size_t limit) const {
  std::stringstream repr;
  repr << "# Circular Queue - size = " << size() << std::endl << "data :";

  if (size() == 0) {
    repr << std::endl;
    return repr.str();
  }
  
  repr << " "; 
  for (size_t i = 0; i < limit; ++i) {
    if (i == limit) repr << _data[i] << std::endl;
    else repr << _data[i] << " ";
  }

  if (size() > limit) repr << " " << "...";

  return repr.str();
}
