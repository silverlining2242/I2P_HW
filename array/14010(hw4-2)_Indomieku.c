#include <stdio.h>
// number can be 2^63 , use long long
int main()
{
  // input
  long long n, k;
  scanf("%lld %lld", &n, &k);
  long long lead = 1;

  for (int i = 0; i < n; i++)
  {
    int each = 2 * i + 1;
    if (i == 0)
    {
      printf("%lld\n", lead);
    }
    else if (i % 2 == 0)
    {
      printf("%d ", lead);
      long long calc = lead;
      for (int j = 0; j < each / 2; j++)
      {
        calc *= k;
        printf("%lld ", calc);
      }
      for (int j = 1; j < each / 2; j++)
      {
        calc /= k;
        printf("%lld ", calc);
      }
      printf("%lld\n", lead);
    }
    else if (i % 2 != 0)
    {
      printf("%d ", lead);
      long long calc = lead;
      for (int j = 0; j < each / 2; j++)
      {
        calc += k;
        printf("%lld ", calc);
      }
      for (int j = 1; j < each / 2; j++)
      {
        calc -= k;
        printf("%lld ", calc);
      }
      printf("%lld\n", lead);
    }
  }

  return 0;
}