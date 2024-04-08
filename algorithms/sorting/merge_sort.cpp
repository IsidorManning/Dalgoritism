#include "sorting.h"

/**
 * @brief Perform merge sort on the internal data array in ascending order.
 * 
 * This method implements the merge sort algorithm to sort the internal 
 * '_data' array of the IntManipulation class in ascending order.
 * 
 * @details Merge sort is a divide-and-conquer algorithm that divides the array 
 * into two halves, recursively sorts each half, and then merges them together.
 * 
 * @note Time complexity: O(n log n).
 */
void IntManipulation::merge_sort() {
    _merge_sort(_data);
}

/**
 * @brief Recursively sorts the given vector using the merge sort algorithm.
 * 
 * This method sorts the given vector using the merge sort algorithm.
 * It divides the vector into two halves, sorts each half recursively, and then
 * merges them back together in sorted order.
 * 
 * @param vec The vector to be sorted.
 */
void IntManipulation::_merge_sort(std::vector<int> &vec) {
    // if the vector has one or zero elements, it is already sorted.
    if (vec.size() <= 1) return;

    // Divide the vector into two halves.
    std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
    std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());

    // Recursively sort the left and right halves.
    _merge_sort(left);
    _merge_sort(right);

    // Merge the sorted left and right subarrays directly into the original array.
    // variables i, j, and k are initialized to 0. i and j are used as indices to 
    // traverse the left and right subarrays respectively, while k is used as an 
    // index to update the original array vec.
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            vec[k] = left[i];
            i++;
        } else {
            vec[k] = right[j];
            j++;
        }
        // Regardless of which element is copied, k is always incremented after 
        // copying an element.
        k++;
    }

    // Copy any remaining elements from the left subarray.
    while (i < left.size()) {
        vec[k] = left[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right subarray.
    while (j < right.size()) {
        vec[k] = right[j];
        j++;
        k++;
    }
}
