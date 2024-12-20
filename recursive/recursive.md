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

## Working through the logic

Let's start with a test array, a look at the recursive function, and work through the logic.

```
// Test array
int arr[] = {2, 1, 4, 3};

// Get length of Array. Remember that sizeof() will return the number of characters in the array.
// We want the length, 0-indexed. The 0-indexed length will == size - 1
int length = (sizeof(arr) / sizeof(arr[0])) - 1;

// Function
// Pass in arr, 0 for l (left index), and length for r (right index)
void merge_sort(int arr[], int l, int r)
{
  if (l < r)
  {
    // Get midpoint index.
    int m = l + (r - l) / 2;

    // Sort left half.
    merge_sort(arr, l, m);

    // Sort right half.
    merge_sort(arr, m + 1, r);

    // Call function that merges sorted arrays.
    merge_sorted_arrays(int arr, int l, int m, int r); 
  }
}
```

Let's break this down from the perspective of the Call Stack.

1. Initial Call | Entire array is passed in | l = 0, r = 3
```
// Pass in 0 for l, length for r.
merge_sort(arr, 0, 3)
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


