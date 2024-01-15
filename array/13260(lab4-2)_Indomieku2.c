#include <stdio.h>
// number can be 2^63 , use long long
int main()
{
  // input
  long long n;
  scanf("%lld", &n);
  long long lead = 1;

  for (int i = 0; i < n; i++)
  {
    long long calc = lead;
    // print space
    for (int j = 0; j < n - i - 1; j++)
      printf(" ");
    // print number
    printf("%lld", lead);
    if (i == 0)
    {
      printf("\n");
      continue;
    }
    for (int j = 0; j < i; j++)
    {
      printf("%lld", ++calc); // add first then print!
    }
    for (int j = 0; j < i - 1; j++)
    {
      printf("%lld", --calc);
    }
    printf("%lld\n", --calc);
  }

  return 0;
}