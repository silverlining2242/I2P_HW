#include <stdio.h>

void insertion_sort(int *ap, int n)
{
  int temp;
  int i, j;

  for (i = 1; i <= n - 1; i++)
  {
    temp = *(ap + i);

    j = i - 1;
    while ((j >= 0) && (*(ap + j) > temp))
    {
      // Move the content to the next cell
      *(ap + j + 1) = *(ap + j);
      j--; // update j
    }
    // move content in temp back to the array
    *(ap + j + 1) = temp;
  }
}
