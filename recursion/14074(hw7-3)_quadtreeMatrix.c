#include <stdio.h>
#include <string.h>

char map[128][128];
char ans[16400][10];

// given position (x,y) fill square length = n with value '1' in map
void fillsqure(int x, int y, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      map[x + i][y + j] = '1';
    }
  }
  return;
}

// given pair i and idx t in array > ans[i] i-th pair of values
// ex: ans[0]= {'1','1','2'}
// t : idx in 2nd array, t start from 1
// t : how many time we slice, determine how large we span the square(when t+1 >> n/2)
// t is also the position of string = ans[i][t]
// value: decide how we move the position (x,y)
// value =  1 move P from given (x,y) to (x,y+n/2)
// n will be n/2 each time call recursive function, (x,y) is new P from last recursive function

void getP(int x, int y, int n, int t, int i)
{
  // base (terminate)
  // printf("t: %c\n", ans[i][t]);
  if (ans[i][t] == '\0')
  {
    // printf("(%d, %d),n: %d, t: %d\n", x, y, n, t);
    fillsqure(x, y, n);
    return;
  }
  // recursive
  if (ans[i][t] != '\0')
  {
    int value = ans[i][t] - '0'; // value decide how we move the position (x,y)
    if (value == 0)
    {
      // printf("(%d,%d)\n", x, y);
      getP(x, y, n / 2, t + 1, i);
    }
    else if (value == 1)
    {
      getP(x, y + n / 2, n / 2, t + 1, i);
    }
    else if (value == 2)
    {
      getP(x + n / 2, y, n / 2, t + 1, i);
    }
    else if (value == 3)
    {
      getP(x + n / 2, y + n / 2, n / 2, t + 1, i);
    }
  }
}

int main()
{
  // input
  int count;
  scanf("%d", &count);

  for (int i = 0; i < count; i++)
  {
    char string[10];
    scanf("%s", string);
    // strcpy(ans[idx], string);
    int j = 0;
    while (string[j] != '\0')
    {
      ans[i][j] = string[j];
      j++;
    }
  }

  // span whole map
  for (int i = 0; i < 128; i++)
  {
    for (int j = 0; j < 128; j++)
    {
      map[i][j] = '0';
    }
  }

  int R, C;
  scanf("%d %d", &R, &C);

  // 3*5 > 8

  int max = (R >= C) ? R : C;
  int n = 1;
  for (int i = 0; i < 8; i++)
  {
    n *= 2;
    if (n >= max)
      break;
  }

  // recursive
  for (int i = 0; i < count; i++)
  {
    getP(0, 0, n, 1, i); // t start with 1
  }

  // print the matrix
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (i == R - 1 && j == C - 1)
        printf("%c", map[i][j]);
      else if (i != R - 1 && j == C - 1)
        printf("%c\n", map[i][j]);
      else
        printf("%c ", map[i][j]);
    }
  }

  return 0;
}
