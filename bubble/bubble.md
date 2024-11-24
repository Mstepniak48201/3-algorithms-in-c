# Bubble Sort

## Problem Statement

Take an unsorted array of numbers, and sort them using a Bubble Sort algorithm as described in CS50x. Understand how the program and its elements work, step by step.

## Overview in pseudo-code
```
unsorted_array = 5, 3, 5, 2, 9, 8

size = size of unsorted array


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


