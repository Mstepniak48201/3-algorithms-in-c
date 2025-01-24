#include <stdio.h>

// Prototypes
void print_array(int arr[], int length);
void merge(int arr[], int l, int r, int m);

int main(void)
{
  int test_array[] = {3, 1};
  int length = sizeof(test_array) / sizeof(test_array[0]);
  
  print_array(test_array, length);

  merge(test_array, 0, 1, 0);
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

  // Copy right half of arr[] into right[].
  for (int i = lr_index; i < length; i++)
  {
    right[i - lr_index] = arr[i];
  }
    
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
