#include <stdio.h>
char A[3][3], B[3][3];
void copy(char A[][3], char C[][3]) // from A to C
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      C[i][j] = A[i][j];
    }
  }
}
int ifsame(char a[][3], char b[][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (a[i][j] != b[i][j])
      {
        return 0;
      }
    }
  }
  return 1;
}

int f(int step, char A[3][3], char B[3][3], int x, int y)
{
  int check = ifsame(A, B);
  // base case: only when step == 0, terminate recursion
  if (step == 0)
  {
    return (ifsame(A, B)) ? 1 : 0;
  }

  // use C to swap, and remain A intact, **C must be local!
  char C[3][3];
  //int temp; // place here
  // up
  copy(A, C);
  if (x >= 1)
  {
    // printf("1\n");
    int temp = C[x][y];
    C[x][y] = C[x - 1][y];
    C[x - 1][y] = temp;
    // keep recursion inside
    if (f(step - 1, C, B, x - 1, y)) // use new map (C, B), new position(x-1) to check the branch
    {
      // printf("1check");
      check = 1;
    }
  }

  // left
  copy(A, C);
  if (y >= 1)
  {
    // printf("2\n");
    int temp = C[x][y];
    C[x][y] = C[x][y - 1];
    C[x][y - 1] = temp;
    if (f(step - 1, C, B, x, y - 1))
    {
      // printf("2check");
      check = 1;
    }
  }
  // down
  copy(A, C);
  if (x < 2)
  {
    // printf("3\n");
    int temp = C[x][y];
    C[x][y] = C[x + 1][y];
    C[x + 1][y] = temp;
    if (f(step - 1, C, B, x + 1, y))
    {
      // printf("3check");
      check = 1;
    }
  }

  // right
  copy(A, C);
  if (y < 2)
  {
    // printf("4\n");
    int temp = C[x][y];
    C[x][y] = C[x][y + 1];
    C[x][y + 1] = temp;
    if (f(step - 1, C, B, x, y + 1))
    {
      // printf("4check");
      check = 1;
    }
  }

  // **after check each branch return check!!!
  return (check) ? 1 : 0;
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    int k;
    scanf("%d", &k);
    int x, y;

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        scanf(" %c", &A[i][j]);
        if (A[i][j] == 'x') // only 1 x
        {
          x = i;
          y = j;
        }
      }
    }
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        scanf(" %c", &B[i][j]);
      }
    }

    // output each testcase
    if (f(k, A, B, x, y))
      printf("Yes\n");
    else
      printf("No\n");
  }
}
