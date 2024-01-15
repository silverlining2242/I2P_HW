#include <stdio.h>

int main()
{
  // printf("%d %d %d %d\n", 'A', 'Z', 'a', 'b'); // print corresponding ASCII code
  char input[6];
  // 5 char must + 1char, as last is using \0 to terminate string
  scanf("%s", input);
  // when doing char operations, it will convert to decimal first
  for (int i = 0; i < 5; i++) // 2nd condition can use  word[i] != '\0'
  {
    input[i] = 'Z' - (input[i] - 'a');
  }
  printf("%s\n", input);

  return 0;
}
/*
a becomes Z
b become Y
apple becomes ZKKOV
*/