#include "sorting.h"

/**
 * @brief Perform selection sort on the internal data array in ascending order.
 * 
 * This method implements the selection sort algorithm to sort the internal 
 * '_data' array of the IntManipulation class in ascending order.
 * 
 * @details selection sort selects the smallest value in any unsorted array (or subarray)
 * and replaces that minimum element with the current element. The algorithm does this for
 * all elements in the array until it is sorted.
 * 
 * @note Time complexity in the worst case: O(n^2).
 */
void IntManipulation::selection_sort() {
    // Iterate over all elements in the array
    for (size_t i = 0; i < _data.size(); ++i) {
        // initilize the minimum value at index 'min_index' to be the current
        // element.
        int min_index = i; 

        // Iterate over all elements right of the current element.
        for (size_t j = i; j < _data.size(); ++j) {
            // Select the smallest value in this right, subarray.
            if (_data[j] < _data[min_index]) min_index = j;
        }

        // Swap the current value in the array with the smaller value (if any was found)
        // at index 'min_index'
        std::swap(_data[i], _data[min_index]);
    }
}
