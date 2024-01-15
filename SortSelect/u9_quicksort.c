/*
https://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html
*/
#include <stdio.h>
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
// find a pivot and put #smaller on the left, #larger on the right of pivot and put pivot in the middle
int Partition(int *arr, int front, int end) // front 0 ~ end 8
{
  int pivot = arr[end];             // assume to use pivot as end of the string
  int i = front - 1;                // i is from -1 ~ 8, as every number may all be smaller than pivot, i is the index of number that is smaller than pivot
  for (int j = front; j < end; j++) // j is from 0-8// iteration inside the array index
  {
    if (arr[j] < pivot)
    {
      i++;                    // move from -1 to 0, means we found 1 number(index= 0) is smaller than pivot
      swap(&arr[i], &arr[j]); // swap arr[i] with previous arr[j], which is larger than pivot
      // if the first arr[j=0] smaller than pivot >>perform swap(&arr[0], &arr[0])
    }
  }
  // after loop, it is smaller group> larger group> pivot,
  i++;                      // move smaller index + 1
  swap(&arr[i], &arr[end]); // swap the pivot to the i++(in the middle) smaller> pivot > larger
  return i;                 // index of pivot
}
void QuickSort(int *arr, int front, int end) // front beginning index 0, end = n-1
{
  if (front < end) // if only one element left front 5, end = pivot = 5, it's not <
  {
    int pivot = Partition(arr, front, end); // pivot's index place
    QuickSort(arr, front, pivot - 1);       // keep recur on smaller group on the left of pivot
    QuickSort(arr, pivot + 1, end);         // keep recur on larger group on the right of pivot
  }
}
void PrintArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main()
{

  int n = 9;
  int arr[] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
  printf("original: \n");
  PrintArray(arr, n);

  QuickSort(arr, 0, n - 1);

  printf("original: \n");
  PrintArray(arr, n);
  return 0;
}