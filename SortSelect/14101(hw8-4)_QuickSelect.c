#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// Quickselect is a powerful algorithm for finding the kth smallest element in an unordered list.
/*this is partial judge for SwapString and Partition*/
/*https://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html*/
void SwapString(char **str1, char **str2)
{
  char *temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}

int Partition(char **A, int l, int r) // it can compare a string inside!
{
  char *pivot = A[r];         // use the most right
  int i = l - 1;              // i start from -1
  for (int j = l; j < r; j++) // not include r
  {
    if (strcmp(A[j], pivot) < 0)
    // strcmp if two equals return 0/ str1 > str2 return > 0/ str1 < str2 return < 0
    {
      i++; // move one to swap
      SwapString(A[i], A[j]); //without & is okay
    }
  }
  // final step
  i++;
  SwapString(&A[i], &A[r]); //**r
  return i; // it will return idx of pivot(middle one)
}

char *Select(char **A, int l, int r, int k) // l = 0, r is total names  -1, idx- k smallest
{
  while (l < r) //loop to find the k-th smallest
  {
    int m = Partition(A, l, r); // index of pivot inside the range not whole array
    if (m == k)                 // k-th smallest = pivot, then Xk = pivot
      return A[m];
    if (m < k) // pivot index < k
      l = m + 1;
    else
      r = m - 1;
  }
  return A[l]; //*return the string
}

int main()
{
  int N, k; // n strings, k-th smallest
  char buff[1000];
  scanf("%d\n", &N);
  char **Names = (char **)malloc(N * sizeof(char *)); //**pointer point to the string set
  for (int i = 0; i < N; i++)
  {
    scanf("%s",buff);//get(buff); // read a line from stdin and stores it into the string buff
    Names[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char));
    //+1 space for \0
    // Name[i] is the memory address of each name's string start address
    strcpy(Names[i], buff); // copy the pointer of buff to pointer name[i]
  }

  scanf("%d", &k);                                // find k-th smallest
  printf("%s\n", Select(Names, 0, N - 1, k - 1)); // N, k trans to index start from 0

  // free up space
  for (int i = 0; i < N; i++)
  {
    free(Names[i]);
  }

  free(Names);
}
