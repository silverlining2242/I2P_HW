#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Swap(char **str1, char **str2)
{
  char *temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}

int Partition(char **A, int l, int r)
{
  char *pivot = A[r];
  int i = l - 1;
  for (int j = l; j < r; j++)
  {
    if (strcmp(A[j], pivot) < 0)
    {
      i++;
      Swap(&A[i], &A[j]);
    }
  }
  i++;
  Swap(&A[i], &A[r]);

  return i;
}

char *Select(char **A, int l, int r, int k)
{
  while (l < r)
  {
    int m = Partition(A, l, r);
    if (m == k)
      return A[m];
    else if (m < k)
      l = m + 1;
    else
      r = m - 1;
  }
  return A[l];
}

int main()
{
  int n;
  scanf("%d", &n);

  char **name = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++)
  {
    char temp[20];
    scanf("%s", temp);
    int len = strlen(temp);
    name[i] = (char *)malloc(sizeof(char) * len + 1);
    strcpy(name[i], temp);
  }
  int k;
  scanf("%d", &k);
  // exe
  printf("%s\n", Select(name, 0, n - 1, k-1));

  // free
  for (int i = 0; i < n; i++)
  {
    free(name[i]);
  }
  free(name);

  return 0;
}