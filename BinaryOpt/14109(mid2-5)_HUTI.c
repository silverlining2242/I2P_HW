#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  long long int result = 0;
  while (n--)
  {
    long long int new;
    scanf("%lld", &new);
    result = result ^ new;
  }
  printf("%lld\n", result);

  return 0;
}