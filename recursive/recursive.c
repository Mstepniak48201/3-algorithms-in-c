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
        // arry[index] = right[r_index]
        // index++
        // r_index++
  }


  
}



