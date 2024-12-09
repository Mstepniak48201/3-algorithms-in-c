#include <stdio.h>

// Prototypes
void bubble_sort(int arr[], int size);
void print_array(int arr[], int size);

int main(void)
{
  // Unsorted array
  int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};

  // Get array size.
  int size = sizeof(numbers) / sizeof(numbers[0]);

  // Print unsorted array.
  printf("Unsorted array:\n");
  print_array(numbers, size);

  // Sort array.
  bubble_sort(numbers, size);

  // Print sorted array.
  printf("Sorted array:\n");
  print_array(numbers, size);

  return 0;
}

void bubble_sort(int arr[], int size)
{
  // Outer loop
  for (int i = 0; i < size - 1; i++)
  {
    // Variable to check if swap has been made
    // Reset swap checker to 0 on each pass through the loop.
    int swapped = 0;

    // Inner loop
    for (int j = 0; j < size - i - 1; j++)
    {
      // Compare current unsorted element with adjacent element.
      if (arr[j] > arr[j + 1])
      {
        // Store current (larger) element in temp variable.
        int temp = arr[j];

        // Move adjacent (smaller) value at j + 1 down to j.
        arr[j] = arr[j + 1];

        // Move larger value stored in temp up to j + 1.
        arr[j + 1] = temp;

        // Mark that a swap occurred.
        swapped = 1;
      }
    }

    // If swapped == 0, the array is sorted.
    // If array is sorted, break out of the loop.
    if (!swapped)
    {
      break;
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
