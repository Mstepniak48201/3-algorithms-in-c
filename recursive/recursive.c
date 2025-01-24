#include <stdio.h>

// Prototypes
void print_array(int arr[], int length);
void merge(int arr[], int l, int r, int m);

int main(void)
{
  int test_array[] = {1, 5, 100, 6, 90};
  int length = sizeof(test_array) / sizeof(test_array[0]);
  
  print_array(test_array, length);

  merge(test_array, 0, 4, 2);
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

  // Declare index variables to track status of merge
  // for the original array, left and right temp arrays.
  // Altering the original array will always occur at the 
  // l value.
  int arr_i = l;
  int left_i = 0;
  int right_i = 0;

  // Copy left half of arr[] into left[].
  for (int i = 0; i < l_length; i++)
  {
    left[i] = arr[i];
  }

  // Copy right half of arr[] into right[].
  for (int i = lr_index; i < length; i++)
  {
    right[i - lr_index] = arr[i];
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
