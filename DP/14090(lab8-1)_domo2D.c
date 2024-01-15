#include <stdio.h>
#define MIN -10
/*bottom up*/
unsigned long long int arr[105][105];
unsigned long long int dp[105][105];

unsigned long long int getmax(unsigned long long int a, unsigned long long int b)
{
  return (a >= b) ? a : b;
}

int main()
{
  // input
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
        scanf("%llu", &arr[i][j]);
        if (arr[i][j] == -1)
          arr[i][j] = MIN; // change - 1 to MAX // during compare min, will not be replaced
    }
  }

  // exe bottom up
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      // **important , for it to be replace!
      unsigned long long int last_n = MIN; //*can not assign to MAX
      unsigned long long int last_m = MIN;

      // to avoid boundary
      if (i >= 1)
        last_n = dp[i - 1][j];
      if (j >= 1)
        last_m = dp[i][j - 1];

      // find min value
      unsigned long long int max;
      if (i == 0 && j == 0)
        max = arr[i][j];
      else
        max = getmax(last_n, last_m);
      // dp
      dp[i][j] = arr[i][j] + max;
      // bottom up to add itself and last smallest value: num (1,1,1) must come from (1,1,0) (1,0,1) or (0,1,1)
    }
  }
  printf("%llu\n", dp[n - 1][m - 1]);

  return 0;
}