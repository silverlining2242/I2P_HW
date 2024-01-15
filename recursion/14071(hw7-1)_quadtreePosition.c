#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int count = 0;
int temp[10]; // value of position (output: 112, 113)
int ans[16500][10];
int a[128][128] = {0}; // declare map globally

int homo(int x, int y, int l)
{
  int v;
  v = a[x][y];
  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < l; j++)
    {
      if (a[x + i][y + j] != v)
      {
        return 0;
      }
    }
  }
  return 1; // means it's homo
}

void getP(int x, int y, int n, int t) // n=8
{
  int v = a[x][y];
  int check = homo(x, y, n);
  // all homo > put it into array
  if (check == 1)
  {
    if (v == 1)
    {
      for (int i = 0; i < t; i++)
      {
        ans[count][i] = temp[i];
      }
      // after it is homo, t will plus 1;
      ans[count][t] = -1; // mark the end, like string terminator \0 to print
      count++;
    }
    return;
  }

  // not homo > split into 4
  if (check == 0)
  {
    temp[t] = 0; // value of position, t position of temp: depth(times of recursive func being executed)
    getP(x, y, n / 2, t + 1);
    temp[t] = 1;
    getP(x, y + n / 2, n / 2, t + 1);
    temp[t] = 2;
    getP(x + n / 2, y, n / 2, t + 1);
    temp[t] = 3;
    getP(x + n / 2, y + n / 2, n / 2, t + 1);
  }
}

int main()
{
  // input
  int R, C;
  scanf("%d %d", &R, &C);

  // input matrix
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      scanf(" %d", &a[i][j]);
      // getchar();
    }
    // getchar();
  }
  // 3*5 >> 8 * 8
  int max = (R >= C) ? R : C;
  int n = 2;
  for (int i = 0; i < 7; i++)
  {
    n = n * 2;
    if (n >= max)
      break;
  }

  // func

  getP(0, 0, n, 0); // t start from 0
  printf("%d\n", count);

  // print each
  for (int i = 0; i < count; i++)
  {
    printf("1");
    int j = 0;
    while (ans[i][j] != -1)
    {
      printf("%d", ans[i][j]);
      j++;
    }
    printf("\n");
  }

  // print check
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     printf("%d", a[i][j]);
  //   }
  //   printf("\n");
  // }

  return 0;
}
