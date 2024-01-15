/*Bottom up : use for loop to cal from the bottom*/
#include <stdio.h>
int ans[10000];
int count[10000] = {0};

void step(int n)
{
  if (count[n] != 0) // it's calculated before
    return;

  count[0] = 1;
  count[1] = 1;

  for (int i = 2; i <= n; i++)
    count[i] = count[i - 1] + count[i - 2];
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
