#include <stdio.h>
/*col is start from 1 question*/
//**aware of position is y!! and x++
char map[500][500];
int Q[100];
int h, w;
int x, y;

void Drop(int col)
{
  x = 0;
  y = col;
  for (int i = 0; i < h; i++)
  {
    if (y == 0 && map[x][y] == '/')
    {
      printf("Left!\n");
      break;
    }
    if (y == w - 1 && map[x][y] == '\\')
    {
      printf("Right!\n");
      break;
    }

    if (map[x][y] == '/' && y >= 1) // **boundary check x-1,  x must >=1
    {
      // x--;
      // printf("2x: %d\n", x);
      if (map[x][y - 1] == '/')
      {
        y--;
        x++;
      }
      else if (map[x][y - 1] == '\\')
      {
        printf("Stuck QQ\n");
        break;
      }
    }

    if (map[x][y] == '\\' && y < w - 1) // **boundary check x+1,  x must < 5(not include 5)
    {
      if (map[x][y + 1] == '\\')
      {
        y++;
        x++;
      }
      else if (map[x][y + 1] == '/')
      {
        printf("Stuck QQ\n");
        break;
      }
    }
  }
  // after loop, y will be at position of h, x is position
  if (x == h) //**need condition
    printf("Position: %d\n", y + 1);
}

int main()
{
  // input

  scanf("%d %d", &h, &w);
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      scanf(" %c", &map[i][j]);
      // A[i][j] = getchar(); // get one
    }
    // getchar(); // use it to consume '\n'
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &Q[i]);
  }
  for (int i = 0; i < q; i++)
  {
    Drop(Q[i] - 1); // col idx from 1;
  }

  return 0;
}
// // print check
// for (int i = 0; i < h; i++)
// {
//   for (int j = 0; j < w; j++)
//   {
//     printf("%c", map[i][j]);
//     // A[i][j] = getchar(); // get one
//   }
//   printf("\n");
//   // getchar(); // use it to consume '\n'
// }
// for (int i = 0; i < q; i++)
// {
//   printf("%d", Q[i]);
// }