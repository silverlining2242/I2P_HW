#include <stdio.h>
// like calc Fibonnaci num
// if using all recursive: TLE
int ans[10000];
int step(int n)
{
  int num;
  // base case
  if (n == 0 || n == 1)
    num = 1;

  // recursion
  else
    num = step(n - 1) + step(n - 2);

  return num;
}
int main()
{
  int t; // testcase
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    int h;
    scanf("%d", &h);
    ans[i] = step(h);
  }
  // print
  for (int i = 0; i < t; i++)
  {
    printf("%d\n", ans[i]);
  }

  return 0;
}
