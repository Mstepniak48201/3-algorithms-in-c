# Selection


## Problem Statement
Take an unsorted array of numbers, and sort them using a Selection algorithm as described in CS50x. Understand how the program and its elements work, step by step.

## Overview in pseudo-code

// Outer loop iterates from 0 through size - 1, making certain the loop makes enough passes.
for i = current pass, iterate while the loop hsa completed < size - 1 passes.


  // Check to see if a swap has occurred.
  int swapped = Was a swap made? y/n

  // Inner loop compares adjecent elements, arr[j] and arr[j] + 1,
  // in the unsorted portion of the array during each pass (i).
  for j = starting point for comparison, while j < size - i - 1.

```
unsorted_array = 5, 3, 5, 2, 9, 8

size = size of unsorted array

for i = current element, iterate over all array elements except size - 1 (last element)

  min_index = current unsorted element (i)

  // j will always be one element ahead of i.
  // The loop will compare i and j.
  // Remember that min_index = i.
  for j = i + 1, iterate over all array elements except array[0]
    if array[j] < array[min_index]
      
      // If array[j]  is smaller, reassign the value of min_index.
      // Otherwise, min_index stays the same.
      min_index = j

// Check to make sure that min_index != i, before swapping numbers. If min_index == i, the smallest number is already in the correct place and no further sorting needs to be done in this iteration.
if min_index != i

  // Store the current unsorted value in a temporary variable.
  temp_i = array[i]

  // Replace the value at the current unsorted index 
  // with the smaller value stored in min_index (array[j])
  array[i] = array[min_index]

  // Swap the value stored at array[j] with the unsorted value stored in temp_i
  array[min_index] = temp_i
```

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

## selection sort function

The function must take the array and its size as args.

  `void selection_sort(int arr[], int size)`


We need to iterate through all array elements, except the last one:

  for (int i = 0; i < size - 1; i++)


Within the outer loop, we declare the variable `min_index`. This variable is initialized as i, the first element, and will be updated if elements are smaller in value.

  `int min_index = i`


The inner loop compares the values, stopping at the final value.

- j is initialized to i + 1, as initially, `min_index` is initialized to the index of the first element in the array.
- We want to compare `min_index`, initially array[0] to array[j].
- If array[j] < `min_index`, we update `min_index` to j.
  
```
for (int j = i + 1; j < size; j++)
{
  if (array[j] < min_index)
  {
    min_index = j;
  }
}
```


Next we want to swap the smallest element with the first unsorted element.

- We now know the smallest element in the array, and we have stored its index in `min_index`.
- We now want the element at `array[min_index]` to exist at array[i], and the element at array[i] to exist at `array[min_index]`.
- We do this by storing array[i] in a temporary variable, `temp_i` = array[i].
- We then update array[i] to the value of `array[min_index]`.
- We then update the value of `array[min_index]` to the value of our temporary value, `array[temp_i]`.


Next the loop moves forward, array[i] becomes array[1], and is compared to array[2], and the process repeats.


## print array function

We need to loop through the array from index 0 to size - 1, printing each element followed by a space.

- The function must take the array and its size as args.

for (int i = 0; i < size; i++)
{
  printf("%i ", arr[i]);
}
printf("\n");



```
if (min_index != i)
{
  int temp_i = arr[i];
  arr[i] = arr[min_index];
  arr[min_index] = temp_i;
}
```


## Test Code

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

  // Print sorted array.
  printf("Sorted array:\n");
  print_array(numbers, size);

  return 0;
}

void selection_sort(int arr[], int size)
{
  // Offset by -1 to prevent the loop from attempting to compare
  // to a value outside of the array. 
  for (int i = 0; i < size - 1; i++)
  {
    // Initialize min_index to i (initially arr[0]).
    int min_index = arr[i];

    // Initialize j to i + 1, so that min_size is always 1 index before j.
    for (int j = i + 1; j < size; j++)
    {
      // Compare current element j to min_index.
      if (arr[j] < arr[min_index])
      {
        // Update min_index to smallest element.
        min_index = j;
      }
    }  

    // Swap values between min_index and i, if min_index is not i.
    if (min_index != i)
    {
      // Store i in a temp variable.
      int temp_i = arr[i];
      
      // Replace arr[i] with arr[min_index
      arr[i] = arr[min_index];

      // Replace arr[min_index] with temp (formerly arr[i])
      arr[min_index] = temp;
    }
  }
}


void print_array(arr[], size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%i ", arr[i]);
  }
  printf("\n");
}
```


## Run program

* To compile and run:

- Output the executable file `my_file`.
```
bash:
gcc my_file.c -o my_file
```

