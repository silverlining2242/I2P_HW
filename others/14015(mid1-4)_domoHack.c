#include <stdio.h>

void FirstLastRow(int N, int R, int RowNum, int row[])
{
  int Loop = 2 * R - 2; // 1 + 6=  7 + 6 = 13 , 6 = 2R-2
  // when or not to assign \0 to the end??
  row[0] = RowNum;
  int i = 0;
  while (row[i] <= N) // at the end of while i++, so when check row[i+1]>just row[i]
  {
    row[i + 1] = row[i] + Loop;
    // printf("%d ", row[i + 1]);// N R = 14 4, it will have redundant row[3]=19 but not print out in main
    i++; // after loop i = 2 (which is out of N)
  }
}

void MiddleRow(int N, int R, int RowNum, int row[])
{
  int Loop = 2 * R - 2;
  row[0] = RowNum;
  row[1] = row[0] + (Loop - (RowNum - 1) * 2); // find 1st in between number
  int i = 0;
  // one block to row[0,2,4 item]
  while (row[i] <= N)
  {
    row[i + 2] = row[i] + Loop;
    i = i + 2;
  }
  // number in the middle of block to row [1,3,5 item]
  i = 1; // reassign i !!
  while (row[i] <= N)
  {
    row[i + 2] = row[i] + Loop;
    i = i + 2;
  }
}

void print(int row[], int N)
{
  for (int i = 0; row[i] <= N; i++)
  {
    printf("%d ", row[i]);
  }
}

int main()
{
  int N, R;
  scanf("%d %d", &N, &R);

  int row[10000];
  // must put Nerror:definition of variable with array type needs an explicit size or an initializer

  FirstLastRow(N, R, 1, row);
  print(row, N);
  for (int i = 2; i < R; i++)
  {
    MiddleRow(N, R, i, row);
    print(row, N);
  }
  FirstLastRow(N, R, R, row);
  // in the end no space but newline
  for (int i = 0; row[i] <= N; i++)
  {
    row[i + 1] > N ? printf("%d", row[i]) : printf("%d ", row[i]);
  }

  printf("\n");

  return 0;
}
