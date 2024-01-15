#include <stdio.h>

int main()
{
  unsigned int x;
  scanf("%u", &x);
  double year1;
  float year2;
  long long second;
  year1 = (double)x / 365; // transfer data type from int to double first
  year2 = (float)x / 365;
  second = (long long)x * 24 * 3600;
  printf("%lf %.6f %lld\n", year1, year2, second); // default is 6 decimal after the points
  // we can directly calc then print without declaring new variables
  // printf("%.6lf %.6lf %lld\n", (double)x / 365, (float)x / 365, (long long)x * 24 * 3600);

  return 0;
}
/*When you divide an unsigned integer (x) by another integer (365), the result will also be an integer, and any fractional part will be truncated.
To fix this issue and get the expected floating-point results, you should cast one or both of the operands to floating-point types, such as double, before performing the division.*/