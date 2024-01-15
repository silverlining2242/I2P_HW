#include <stdio.h>
int ans[21][21];
int map[21][21];

void bottomup(int W, int L)
{
  // to avoid boundary issue shift 1 place to bottom right and fill with 0 but (0,0) = 1
  for (int i = 0; i < W; i++)
  {
    ans[i][0] = 0;
  }
  for (int j = 0; j < L; j++)
  {
    ans[0][j] = 0;
  }
  ans[0][0] = 1;

  //
  for (int i = 1; i <= W; i++)
  {
    for (int j = 1; j <= L; j++)
    {

      if (map[i][j] == 1) // if 1 is obstacles!
        ans[i][j] = 0;
      else
        ans[i][j] = ans[i - 1][j] + ans[i][j - 1] + ans[i - 1][j - 1];
    }
  }
}

int main()
{
  int W, L;
  // input
  scanf("%d %d", &W, &L);
  for (int i = 1; i <= W; i++)
  {
    for (int j = 1; j <= L; j++)
    {
      scanf("%1d", &map[i][j]); // **consume 1d at a time
    }
  }
  // exe func
  bottomup(W, L);

  // output
  printf("%d\n", ans[W][L]);

  // print check
  // for (int i = 0; i <= W; i++)
  // {
  //   for (int j = 0; j <= L; j++)
  //   {
  //     printf("%1d", map[i][j]); // **consume 1d at a time
  //   }
  //   printf("\n");
  // }

  return 0;
}