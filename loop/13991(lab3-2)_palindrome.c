#include <stdio.h>
#include <string.h>

int main()
{
  int testcase;
  scanf("%d", &testcase);
  while (testcase--)
  {
    char input[1000001];
    scanf("%s", input);
    int len = strlen(input);

    int half = strlen(input) - 1;
    int isP = 1;
    for (int i = 0; i < half; i++)
    {
      if (input[0 + i] != input[len - 1 - i])
      {
        isP = 0;
        break;
      }
    }
    (isP)? printf("Yes\n"): printf("No\n");
  }

  return 0;
}