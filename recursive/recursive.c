#include <stdio.h>

// Prototypes
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int r, int m);
void print_array(int arr[], int length);

int main(void)
{
  int test_array[] = {1, 5, 100, 6, 90};
  int length = sizeof(test_array) / sizeof(test_array[0]);
  
  printf("unsorted test array: ");
  print_array(test_array, length);

  merge_sort(test_array, 0, length - 1);

  printf("sorted test array: ");
  print_array(test_array, length);
   
  
  // merge(test_array, 0, 4, 2);
}

void merge_sort(int arr[], int l, int r)
{
  // Set base case for single element or empty array.
  if (l >= r)
  {
    return; 
  }

  // Get midpoint index.
  int m = l + (r - l) / 2;

  // Sort left half.
  // Pass in l instead of 0. The value of l will change when sorting
  // the left halves of right halves.
  merge_sort(arr, l, m);

  // Sort right half.
  merge_sort(arr, m + 1, r);

  // Merge sorted arrays.
  merge(arr, l, r, m);
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

  // Variables to increment elements to be copied from original array to left[] and right[].
  int l_cp_index = l;
  int r_cp_index = m + 1;

  // Variable to increment the current index of the original array being modified.
  int arr_i = l;

  // Variables to track temp array elements processed.
  int left_i = 0;
  int right_i = 0;

  // Copy left half of arr[] into left[].
  for (int i = 0; i < l_length; i++)
  {
    left[i] = arr[l_cp_index];
    l_cp_index++;
  }

  // Copy right half of arr[] into right[].
  for (int i = 0; i < r_length; i++)
  {
    right[i] = arr[r_cp_index];
    r_cp_index++;
  }

  // Now that the arrays are copied, compare them.
  // Keep track of the index set for the original array,
  // and the indices of the left and right arrays.
  // If the left or right index exceeds its length, exit
  // the loop.
  while (left_i < l_length && right_i < r_length)
  {
    if (left[left_i] <= right[right_i])
    {
      arr[arr_i] = left[left_i];
      left_i++;
    }
    else
    {
      arr[arr_i] = right[right_i];
      right_i++;
    }
    arr_i++;
  }

  // Copy remaining elements from left array.
  while (left_i < l_length)
  {
    arr[arr_i] = left[left_i];
    arr_i++;
    left_i++;
  }

  // Copy remaining elements from right array.
  while (right_i < r_length)
  {
    arr[arr_i] = right[right_i];
    arr_i++;
    right_i++;
  }

  /*
  printf("First char of array: \n");
  printf("%i\n", arr[0]);
    
  printf("Second char of array: \n");
  printf("%i\n", arr[1]);
  
  printf("Sorted Array: \n");
  print_array(arr, length);


  printf("left: ");
  print_array(left, l_length);

  printf("right: ");
  print_array(right, r_length);  
  */
}

void print_array(int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%i", arr[i]);
  }
  printf("\n");
}

  
// One array can empty out before the other, so no matter how many elements in each array, it is possible to have "left over elemnts," in one array while the other is empty.

// Rather than make assumptions about the size of the array, it is best to have ways to handle left over elements.

// This means keeping track of how many elements in the left and right arrays, respectively, have been allocated to their correct ordered index in the sorted array.
  
  // Plan for a possible odd number of elements. If this is the case, the left array will always be larger.

  // Alter code to expect l parameter in recursive function to be length - 1.  // Compare left[0] and right[0]
  // If left[0] <= right[0]:
    // Copy left[0] to arr[0]
  // Else;
  // Compare left[0] and right[0]
  // If left[0] <= right[0]:
    // Copy left[0] to arr[0]
  // Else;
  // Compare left[0] and right[0]
  // If left[0] <= right[0]:
    // Copy left[0] to arr[0]
  // Else;
