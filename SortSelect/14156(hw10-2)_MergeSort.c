/*combine all
https://www.geeksforgeeks.org/c-program-for-merge-sort/?ref=gcse
*/
#include <stdio.h>
#include <stdlib.h>
/*this is partial judge, only complete merge*/
void merge(int *, int, int, int);
void mergeSort(int *, int, int);
void printArray(int[], int);

void mergeSort(int *arr, int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2; // middle point

    mergeSort(arr, l, m);           // include m
    printArray(arr + l, m - l + 1); // need to print from arr + l !!

    mergeSort(arr, m + 1, r); // not include m
    printArray(arr + m + 1, r - m);

    merge(arr, l, m, r);
  }
}

void printArray(int A[], int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (i != 0)
      printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main()
{
  int size;

  scanf("%d", &size);

  int *arr = (int *)malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++)
  {
    // int num;
    // scanf("%d", &num);
    // arr[i] = num;
    scanf("%d", &arr[i]);
  }

  mergeSort(arr, 0, size - 1);

  printArray(arr, size);
  free(arr);
  return 0;
}

void merge(int *arr, int l, int m, int r)
{
  int i, j, k;        // idx for L, R, arr
  int n1 = m - l + 1; // length of left part
  int n2 = r - m;     // length of right part

  // Create temp arrays
  int L[n1], R[n2]; //?

  // Copy data to temp arrays L[] and R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j]; // not include m

  // Merge the temp arrays back into arr[l..r]

  i = 0;                   // Initial index of first subarray
  j = 0;                   // Initial index of second subarray
  k = l;                   // **Initial index of merged subarray
  while (i < n1 && j < n2) // **can't use: i < n1 || j < n2
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if there are any
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if there are any
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}