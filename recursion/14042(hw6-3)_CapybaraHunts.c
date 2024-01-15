#include <stdio.h>
char map[500][500];
char visited[500][500]; // use another map to record visited, if visited, then return. to avoid back and forth walk
int h, w;
// int step = 0; // **avoid declare step! it is in func
int validstep = 0;

void printmap(); // this is for check

// ** use step to count where you iterate !
void walkmaze(int x, int y, int step) //**not declare duplicate map!!! char map[][500]
{
  // base case
  if (map[x][y] == '#' || x < 0 || y < 0 || x >= h || y >= w) // separate as no need to count step
    return;
  // mark visited
  if (visited[x][y] == '1')
    return;
  else
    visited[x][y] = '1';
  // count valid step
  if (map[x][y] == 'M') // can still go further, so M not stop!
  {
    validstep += step;
    // return;
  }

  // recursive case
  // goes up right down left

  walkmaze(x - 1, y, step + 1);
  walkmaze(x, y + 1, step + 1);
  walkmaze(x + 1, y, step + 1);
  walkmaze(x, y - 1, step + 1);

  return;
}

int main()
{
  // input
  scanf("%d %d", &h, &w);
  int x, y; // store starting point

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      scanf(" %c", &map[i][j]);
      if (map[i][j] == 'S')
      {
        x = i;
        y = j;
      }
    }
  }

  // execute

  walkmaze(x, y, 0); 
  printf("%d\n", validstep * 2);

  return 0;
}

void printmap()
{
  // check
  printf("\n");
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

/*
9 17
#################
#.#...#........M#
#.###.#.###.###.#
#S..#...#.#...#.#
#.#.#####.#####.#
#.#.....#.....#.#
###.###.###.#.#.#
#M..#.......#...#
#################
*/
/*
9 17
#################
#.#...#........M#
#.###.#.###.###.#
#S..#...#.#...#.#
#.#.#####.#####.#
#.#.#...#.....#.#
###.###.###.#.#.#
#M..#.......#...#
#################
*/