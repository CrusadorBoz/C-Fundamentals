// Write a function funnySort that sorts an array of integers in ascending order, but with a twist: every third number should be the 
// largest number from the unsorted portion of the array up to that point. Here's what you need to do:

// Given an array arr and its size n.
// The function should modify arr in-place.
// For every third position (indices 2, 5, 8, etc.), place the largest number from the unsorted part of the array at that point.
// All other numbers should be sorted in ascending order.

// Example:

// Input: arr[] = {5, 2, 9, 1, 7, 6, 3}
// After sorting normally, it would be {1, 2, 3, 5, 6, 7, 9}.
// But with our twist:
// Place 9 at index 2 (since it's the largest from the unsorted part), now array is {1, 2, 9, 5, 6, 7, 3}
// Place 7 at index 5, now array is {1, 2, 9, 3, 6, 7, 5}

// Final result should be: {1, 2, 9, 3, 5, 7, 6}

// Here's how you might start coding this:

// void funnySort(int arr[], int n) {
//     // Your code here
// }

// This question tests understanding of sorting algorithms, array manipulation, and thinking outside the box with algorithmic design.

// Solution:

#include <stdio.h>

void funnySort(int arr[], int n) {
    // Temporary array to hold the sorted numbers
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    // Perform an in-place sort on temp array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                // Swap elements
                int swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    // Reconstruct the array with the twist
    int place = 0;  // Index for placing sorted numbers
    int largest = n - 1;  // Index for placing largest numbers
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 3 == 0 && largest >= 0) {  // Every third element
            arr[i] = temp[largest];
            largest--;
        } else {
            arr[i] = temp[place];
            place++;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[] = {5, 2, 9, 1, 7, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    funnySort(arr, n);

    printf("Sorted array with twist: \n");
    printArray(arr, n);
    return 0;
}

// Explanation:
// * We first copy the input array into a temporary array temp to perform sorting without altering arr directly during sorting.

// * We use bubble sort here for simplicity, but you could use any sorting method. 

// After sorting temp, we reconstruct arr by:
    // *Placing sorted numbers in order but skipping every third position.

    // *On every third position, we place the largest number left from temp, moving from the end of the sorted array towards the 
    //  beginning to ensure we get the largest numbers.  

// Remember, this solution assumes you're okay with an O(n^2) time complexity 
// due to bubble sort. For larger arrays, consider using a more efficient sorting algorithm like quicksort or heapsort for 
// temp before reconstructing arr.

// gcc -o C:\Users\"Name"\Documents\Programs\funny-sort.exe funnysort.c
