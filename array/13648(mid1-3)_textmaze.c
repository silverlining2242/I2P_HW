#include <stdio.h>
char map[100][100];
int x, y;
int chosenX, chosenY;
int flag = 0;  // 0 is finding min, 1 is finding max
int valid = 1; // flag to check map boundary

void move(char map[][100], int n, char ch)
{
  valid = 1;  // before move, it must be within the map
  switch (ch) // the ch char is founded either min or max
  {
  case 'a':
  case 'f':
  case 'k':
  case 'p':
  case 'E':
  case 'J':
  case 'O':
  case 'T':
    if (y - 1 < 0)
    {
      valid = 0;
      return;
    }
    y--;
    break;
  case 'b':
  case 'g':
  case 'l':
  case 'q':
  case 'D':
  case 'I':
  case 'N':
  case 'S':
    if (y + 1 >= n)
    {
      valid = 0;
      return;
    }
    y++;
    break;
  case 'c':
  case 'h':
  case 'm':
  case 'r':
  case 'C':
  case 'H':
  case 'M':
  case 'R':
    if (x - 1 < 0)
    {
      valid = 0;
      return;
    }
    x--;
    break;
  case 'd':
  case 'i':
  case 'n':
  case 's':
  case 'B':
  case 'G':
  case 'L':
  case 'Q':
    if (x + 1 >= n)
    {
      valid = 0;
      return;
    }
    x++;
    break;
  case 'e':
  case 'j':
  case 'o':
  case 't':
  case 'A':
  case 'F':
  case 'K':
  case 'P':
    x = chosenX;
    y = chosenY;
    flag = (flag == 0) ? 1 : 0;
    break;
  default:
    x = chosenX;
    y = chosenY;
    break;
  }
}
char find(char map[][100], int n, int x, int y, int flag)
{
  // step1: set surrounding iteration;
  int idx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int idy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int surX[8], surY[8];
  for (int i = 0; i < 8; i++)
  {
    surX[i] = x + idx[i];
    surY[i] = y + idy[i];
  }
  // // check: surrounding iteration
  // for (int i = 0 ; i < 8 ;i++)
  // {
  //   printf("%c", map[surX[i]][surY[i]]);
  // }

  // step 2: find min or max
  char min = (char)125; // set min largest, so any (x,y)compare will replace it
  char max = (char)0;
  for (int i = 0; i < 8; i++)
  {
    if (surX[i] < 0 || surX[i] >= n || surY[i] < 0 || surY[i] >= n)
    {
      continue;
    }
    else
    {
      if (flag == 0)
      {
        if (map[surX[i]][surY[i]] <= min) // if same chose the largest idx, so must <=
        {
          min = map[surX[i]][surY[i]];
          // printf("%c\n",min);
          chosenX = surX[i];
          chosenY = surY[i];
        }
      }
      else
      {
        if (map[surX[i]][surY[i]] >= max) // if same chose the largest idx, so must <=
        {
          max = map[surX[i]][surY[i]];
          chosenX = surX[i];
          chosenY = surY[i];
        }
      }
    }
  }
  return (flag == 0) ? min : max;
}
int main()
{
  int n, step;
  scanf("%d %d", &n, &step);
  scanf("%d %d", &x, &y);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf(" %c", &map[i][j]); // space %c can absorb leading /n or space
    }
  }
  // step 0
  printf("%c", map[x][y]);
  while (step--)
  {
    char ch;
    ch = find(map, n, x, y, flag); // find surrounding min/ max value
    // printf("find: %c, (%d,%d)\n", ch,chosenX,chosenY);
    move(map, n, ch);
    if (valid)
      printf("%c", map[x][y]);
    else
      break;
  }

  return 0;
}