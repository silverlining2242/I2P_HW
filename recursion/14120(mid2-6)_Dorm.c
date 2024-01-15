// use time: final version
#include <stdio.h>
#define MOD 1000000007
// using % MOD after each computation involving large numbers, you ensure that the values of split, nosplit, and total remain within the range specified by the modulo operation, thereby avoiding integer overflow issues.
unsigned long long int split, nosplit = 0;
unsigned long long int idx[100] = {0}; // for store # of the input line
// unsigned long int result[100];

void calc(int n)
{
  // basic
  if (n == 1)
  {
    split = 1;
    nosplit = 1;
    // printf("n = %d: %d, %d\n", n, split, nosplit);
    return;
  }
  // recursive
  calc(n - 1);

  unsigned long long int newsplit, newnosplit;
  // need new pair, as when nosplit = 1*split+2*nosplit; the nosplit is updated one from last line

  newsplit = (4 * split + 1 * nosplit) % MOD;
  newnosplit = (1 * split + 2 * nosplit) % MOD;

  split = newsplit;
  nosplit = newnosplit;

  // printf("n = %d: %d, %d\n", n, split, nosplit);
}

int main()
{
  // input
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
  {
    scanf("%llu", &idx[i]);
  }
  // execute
  for (int i = 0; i < q; i++)
  {
    calc(idx[i]); // ex: 6
    unsigned long long int total = (split + nosplit) % MOD;
    printf("%llu\n", total);
    split = 0;
    nosplit = 0;
  }

  return 0;
}