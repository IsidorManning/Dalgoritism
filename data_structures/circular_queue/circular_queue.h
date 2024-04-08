#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <vector>
#include <sstream>

template<typename T>
class CircularQueue {
private:
    std::vector<T> _data;
    size_t _head, _tail;

    // Sentinel value for indicating empty queue.
    static T _sentinel : T(); 

public:
    static const int MAX_DISP_ELEMS = 100;
    CircularQueue(size_t size);

    static void set_sentinel(const T& elem) { _sentinel = elem; };
    static T get_sentinel() { return _sentinel; };

    bool is_empty() const;
    size_t size() const;
    void resize(size_t size);

    const T& peek() const;
    bool dequeue();
    bool enqueue(const T& elem);

    std::string to_string(size_t limit = MAX_DISP_ELEMS) const;
};

#endif
