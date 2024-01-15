#include <stdio.h>
#define MAX 1000000005
/*bottom up*/
unsigned long long int arr[105][105][105];
unsigned long long int dp[105][105][105];

unsigned long long int getmin(unsigned long long int a, unsigned long long int b, unsigned long long int c)
{
  if (a > b)
  {
    return (b > c) ? c : b;
  }
  else // b>a
  {
    return (a > c) ? c : a;
  }
}

int main()
{
  // input
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int g = 0; g < k; g++)
      {
        scanf("%llu", &arr[i][j][g]);
        if (arr[i][j][g] == -1)
          arr[i][j][g] = MAX; // change - 1 to MAX // during compare min, will not be replaced
      }
    }
  }

  // exe bottom up
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int g = 0; g < k; g++)
      {
        // **important , for it to be replace!
        unsigned long long int last_n = MAX; //*can not assign to MAX
        unsigned long long int last_m = MAX;
        unsigned long long int last_k = MAX;
        
        // to avoid boundary
        if (i >= 1)
          last_n = dp[i - 1][j][g];
        if (j >= 1)
          last_m = dp[i][j - 1][g];
        if (g >= 1)
          last_k = dp[i][j][g - 1];

        // find min value
        unsigned long long int min;
        if (i == 0 && j == 0 && g == 0)
          min = 0;
        else
          min = getmin(last_n, last_m, last_k);
        // dp
        dp[i][j][g] = arr[i][j][g] + min;
        // bottom up to add itself and last smallest value: num (1,1,1) must come from (1,1,0) (1,0,1) or (0,1,1)
      }
    }
  }
  printf("%llu\n", dp[n - 1][m - 1][k - 1]);

  return 0;
}