#include <iostream>
#include <vector>

#ifndef Algoritism_h
#define Algoritism_h

class IntManipulation {

private:
  std::vector<int> _data;
  static size_t _size;

  int partition(std::vector<int> &vec, int low, int high);
  int quick_select(int low, int high, size_t n);

public:
  IntManipulation(std::vector<int>& vec);
  size_t get_size() const { return _data.size(); }

  int quick_sort();
  int bubble_sort();
  int merge_sort();
  int insertion_sort();
  int selection_sort();

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
