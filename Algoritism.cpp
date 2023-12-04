#include <iostream>
#include <climits>
#include <vector>
#include <sstream>
#include "Algoritism.h"


IntManipulation::IntManipulation(std::vector<int>& vec) {
  // Here we accept the inputted vector containing of integers 
  // by reference. We do it this way to avoid having to copy
  // the whole vector which results in lower efficiency.
  _data = vec; // store the reference in a variable called "_data".
}

int IntManipulation::quick_sort() {
  // Will implement in the future.
}

int IntManipulation::bubble_sort() {
  // Will implement in the future.
}

int IntManipulation::merge_sort() {
  // Will implement in the future.
}

int IntManipulation::insertion_sort() {
  // Will implement in the future.
}

int IntManipulation::selection_sort() {
  // Will implement in the future.
}

bool IntManipulation::sort_in_ascending_order(std::string algorithm_name) {
  // Currently not used since it infolves having implemented the above sorting
  // algorithms. Therefore, you can ignore it for now.
  //
  // This whole method I basically implemented for the sake of the user.
  // What this method does is simply calling the corresponding 
  // sorting algorithm on the curret data vector ("_data") based
  // on the inputed name of the algorithm ("algorithm_name").

  if (algorithm_name == "bubble") {
    bubble_sort();
    return true;
  } else if (algorithm_name == "merge") {
    merge_sort();
    return true;
  } else if (algorithm_name == "quick") {
    quick_sort();
    return true;
  } else if (algorithm_name == "insertion")  {
    insertion_sort();
    return true;
  } else if (algorithm_name == "selection")  {
    selection_sort();
    return true;
  }
  
  return false;
}

int IntManipulation::find_second_smallest() {
  // First we initilize the variables "smallest" and
  // "second_smallest" to a INT_MAX which is the 
  // maximum value an int can hold (2147483647).
  int smallest = INT_MAX;
  int second_smallest = INT_MAX;

  // We loop through our vector from the start
  for (size_t i = 0; i < get_size(); ++i) {
    if (_data[i] < smallest) {
      // Now if the current element is smaller than the current 
      // smallest value ("smallest"), we will need to re-asign
      // our smallest value to be the current element. Secondly,
      // we will also need to re-asign our current value for the 
      // second smallest number ("second_smallest") which now will
      // be what the old value for our variable "smallest" was.
      second_smallest = smallest;
      smallest = _data[i];
    } else if (_data[i] < second_smallest && _data[i] != smallest) {
      // If the current element is smaller than the currently second
      // smallest value ("second_smallest"), and if the current element
      // has not the same value as the current smallest value ("smallest"),
      // this means that the current value is bigger than our smallest 
      // value but smaller than our second smallest value!
      second_smallest = _data[i];
    }
  }
  return second_smallest;
}

int IntManipulation::find_nth_smallest(size_t n) {
  if (n <= get_size()) {
    // initilize the lower boundary to the first index of the "_data" vector.
    int low = 0;
    // initilize the upper boundary to the last index of the "_data" vector.
    int high = _data.size() - 1; 
    // This next line is necessary since we want to convert the 
    // human-readable index (starting from 1) inputted by the user, 
    // to a index starting from 0.
    --n;

    // Now we start doing the quick select algorithm which, after some
    // recursion, should return the n:th smallest value of the "_data"
    // vector.
    return quick_select(low, high, n);
  }
}

int IntManipulation::quick_select(int low, int high, size_t n) {
  // This method will perform quick select on the vector "_data" that was 
  // initilized in the constructor. Quick select is a sorting algorithm that 
  // is used to search an vector for one single element and it uses the partition
  // algorithm to achieve this goal.
  // The parameters "low" and "high" represent the index of the lower and 
  // upper boundary of the initilized "_data" vector.

  // The following check is necessary to check whether the vector is 
  // empty or not. 
  if (low <= high) {
    // Call the "partition" function to get the index of the pivot
    // element after the partition of the vector has been done.
    int pivot_i = partition(_data, low, high);

    // if the pivot index ("pivot_i") is the same as the the value 
    // for n, the index of the n:th smallest element in the vector ("_data") 
    // has been found. 
    if (pivot_i == n) return _data[pivot_i];

    // if the pivot index is greater than the value of n, we 
    // recursively call the "quick_select" function and search the left
    // sub-vector for the n:th smallest value since we now know that the value
    // must be contained in the subset of smaller values of the vector.
    else if (pivot_i > n) return quick_select(low, pivot_i - 1, n);
    
    // At this point in the code we know that the pivot index 
    // ("pivot_i") is smaller than "n". Therefore, we will recursively 
    // call the "quick_select" function and search the right sub-vector for 
    // the n:th smallest value since we now know that the value
    // must be contained in the subset of larger values of the vector.
    else return quick_select(pivot_i + 1, high, n);
  }
}

int IntManipulation::partition(std::vector<int>& vec, int low, int high) {
  // What this private method does is that it takes in a vector vy reference 
  // and partitions it accordingly. It works by sorting a vector
  // so that we end up having a sorted vector where we have a chosen 
  // pivot element in the middle, where all elements to the left of
  // that pivot is smaller than the pivot element, and where all elements 
  // to the right of the pivot is larger than the pivot element. While the pivot
  // element can be chosen to be any element in the vector, you would
  // typically chose the pivot element to be the last element in the vector.
  //
  // The parameters "low" and "high" represent the index of the lower and 
  // upper boundary of the inputted vector, "vec", respectively. It returns
  // the index of the pivot element once the vector has been correctly sorted.
  int pivot = vec[high]; // Initilize the pivot element to the last element.

  // "i" is the index to track the position of the smaller
  // elements in the  vector, "vec", (the left side of the pivot element).
  int i = low - 1; 

  // Start looping through the vector, "vec", excluding the last element
  // at index "high".
  for (int j = low; j < high; ++j) {
    // Check if the current element of the vector, "vec", at index "j" 
    // is smaller than or equal to the pivot element ("pivot").
    if (vec[j] <= pivot) {
      // At this point we increment "i" to move to the next position. We will 
      // also swap the element at index "i" with the element at index "j". We have
      // now shifted a smaller value in the vector to the left side of the pivot. 
      // Now we will follow this same process for all values in the vector to 
      // end up with a correctly partitioned vector.
      ++i;
      std::swap(vec[i], vec[j]);
    }
  }
  // Before we return we swap the pivot element ("pivot") with the element at the 
  // next position after the element at index "i". We do this to move the pivot element
  // to the middle of the vector.
  std::swap(vec[i + 1], vec[high]);

  // Now that we have rearranged and partitioned the vector we will return the index of  
  // the pivot element which would be "i + 1".
  return i + 1;

  // Intuition of partition algorithm: Imagine a vector that looks like 
  // [9, 2, 5, 0, 4], where the pivot element is 4 at index 4:
  //
  // Iteration 1: "i" = -1, "j" = 0. 9 is not smaller than 4 so we move on.
  //
  // Iteration 2: "i" = -1, "j" = 1. 2 is smaller than 4. "i" = 0. Swap the element
  // at index "i" with the one at index "j". Now our vector looks like [2, 9, 5, 0, 4].
  //
  // Iteration 3: "i" = 0, "j" = 2. 5 is not smaller than 4 so we move on.
  //
  // Iteration 4: "i" = 0, "j" = 3. 0 is smaller than 4. "i" = 1. Swap the element
  // at index "i" with the one at index "j". Now our vector looks like [2, 0, 5, 9, 4].
  //
  // Iteration 5: "i" = 1, "j" = 4. Now we exit the loop since 4 ("j") is not smaller 
  // than 4 ("high"). So our vector still looks like [2, 0, 5, 9, 4].
  //
  // At this point we switch the element at index "i" + 1 (1 + 1 = 2), which would be
  // the element 5, with the pivot element at index high. We swap vec[2] with vec[high] 
  // and end up with a vector looking like [2, 0, 4, 9, 5].
}

bool IntManipulation::reverse_vector() {
  // This method reverses the order of the elements in the vector
  // "_data" that was initialized in the constructor.
  size_t n = get_size();

  // We iterate over the first half of the numbers ("n" / 2) in the vector 
  // since iterating over the full vector would lead to us first reversing 
  // the vector and then reversing it back to its original state.
  for (size_t i = 0; i < n / 2; i++) {
    int current_value_holder = _data[i];
    _data[i] = _data[n - 1 - i];
    _data[n - 1 - i] = current_value_holder;
  }

  return true;
}

std::string IntManipulation::serialize() const {
  std::stringstream repr;
  size_t n = get_size();

  repr << "Your data vector contains " << n << " elements:" << std::endl;
  for (size_t i = 0; i < n; ++i) repr << "Element " << (i + 1) << ": " << _data[i] << std::endl;

  return repr.str();
}


StringManipulation::StringManipulation(std::vector<std::string>& vec) {
  // Here we accept the inputted vector containing of strings 
  // as reference. We do it this way to avoid having to copy
  // the whole vector which results in lower efficiency.
  _data = vec; // store the reference in a variable called "_data".
}

bool StringManipulation::reverse_vector_and_words() {
  size_t n_words = get_size();

  // We iterate over the first half of the numbers ("n" / 2) in the vector 
  // since iterating over the full vector would lead to us first reversing 
  // the vector and then reversing it back to its original state.
  for (size_t i = 0; i < n_words / 2; ++i) {
    std::string current_word_holder = _data[i];
    _data[i] = reverse_letters(_data[n_words - 1 - i]);
    _data[n_words - 1 - i] = reverse_letters(current_word_holder);
  }

  return true;
}

std::string StringManipulation::reverse_letters(std::string& word) {
  size_t n_letters = word.length();

  // We iterate over the first half of the letters ("n" / 2) in the word 
  // since iterating over all letter would lead to us first reversing 
  // the word and then reversing it back to its original state.
  for (size_t j = 0; j < n_letters / 2; ++j) {
    char current_letter = word[j];
    word[j] = word[n_letters - 1 - j];
    word[n_letters - 1 - j] = current_letter;
  }

  return word;
}

bool StringManipulation::alphabeticla_sort() {
  // Will implement in the future.
}

std::string StringManipulation::serialize() const {
  std::stringstream repr;
  size_t n = get_size();

  repr << "Your data vector contains " << n << " elements:" << std::endl;
  for (size_t i = 0; i < n; ++i) repr << "Element " << (i + 1) << ": " << _data[i] << std::endl;

  return repr.str();
}

