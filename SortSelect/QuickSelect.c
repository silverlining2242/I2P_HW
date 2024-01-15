/*https://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html*/
// Quickselect is a powerful algorithm for finding the kth smallest element in an unordered list.
#include <iostream>
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
int Partition(int *arr, int front, int end)
{
  int pivot = arr[end];
  int i = front - 1;
  for (int j = front; j < end; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  i++;
  swap(&arr[i], &arr[end]);
  return i;
}
void QuickSort(int *arr, int front, int end)
{
  if (front < end)
  {
    int pivot = Partition(arr, front, end);
    QuickSort(arr, front, pivot - 1);
    QuickSort(arr, pivot + 1, end);
  }
}
void PrintArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
int main()
{

  int n = 9;
  int arr[] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
  std::cout << "original:\n";
  PrintArray(arr, n);

  QuickSort(arr, 0, n - 1);

  std::cout << "sorted:\n";
  PrintArray(arr, n);
  return 0;
}

/*
    original : 9 4 1 6 7 3 8 2 5 
    sorted :   1 2 3 4 5 6 7 8 9

*/
