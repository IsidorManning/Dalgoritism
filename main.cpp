#include "Algoritism.cpp"
#include <vector>

int main() {
  // Demostrating the "find_nth_smallest()" function:
  
  std::vector<int> my_int_vec = {1, 5, 2, 7, 3, 2, 6, 99, -2}; 
  IntManipulation int_manipulation = IntManipulation(my_int_vec);

  size_t nth_index = 4;
  int nth_smallest = int_manipulation.find_nth_smallest(nth_index);
  std::cout << "The " << nth_index << ":th smallest value of your data is " << nth_smallest;
  std::cout << std::endl << std::endl << std::endl;


  // Demostrating the "reverse_vector_and_words()" function:
  
  std::vector<std::string> my_string_vec = {"Hi", "my", "name", "is", "Isidor", ":)", "reversed", "anna"}; 
  StringManipulation string_manipulation = StringManipulation(my_string_vec);
  
  std::cout << string_manipulation.serialize() << std::endl;
  string_manipulation.reverse_vector_and_words();
  std::cout << string_manipulation.serialize() << std::endl;

  return 0;
}