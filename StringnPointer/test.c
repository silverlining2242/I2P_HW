// #include "function.h"
#include <string.h>
#include <stdlib.h>
char **split(char *string, char *pattern, int *splittedStrings)
{
  // malloc
  int max = 500;
  char **result = (char **)malloc(sizeof(char *) * max);
  for (int i = 0; i < max; i++)
  {
    result[i] = (char *)malloc(sizeof(char) * max);
  }
  // split
  char *start = string;
  char *end = strstr(string, pattern);
  while (end != NULL)
  {
    if (start != end)
    {
      strcpy(result[*splittedStrings], start);
      result[*splittedStrings][end-start] = '\0';
      (*splittedStrings)++;
    }
    start = end + strlen(pattern);
    end = strstr(start, pattern);
  }
  // copy remaining
  if (end == NULL)
  {
    strcpy(result[*splittedStrings], start);
    (*splittedStrings)++;
    return result;
  }

  // exe free is in main function
}

void free_(char **result, int splittedStrings)
{
  for (int i = 0; i < splittedStrings; i++)
  {
    free(result[i]);
  }
  free(result);
}
/*
edge case:
xyzxyz
xyz

should output a blank line
*/