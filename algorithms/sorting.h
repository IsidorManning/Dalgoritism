#include <iostream>
#include <vector>

#ifndef Sorting_h
#define Sorting_h


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
