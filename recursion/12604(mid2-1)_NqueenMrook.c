#include <stdio.h>
int n, m, size, sol;
int map[10][10];

int issafe(int row, int col, int mode) // mode 0: check Q, mode 1: check R
{
  // check row has Q
  for (int j = 0; j < col; j++)
  {
    if (map[row][j]) // r is 1
      return 0;
  }
  // check col has Q
  for (int i = 0; i < row; i++)
  {
    if (map[i][col])
      return 0;
  }
  // check left to right'\'
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
  {
    if (map[i][j]) // if met Q and it's mode is to check R, then skip
    {
      if (map[i][j] == -1 && mode == 1) // if itself is R and mode is check R,
        continue;
      else
        return 0;
    }
  }
  // check right to left'/'
  for (int i = row, j = col; i < size && j >= 0; i++, j--)
  {
    if (map[i][j]) // if met Q
    {
      if (map[i][j] == -1 && mode == 1) //
        continue;
      else
        return 0;
    }
  }
  return 1;
}

void recur(int col, int numQ, int numR)
{
  // base case
  if (col == size)
  {
    sol++;
    return;
  }
  // check rook

  for (int i = 0; i < size; i++)
  {
    // place queen
    if (numQ < n)
    {
      if (issafe(i, col, 0)) // check Q mode = 0
      {
        map[i][col] = 1; // queen is 1
        recur(col + 1, numQ + 1, numR);
        map[i][col] = 0; // **back to origin
      }
    }
    // place rook
    if (numR < m)
    {
      if (issafe(i, col, 1)) // check R mode = 1
      {
        map[i][col] = -1; // rook is -1
        recur(col + 1, numQ, numR + 1);
        map[i][col] = 0; // back to origin
      }
    }
  }
}

int main()
{
  // input
  while (scanf("%d %d", &n, &m) != EOF)
  {
    size = n + m;

    // initialize map
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        map[i][j] = 0;
      }
    }

    // to original
    sol = 0;
    recur(0, 0, 0);
    printf("%d\n", sol);
  }

  return 0;
}