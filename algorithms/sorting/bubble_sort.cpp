#include "sorting.h"

/**
 * @brief Perform bubble sort on the internal data array in ascending order.
 * 
 * This method implements the bubble sort algorithm to sort the internal 
 * '_data' array of the IntManipulation class in ascending order.
 * 
 * @details Bubble sort repeatedly steps through the list, compares adjacent elements, 
 * and swaps them if they are in the wrong order. The process continues until no 
 * more swaps are needed, indicating that the array is sorted.
 * 
 * @note Time complexity in the worst case: O(n^2).
 */
void IntManipulation::bubble_sort() {
    size_t current_index = 1; // Index used to traverse the array.
    size_t n_swaps = 0; // Count the number of swaps in one full iteration through the array.

    while (true) {
        int left = _data[current_index - 1]; // Get the left element.
        int right = _data[current_index]; // Get the right (current) element.

        if (right < left) {
            // Swap the elements if they are in the wrong order.
            std::swap(_data[current_index - 1], _data[current_index]);
            ++n_swaps; // Increment the number of swaps.
        }

        // Check if we are at the end of the array.
        if (++current_index == _data.size()) {
            current_index = 1; // Reset index to start the next pass.
            
            // If no swaps were performed, the array is sorted, and we can exit the loop.
            if (n_swaps == 0) break;
            else n_swaps = 0; // Reset the swap counter for the next iteration.
        }
    }
}