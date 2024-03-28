#include <iostream>
#include <vector>

#ifndef Dalgoritism_h
#define Dalgoritism_h

// Coming soon
class PrefixTree {

private:

public:

};

// Coming soon
class Stack {

private:

public:

};
  
// Coming soon
class HashTable {

private:

public:

};
  
// Coming soon
class CircularQueue {

private:

public:

};

// Coming soon
class GeneralTree {

private:

public:

};

// Coming soon
class BinaryTree {

private:

public:

};

class Queue {
private:
    struct Node {
        int data;
        Node *next;
        Node(int data = -1) : data(data), next(nullptr) {}
    };
    Node *_head, *_tail, *_after_front;
    size_t _size = 0;

public:
    void enqueue(int data);
    void dequeue();

    bool is_empty() { return (_size == 0 ? true : false); }
    int size() { return _size; }
    int peek() { return _head->data; }
};

class IntManipulation {

private:
    std::vector<int>& _data;
    static size_t _size;

    int partition(std::vector<int> &vec, int low, int high);
    int quick_select(int low, int high, size_t n);

    void _merge_sort(std::vector<int> &vec);


public:
    // Here we accept the inputted vector containing of integers 
    // by reference. We do it this way to avoid having to copy
    // the whole vector which results in lower efficiency.
    IntManipulation(std::vector<int>& vec) : _data(vec) {}
    
    size_t get_size() const { return _data.size(); }

    void quick_sort();
    void bubble_sort();
    void merge_sort();
    void insertion_sort();
    void selection_sort();

    bool sort_in_ascending_order(std::string algorithm = "bubble");
    
    int find_second_smallest();
    int find_nth_smallest(size_t n);
    bool reverse_vector();

    std::string serialize() const;
};

class StringManipulation {
  
private:
    std::vector<std::string> _data;
    static size_t _size;

    bool alphabeticla_sort();
    
    std::string reverse_letters(std::string& word);

public:
    StringManipulation(std::vector<std::string>& vec);
    size_t get_size() const { return _data.size(); }

    bool reverse_vector_and_words();

    std::string serialize() const;
};
#endif
