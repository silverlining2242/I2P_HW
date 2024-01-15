#include <stdio.h>
#include <string.h>
/*flag concept to check vaild*/

int main()
{
  char input[1001];
  scanf("%s", input);
  int count = 0; // duplicate palindromes still count

  int len = strlen(input);
  // int isP = 1;                  // cannot put it here!
  for (int i = 0; i < len; i++) // position in string
  {
    for (int j = 3; j <= len; j++) // length of substring
    {
      int isP = 1; // assume it is palindrom as a flag **where to put this !, each position and length initiate new flag
      // **check boundary
      if (i + j > len)
      {
        break;
      }
      // after checking substring inside
      int half = j - 1 / 2;
      for (int k = 0; k < half; k++)
      {
        if (input[i + k] != input[i + j - 1 - k])
        {
          isP = 0;
          break;
        }
      }
      // use flag to count
      if (isP)
      {
        //printf("i: %d, j: %d\n", i, j);
        count++;
      }
    }
  }
  printf("%d\n", count);

  return 0;
}