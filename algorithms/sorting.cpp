#include <iostream>
#include <climits>
#include <vector>
#include <sstream>
#include "Sorting.h"


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
