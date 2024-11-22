# Selection

## Problem Statement
Take an unsorted array of numbers, and sort them using a Selection algorithm as described in CS50x. Understand how the program and its elements work, step by step.

## sizeof()

We will need to use sizeof(), a built in operator in C, to find the number of elemnts in the unsorted array.

- sizeof() evaluates the size of a data type otr object (like a variable or array) in bytes.
  - On many systems, sizeof(int) is 4 bytes.
  - In C, sizeof(char) is 1 byte

- When applied to an array, sizeof(array) calculates the total memory allocated for the array. This includes the memory for all its elements.

- Suppose an array of 8 integers. If sizeof(int) is 4 bytes, the total memory of the array is: 8 * 4 = 32 bytes.
- Now use sizeof(array[o]) to calculate the size of the first element. Because it is an int, sizeof(array[0]) = 4 bytes.
  - In some 16 bit systems, an int may be 2 bytes, and in some specialized systems, an int may be 8 bytes.
  - But in all cases, the value of an int in bytes will not vary WITHIN a system.

- We use this formula: Number of Elements = Total Memory Size / Size of One Element

So: int size = sizeof(array) / sizeof(array[0])



```
#include <stdio.h>

// Prototypes
void selection_sort(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
  // Unsorted Array
  int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};

  // Calculate the number of elements in the array.
  // sizeof(numbers) gives the total memory size of the array.
  // sizeof(numbers[0]) gives th size of one int element.
  // Dividing these two gives the total number of elements in the array.  
  int size = sizeof(numbers) / sizeof(numbers[0]);

  // Print unsorted array.
  printf("Original array:\n");
  print_array(numbers, size);
  
  // Sort the array.
  selection_sort(numbers, size);
}

void selection_sort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    
  }
}

```
