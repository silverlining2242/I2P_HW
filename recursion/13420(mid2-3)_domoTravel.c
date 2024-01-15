#include <stdio.h>

int connect[100][100];
int visited[100]; // use it to track if city is used as root
int component;

// step2: use city as root city, to DFS walk to all city(N), like walk maze. e.g 0, N
void traverse(int city, int N)
{
  for (int j = 0; j < N; j++)
  {
    if (connect[city][j] == 1)
    {
      // step4-1: mark where we walked, and valid root city
      connect[city][j] = 2; // mark where we walked
      connect[j][city] = 2; //

      visited[j] = 1; // the walked city is linked with root and , no need to use as root to traverse, so mark it

      // step4-2: keep walk.
      // if the next city is valid to walk, we next city as current city and find next city (0 - 1)
      traverse(j, N);
    }
  }
  // **step3: recur terminate case **important!!!
  // as when finish using int city as root that tried to walk to all the other cities
  return;
}

int main()
{
  // input
  int N, K;
  scanf("%d %d", &N, &K); // N cities, K input links
  while (K--)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    connect[x][y] = 1; // step1: create tables to store relationship if each two city-city is linked
    connect[y][x] = 1; // also it's diagonal, connect[x][x] remain 0, as it will only move forward
  }
  // traverse
  for (int i = 0; i < N; i++) // step5: use each city as root to traverse, call func
  {
    if (visited[i] != 1) // if it's 1, no need to use as root
    {
      component++;    // **if it's valid to used as root, count++
      visited[i] = 1; // mark itself as used root traverse
      traverse(i, N); // call func
    }
  }
  // output
  printf("%d\n", component - 1); // step6: result is using 3 cities as component, so -1 = 2 links

  return 0;
}

/*
input:
6 4 (6 cities, 4 links)
0 1
1 2
2 0
3 4
output
2
*/