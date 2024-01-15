#include <stdio.h>

// declare big array globally, not in the main
int map[1024][1024];
int hori[1024];
int verti[1024];
int testcase, n;

void sumup(int map[][1024], int x, int y, int n)
{
  int sum = 0;
  sum = hori[x] + verti[y];

  int cross = 0;
  // \ direction
  for (int i = 0; x - i >= 0 && y - i >= 0; i++)
  {
    cross += map[x - i][y - i];
  }
  for (int i = 0; x + i < n && y + i < n; i++)
  {
    cross += map[x + i][y + i];
  }
  // / direction
  for (int i = 0; x + i < n && y - i >= 0; i++)
  {
    cross += map[x + i][y - i];
  }
  for (int i = 0; x - i >= 0 && y + i < n; i++)
  {
    cross += map[x - i][y + i];
  }
  printf("%d\n", sum + cross - 5 * map[x][y]); // itself count total 6 times - 5 times;
}

int main()
{
  // input
  scanf("%d", &testcase);
  scanf("%d", &n); // size of map

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf(" %d", &map[i][j]);
    }
  }
  // pre-calc
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      hori[i] += map[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      verti[i] += map[j][i];
    }
  }
  // execute
  while (testcase--)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    sumup(map, x, y, n);
  }

  return 0;
}