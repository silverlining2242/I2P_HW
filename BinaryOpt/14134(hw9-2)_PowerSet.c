#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char input[25];
  scanf("%s", input);
  int len = strlen(input); // max len of elements of subset
  int power = 1 << len;    // to get 2^len

  for (int i = 1; i < power; i++) // will not print {} start with 1
  {
    for (int j = 0; j < len; j++) // j as mask
    {                             // ex when i = 5 in bit is 101
      if (i & (1 << j))           // 1<<j : 001 010 100 //**use & to check if identical
      {
        printf("%c", input[j]);
      }
    }
    printf("\n");
  }

  // int test = (101) & (001);
  // printf("%d\n", test);

  // printPowerSet(input);

  return 0;
}
