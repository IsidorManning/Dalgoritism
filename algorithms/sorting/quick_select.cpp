#include "sorting.h"

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