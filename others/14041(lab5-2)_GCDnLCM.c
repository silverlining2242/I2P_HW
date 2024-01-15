#include <stdio.h>
// note: OJ's sample output is wrong

int main()
{
  int x, y;
  scanf("%d %d", &x, &y);

  int min = (x <= y) ? x : y;
  int GCD, LCM;
  for (int i = min; i > 0; i--)
  {
    if (x % i == 0 && y % i == 0)
    {
      GCD = i;
      break; // **stop here! or it will calc till 1
    }
  }
  LCM = GCD * (x / GCD) * (y / GCD);
  printf("%d %d\n", LCM, GCD);

  return 0;
}