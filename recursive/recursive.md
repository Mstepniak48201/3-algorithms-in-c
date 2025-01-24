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
  
### Fourth Pass: Understanding the merge

* Assumption 1: two single-element arrays

```
int left[] = {1};
int right[] = {3};
```
1. Original call has {1, 3} passed in, l == 0, r == 1.
2. First recursive call: m == 0 passed in as right-most value "r."
3. First recursive call finds l == r (single-element array) and returns.
4. From within Original call, the Second recursive call: 1 and 1 passed in for l and r. l == r -> Second recursive call returns.
5. From within Original call, merge() is called.
6. Copy the arrays into temp arrays, compare the contents, and copy them, in order, into the original array.


* Assumption 2: {4, 1, 3, 2}

1. Original Call: 
```
merge_sort(int arr[], int l, int r)
```
arr == {4, 1, 3, 2}
l = 0
r = 3
-> m = 1

2. First Recursive Call (Left Half):
```
merge_sort(arr, 0, m)
```
- Args
  l = 0
  r = m (m = 1 in Original call)

new m calculated -> m = 0

3. Second Recursive Call (Left Half of Left Half):
```
merge_sort(arr, 0, m)
```
- Args
  l = 0
  r = m (m = 0 in First Recursive Call)

Base case reached -> l == r, single element array, function returns.

4. Third Recursive Call (Right Half of Left Half):
- The Second Recursive Call was made from within the First Recursive Call.
- Since that Call of `merge_sort()` returned, the program moves to the next line:
```
merge_sort(arr, m + 1, r)
```
- Args
  l = 1
  r = 1

Base case reached -> l == r, single element array, function returns.

5. merge() is called.
- The Third Recursive Call was made from within the First Recursive Call.
- Since that call of `merge_sort()` returned, the program moves to he next line:
```
// function with args
merge(int arr[], int l, int r, int m)

// function as called
merge(arr, 0, 1, 0)
```
- Args
  l = 0
  r = 1
  m = 0

- merge() takes the left half (elements at indices <= m) and compares it to the right half (elements with indices > m)

- In this case, there are two single-element arrays:
  - left: {4}
  - right: {1}

- merge() takes the elements {4} at arr[0] - arr[m] and copies them into a temporary array.

- merge() takes the elements {1} at arr[m + 1] - arr[r] and copies them into a temporary array.

- merge then iterates over the elements in both arrays and copies them into the original array at the correct index. The First Recursive Call examines the Left Half, sothe relevant indices are 0, 1, which are the values for l and r.

```
// Declare index variables for the original array, and the left and right temp arrays.
arr_i = l 
left_i = 0
right_i = 0

// Keep track of the index that has been set in the original array, as well as the indexes of the left and right arrays.
// If the left or right index exceeds its length, exit the loop
while (left_i < l_length && right_i < r_length)
{
  if (left[left_i] <= right[right_i]) 
  {
    arr[arr_i] = left[left_i]
    left_i++
  }
  else
  {
    arr[arr_i] = right[right_i]

    right_i++
  }
  arr_i++
}

// Copy any remaining elements from left array.
while (left_i < l_length)
{
  arr[arr_i] = left[left_i]
  arr_i++
  left_i++
}

// Copy and remaining elements from right array.
while (right_i < r_length)
{
  arr[arr_i] = right[right_i]
  arr_i++
  right_i++
}


```


How do we figure out what index of the array to mutate?

First call of merge(left: 0, right: 1, middle: 0) 
- Made from within the First Recursive Call
- We want to mutate indices 0, 1.
- Compares {4}, and {1}, and places them, in order, into original array.
- Places {1}, {4} into arr[0] and arr[1]


Second call of merge() 
- Made from within the Fourth Recursive Call
- We want to mutate indices 2, 3.
- Compares {3}, and {2} and places them, in order, into original array.
- Places {2}, {3} into arr[2] and arr[3]


Third call of merge()
- Made from within the original call of merge()
- Original array now looks like {1, 4, 2, 3}
- Compare {1, 4} and {2, 3}
- Reorder and place elements into order: {1, 2, 3, 4}








