#include <stdio.h>
/*DP: Top Down*/
int count[10000];
int ans[10000];
void step(int n)
{
  // base case
  if (n == 0 || n == 1)
    count[n] = 1;
  if (n == 0)
    return;
  // recursion
  step(n - 1);
  count[n] = count[n - 1] + count[n - 2];
  return;
}
int main()
{
  int t; // testcase
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    int h;
    scanf("%d", &h);
    step(h);
    ans[i] = count[h];
  }
  // print
  for (int i = 0; i < t; i++)
  {
    printf("%d\n", ans[i]);
  }

  return 0;
}
