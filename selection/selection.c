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
  return 0;
}

void print_array(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%i", arr[i]);
  }
  printf("\n");
}
