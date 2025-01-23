# Recursive Merge Sort

## Problem Statement

The algorithm should:

- Divide an array of integers into two halves
- Recursively sort each half
- Merge the two sorted halves into a single sorted array.

This splits the problem into halves, solves the problem in small portions, then recombines them.

The steps:

1. Base case: The array has a single (1) or no (0) elements. It's already sorted.
2. Divide: Split the array into two halves.
3. Recursively call the function to sort both halves.
4. Merge: Combaine sorted halves.


## Working Through the Logic

* At the bottom of this file, I will be preserving my process as I work through how to write the merge() function in psuedo-code, and iterate towards the final version.

The logic of the recursive merge sort relies on mechanics of C:
- Integer Truncation: When a variable of type int is the result of the division of two ints, and the division would result in a decimal number, everything past the zero is truncated.

  ```
  // 1 / 2 = 0.5
  // Since a C int will truncate the decimal, the value of int truncate is 0. 
  int truncate = 1 / 2;
  ```

I will start with a test array, and work through the logic.

```
// Test array
int arr[] = {2, 4, 1, 3}

// Get array length. sizeof() returns the number of characters, so 0-indexed length will == size = 1.
int length = (sizeof(arr) / sizeof(arr[0]) = 1;

// Pass in 0 for l (left index) and length for r (right index) to initially examine the entire array.
void merge_sort(int arr[], int l, int r)
{
  // Set a base case for a single element or empty array.
  if (l >= r)
  {
    return;
  }

  // Get midpoint index.
  int m = l + (r - l) / 2;

  // Sort left half.
  merge_sort(arr, 0, m);

  // Sort right half.
  merge_sort(arr, m + 1, r);

  // Call function that merges sorted arrays.
  merge_sorted_arrays(int arr, int l, int m, int r);  
}
```

### Breaking down the Call Stack

1. Initial call | Entire array {2, 4, 1, 3} is passed in | l = 0, r = 3

  ```
  merge_sort(arr, 0, 3);
  ```

- function takes the array, and the left and right-most indices that indicate the portion of the array we want to examine.

- On the initial call, we want to examine the entire array, in this case, indices 0 - 3.

- The first thing the function does is create the initial left-right split by finding the midpoint:

  ```
  //  m = l + (r - l) / 2
  int m = 0 + (3 - 0) / 2;
  ```
  - C truncates everything to the right of the decimal, and m = 1.


2. First Recursive Call | Examine Left Half of Array {2, 4} | l = 0, r = 1

After finding the midpoint, the function calls `merge_sort()` recursively, and passes in the midpoint (m) as the right-most (r) index value, so the function examines the portion of the array between 0 - 1, which is {2, 4}.

  ```
  merge_sort(arr, 0, 1);
  ```

- The First Recursive Call of `merge_sort()` finds the "midpoint":

  ```
  //  m = l + (r - l) / 2
  int m = 0 + (1 - 1) / 2
  ```
  - 1 / 2 is truncated at the decimal, and m = 0.


3. Second Recursive Call | Examine Left Half of Left Half of Array {2} | l = 0, r = 0.

  ```
  merge_sort(arr, 0, 0);
  ```

  - This examines the Left Half of the Left Half of the Array, {2}
  
  - The base case of l == r is reached, and the Second Recursive Call of `merge_sort()` returns.


4. Third Recursive Call | Examine the Right Half of the Left Half of the Array {4} | l = 1, r = 1

- Since the base case of l == r was reached in the Second Recursive Call, that function returned.

- The Second Recursive Call was made from within the First Recursive Call, so the program moves to the next line, which is:

  ```
  merge_sort(arr, m + 1, r);
  ```

  - This is the Third Recursive call, which sorts the Right Half of the Left Half of the Array. 


- Recall that within the First Recursive call:

  - m == 0

  - and 1 has been passed in as r.

- This means that the Third Recursive call is:

  ```
  merge_sort(arr, 1, 1);
  ```

  - This examines the Right half of the Left Half of the Array, {4}

  - The base case of l == r is reached, and the Third Recursive Call of `merge_sort()` returns.


5. First Merge | Merge Left half of Left Half and Right Half of Right Half | {2} and {4}, into {2, 4}

The Second and Third Recursive Calls have both been made from within the First Recursive Call, and both functions have returned.



  






## Psuedo Code and Setup

```
// Prototypes
void merge_sort(int arr[], int left, int right)
void merge(int arr[], int left, int mid, int right)

main:
  unsorted_array = 1, 3, 4, 6, 0, 2, 5, 7
  size = size of unsorted array

  print unsorted array

  merg_sort(unsorted_array, 0, size - 1)

  print sorted array


merge(int arr[], int left, int mid, int right)
{

}

merge_sort(int arr[], int left, int right)
  // gg
  if left < r
    int mid = left + (right - left) / 2

    merge_sort(arr, left, mid)
    merge_sort(arr, m + 1, right)

    merge(arr, left, mid, right)


```


- The first argument is the array. The second and third arguments define the portion of the array we want to examine.

- On the initial call of the function, we want to examine the entire array, or, indices 0 - 3.

- The first thing the function does is find the midpoint: m = 0 + (3 - 0) / 2. 
  - The midpoint == 1, as C truncates everything after the decimal.

  - This creates a conceptual split, dividing the array into:
    * Left Half: {2, 1} (indices 0 - 1)
    * Right Half: {4, 3} (indices 2 - 3)

  - These are Conceptual Subdivisions. They exist only in
  the call stack as index ranges. The original array 
  remains intact, and no addition memory is used to
  create physical sub-arrays.

  - These index ranges define the portion of the array to
  be examined.

2. First Recursive Call | Examine Left Half of Array | l = 0, r = 1

After finding the midpoint and conceptually dividing the array into two halves, the function calls `merge_sort()` recursively, and passes in the middle value (m) as the right-most (r) index, so that the function examines the range between l - m.
```
merge_sort(arr, 0, 1)
```

- Get midpoint: m = 0 (1 - 0) / 2. Midpoint == 0.

- Conceptual Split: Left Half of Array divided into:
  * Left Half: {2} (index 0)
  * Right Half: {1} (index 1)

3. Second Recursive Call | Left Half of Left Half of Array | l = 0, r = 0

From within the first recursive call of `merge_sort()`, the function is called again on the left half, in this case, index 0.
```
merge_sort(arr, 0 , 0)
```

- With a range of indices from 0 - 0, the function is asked to examine a single-element array, {2}.

- Single-element arrays are by nature sorted.

- The Base Case, if (l < r) has been reached, as l == r (0 == 0).

The function (the second recursive call) returns, and the 


## merge() psuedo code
### First Pass
```
#include <stdio.h>

int test_array[] = {1, 3, 2, 4};

// We are examining the whole array, and finding the middle.
// The left (l) index is 0, and the right (r) is 3.
// m = l + (r - l) / 2, which is 1.
int m = 1;

void merge(int arr[], int l, int r, int m)
{
  // Get length of original array.   
  int length = sizeof(test_array) / sizeof(test_array[0]);
  
  // Get length of temp right and left arrays.
  int l_length = (m - l) + 1;
  int r_length = r - m;

  // Declare temp arrays.
  int left[l_length], right[r_length];

  // Copy left half of arr into left array.
  for (int i = 0; i < l_length; i++)
  {
    left[i] = arr[i];
  }

  // Copy right half of arr into right array.
  for (int i = 0; i < l_length; i++)
  {
    right[i] = arr[i];
  }

  // Check to see if either side is longer than the other.
  if (l_length == r_length)
  {

    // First Assumption: l_length == r_length
    // While index < (length - 1):
      // Declare current left, right, and array index.
      // int index = 0;
      // int l_index = 0;
      // int r_index = 0;

      // Examine for array[0]
      // if left[l_index] <= right[r_index]
        // array[index] = left[l_index]
        // index++
        // l_index++
      // Else:
        // array[index] = right[r_index]
        // index++
        // r_index++  
  }
  // else:
  {
    // Second Assumption: l_length != r_length
    // l_length will be the longer of the two
    // Iterate through left and right arrays as far as they are of equal length.
    // While index < (length - 2)
      // Declare current left, right, and array index.
      // int index = 0;
      // int l_index = 0;
      // int r_index = 0;

      // if left[l_index] <= right[index]
        // array[index] = left[l_index]
        // index++
        // l_index++
      // Else:
        // array[index] = right[r_index]
        // index++
        // r_index++

      // Compare Left Over Element

      // Suppose {1, 5, 100} and {6, 90}
        // First pass: 1 or 6             | Result: {1}
        // Second pass: 5 or 90           | Result: {1, 5}
        // Third pass: 100 or 6           | Result: {1, 5, 6}
        // Fourth pass: 100 or 90         | Result: {1, 5, 6, 90}
        // Leftover Character: 100 or 90  | Result {1, 5, 6, 90, 100}

      // Suppose {1, 5, 90} and {100, 110}}
        // First pass: 1 or 100           | Result: {1]
        // Second pass: 5 or 100          | Result: {1, 5}
        // Third pass: 90 or 100          | Result: {1, 5, 90}
        // Fourth pass: nothing left in left array, two elements in right array.
  } 
}
```

### Second Pass
```
// One array can empty out before the other, so no matter how many elements in each array, it is possible to have "left over elements," in one array while the other is empty.

// Rather than make assumptions about the size of the array, it is best to have a way to handle left over elements.

// This means keeping track of how many elements in the left and right arrays, respectively, have been allocated to their correct ordered index in the sorted array.

void merge(int arr[], int l, int r, int m)

  // Get length of original array.
  int length = sizeof(arr) / sizeof(arr[0]);

  // Get length of temp right and left arrays.
  int l_length = (m - l) + 1;
  int r_length = r - m;

  // Declare temp arrays.
  int left[l_length], right[r_length];

  // Copy left half of arr[] into left[].
  for (int i = 0; i < l_length; i++)
  {
    left[i] = arr[i];
  }

  // Copy right half of arr[] into right[].
  for (int i = m + 1; i < length; i++)
  {
    right[i] = arr[i];
  }

  int left_elements_allocated = 0;
  int right_elements_allocated = 0;
  int arr_index = 0;
  int l_index = 0;
  int r_index = 0;

  while left_elements_allocated <= l_length and right_elements_allocated <= r_length:
    
    if left[l_index] <= right[r_index]:
      arr[arr_index] = left[l_index]
      l_index++
      arr_index++
    else:
      arr[arr_index] == right[r_index]
      r_index++
      arr_index++

  // Check to see if any elements remain in either array.
  while l_index < l_length:
    arr[arr_index] = left[l_index]
    l_index++
    arr_index++ 

  while r_index < r_length:
    arr[arr_index] = right[r_index]
    r_index++
    arr_index++ 
```

### Third Pass

* Here is a working function that copies the left and right halves of an array into left and right temp arrays. No sorting or acounting for leftover elements is done yet.

```
#include <stdio.h>

// Prototypes
void print_array(int arr[], int length);
void merge(int arr[], int l, int r, int m);

int main(void)
{
  int test_array[] = {1, 3, 2, 4};
  int length = sizeof(test_array) / sizeof(test_array[0]);
  
  print_array(test_array, length);

  merge(test_array, 0, 3, 1);
}

void merge(int arr[], int l, int r, int m)
{
  
  // Get length of temp right and left arrays.
  int l_length = (m - l) + 1;
  int r_length = r - m;
  int length = l_length + r_length; 

  // Get the left index of the right temp array.
  int lr_index = m + 1;  

  // Declare temp arrays.
  int left[l_length], right[r_length];

  // Copy left half of arr[] into left[].
  for (int i = 0; i < l_length; i++)
  {
    left[i] = arr[i];
  }

  for (int i = lr_index; i < length; i++)
  {
    right[i - lr_index] = arr[i];
  }
  
  printf("left array: ");
  print_array(left, l_length);
  printf("right array: ");
  print_array(right, r_length);
}

void print_array(int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%i", arr[i]);
  }
  printf("\n");
}
```
  
