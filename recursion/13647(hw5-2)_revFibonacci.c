#include <stdio.h>
// use recursive instead of storing into an array
// Gn+2 - Gn - Gn+1

int revFib(int G0, int G1, int n)
{
  int ans;
  // base case
  if (n == 0)
  {
    ans = G0;
  }
  else if (n == 1)
  {
    ans = G1;
  }
  // recursive
  else
  {
    // think when G4 = G2 - G3
    // when n = 2, n= 3 , go inside further
    // for n = 2: return: f(, 0) - f( 1) = 2
    // for n = 3: return: f(, 1) - f( 2) = -1 - 2(it will go inside to duplicate cal from 0 and 1) = -3
    // final the two part is done recur inside ans = 2 - (-3) = 5 >>return
    ans = revFib(G0, G1, n - 2) - revFib(G0, G1, n - 1); // it has two return value from the func
  }
  return ans;
}

int main()
{
  int G0, G1, n;
  scanf("%d %d %d", &G0, &G1, &n);
  int final = revFib(G0, G1, n);
  printf("%d\n", final);

  // output Gn, n start from 0 as idx

  return 0;
}