#include <stdio.h>

void bubblesort(int *ap, int n)
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (ap[j] > ap[j + 1])
      {
        temp = ap[j];
        ap[j] = ap[j + 1];
        ap[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int arr[] = {5, 2, 9, 1, 5, 6};          // Your array of integers
  int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

  bubblesort(arr, size); // Call bubblesort passing the array and its size

  printf("Sorted array: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]); // Print the sorted array
  }
  printf("\n");

  return 0;
}