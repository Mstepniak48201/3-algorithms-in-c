#include <stdio.h>

// Prototypes
void selection_sort(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{ 
  // Unsorted Array
  int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};

  // Get size of array.
  int size = sizeof(numbers) / sizeof(numbers[0]);

  // Print unsorted array.
  printf("Unsorted array:\n");
  print_array(numbers, size);

  // Sort array.
  selection_sort(numbers, size);

  // Print sorted array.
  printf("Sorted Array:\n");
  print_array(numbers, size);

  return 0;
}


void selection_sort(int arr[], int size)
{
  // Iterate over arr, offsetting by 1 to prevent
  // attempt to compare to a non-existant int.
  for (int i = 0; i < size - 1; i++)
  {


    // First, or current Unsorted Element in the array to be replaced with the smalled value.
    int min_index = i;
  
    // Compare arr[i] and arr[j]
    // min_index will be set to the smallest value between those two.
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[min_index])  
      {
        // If arr[j] < arr[i], its value will be assigned to min_index.
        // Otherwise, min_index will remain as i.
        min_index = j;
      }
    }

    // Check that i and min_index aren't the same before attempting update.
    // If min_index == i, everything will stay the same, with no need to swap values.
    if (min_index != i)
    {
      // Store the value of arr[i] in a temporary variable.
      // We are about to put the value at arr[min_index] (which is now arr[j]) in place of
      // the value at arr[i].
      // We need to hold on to the value of arr[i] so we can place it at arr[j].
      int temp_i = arr[i];
      
      // arr[min_index] is arr[j].
      // arr[i] is the current element in the outer loop.
      // The value of arr[j] is assigned to arr[i].
      arr[i] = arr[min_index];

      // Now that min_index = j, we swap th displaced value that was formerly at arr[i]
      // will be swapped to the space formerly occupied by the smaller value.
      // In effect, this means: arr[j] = temp_i
      arr[min_index] = temp_i;
    }

  }
}

void print_array(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%i", arr[i]);
  }
  printf("\n");
}
