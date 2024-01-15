#include <stdio.h>
#include <stdlib.h>
int sum(int a[], int n)
{
  int i, ans = 0;
  for (i = 0; i < n; i++)
  {
    ans += a[i];
  }

  return ans;
}
int sum_squared(int a[], int n)
{
  int i, ans = 0;

  for (i = 0; i < n; i++)
  {
    ans += a[i] * a[i];
  }

  return ans;
}
void ToUpper(char *);
void ToLower(char *);
void (*pf)(char *);


int middle(int a[], int n)
{
  return a[n / 2];
}

int run(int (*fp)(int *, int), int a[], int n)
{
  fp(a, n); //(*fp)(a, n) will also work!
}

int main(void)
{
  int a[] = {1, 2, 3, 4};

  char mis[] = "Nina Metier";

  pf = ToUpper;
  // use the function pointer to make a call
  (*pf)(mis); // or pf(mis);

  pf = ToLower;
  // use the function pointer to make another call
  (*pf)(mis); // or pf(mis);

  printf("%d\n", run(sum, a, 4));
  printf("%d\n", run(sum_squared, a, 4));
  printf("%d\n", run(middle, a, 4));

  return 0;
}
