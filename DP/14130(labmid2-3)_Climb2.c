/*Bottom up : use for loop to cal from the bottom*/
#include <stdio.h>
int ans[10000];
int dp[10000] = {0};
int cost[10000];
int min(int a, int b)
{
  return (a <= b) ? a : b;
}
void step(int n)
{
  if (dp[n] != 0) // it's calculated before
    return;

  dp[0] = 0; // change to 0
  dp[1] = 0; // change to 0

  // if cost is the same, compare the num of step(dp arr)
  for (int i = 2; i <= n; i++)
    dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
  return;
}

int main()
{
  // input
  int t; // testcase
  scanf("%d", &t);

  int c; // num of cost
  scanf("%d", &c);

  for (int i = 0; i < c; i++)
  {
    scanf(" %d", &cost[i]);
  }

  for (int i = 0; i < t; i++)
  {
    int h;
    scanf("%d", &h);
    step(h);
    ans[i] = dp[h];
  }
  // print
  for (int i = 0; i < t; i++)
  {
    printf("%d\n", ans[i]);
  }

  return 0;
}
