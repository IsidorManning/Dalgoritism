#include "sorting.h"

/**
 * @brief Perform insertion sort on the internal data array in ascending order.
 * 
 * This method implements the insertion sort algorithm to sort the internal 
 * '_data' array of the IntManipulation class in ascending order.
 * 
 * @details Insertion sort builds the final sorted array one element at a time.
 * It iterates through the array, selecting each element and inserting it into
 * its correct position in the already sorted part of the array to its left.
 * 
 * @note Time complexity: O(n^2) in the worst case.
 */
void IntManipulation::insertion_sort() {
    for (size_t i = 1; i < _data.size(); ++i) {
        int current = _data[i]; // Get the current element to be inserted.
        int previous = _data[i - 1]; // Get the element before the current one.

        // Compare the current element with the previous one.
        if (previous > current) {
            // Find the correct position to insert the current element by iterating
            // through the already sorted part of the array. This is the part of 
            // the array that is left of the current element.
            for (size_t j = 0; j < i; ++j) {
                if (_data[j] > current) {
                    // Insert the current element at the correct position.
                    _data.insert(_data.begin() + j, current);
                    _data.erase(_data.begin() + i + 1); // Remove the duplicated element.
                    break; // Break out of the inner loop once insertion is done.
                }
            }
        }
    }
}