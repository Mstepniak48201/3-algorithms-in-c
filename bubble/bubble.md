# Bubble Sort

## Problem Statement

Take an unsorted array of numbers, and sort them using a Bubble Sort algorithm as described in CS50x. Understand how the program and its elements work, step by step.

The bubble sort should iterate over the array, and after each "pass" through the array:

  - The largest unsorted element is "bubbled up" to its sorted position at the end of the array.

  - The process continues until no further swaps are necessary.

An outer loop (i) will iterate over the array, wherein i is the "pass" over the array.

Within the outer loop an inner loop (j) iterates over the array and compares the adjacent elements array[j] and array[j + 1]. The largest element will "bubble" to the top.


## Overview in pseudo-code
```
unsorted_array = 5, 3, 5, 2, 9, 8

size = size of unsorted array

// Function takes the array and the array's size as arguments.
void bubble_sort(int array[], int size)
  // Since the inner loop will be comparing array[j] and array[j + 1],
  // and we want to prevent the loop from attempting to compare elements
  // outside the range of the array's size,
  // we set the loop to stop iterating at size - 1.
  for i = 0; i < size - 1; i++

    // Create a variable to check if swaps are made.
    // On each iteration of the outer loop, swapped will reset to 0.
    // If swaps are made, the value will change within the inner loop.
    // If the inner loop completes and no swaps are made, this means
    // that the array is sorted and the loop will break.
    int swapped = 0

    // Since at the end of the inner loop, the largest elements will have
    // "bubbled" or have been sorted to the end of the array, we have 
    // fewer elements to compare on every iteration of the outer loop.
    // So we set the inner loop's iteration at size - i - 1, to
    // prevent it from attempting to compare elements beyond the array's
    // size, but also to prevent it from comparing elements that have
    // already been sorted.
    for j = 0; j < size - i - 1; j++
  
      // Compare the current unsorted element with the adjacent unsorted element.
      // And if the current unsorted element is the larger of the two:
      if array[j] > array[j + 1]

        // Store the current unsorted element in a temporary variable.
        temp = array[j] 

        // Start the swap, and set the element at index j to the value of the
        // adjacent variable.
        array[j] = array[j + 1]
    
        // Complete the swap by setting the element at index j + 1 to teh value
        // stored in the temp variable, that we know is the larger of the two values.
        array[j + 1] = temp

        // Mark that a swap occurred. 
        swapped = 1

      // At the end of the inner loop, check the value of swapped.
      // If it is zero, the array is sorted and the loop breaks.
      if not swapped
        break
```

## sizeof()

We used sizeof() in the selection sort algorithm. To review:

- The array to be sorted is comprised of integers. Each integer hs a a size of n bytes. The number of bytes in an integer may vary by system.

- sizeof() evaluates the size of a data type or object (like a variable or array) in bytes.

- In C, sizeof(char) is 1 byte

- sizeof(array) calculates the total memory allocated for the array. This includes the memory for all its elements.


We can use the following formula to calculate the size of an array:

  Number of Elements = Total Memory Size / Size of One Element  

  - sizeof(array) = Total Memory Size

  - sizeof(array[0]) = Size of One Element

So: int size = sizeof(array) / sizeof(array[0])


## Test Code

```
#include <stdio.h>

// Prototypes
void bubble_sort(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{ 
  // Unsorted array
  int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};

  // Get array size.
  int size = sizeof(numbers) / sizeof(numbers[0])

  // Print unsorted array.
  printf("Unsorted array:\n");
  print_array(numbers, size)

  // Sort array.
  bubble_sort(numbers, size);

  // Print sorted array.
  printf("Sorted array:\n");
  print_array(numbers, size);
}

void bubble_sort(int arr[], int size);
{

}

void print_array(int arr[], int size);
{
  for (int i = 0; i < size; i++)
  {
    printf("%i", arr[i]);
  }
  printf("\n");
}


```


