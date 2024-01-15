//#include "function.h"
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
  // string process
  char *start = string;
  char *end = strstr(string, pattern); // Find the pattern in the string

  while (end != NULL)
  {

    if (end != start) //edge case : xyzxyz
    {
      strcpy(result[*splittedStrings], start);
      //strncpy(result[*splittedStrings], start, end - start); // Copy the substring
      result[*splittedStrings][end - start] = '\0';          // **Null-terminate the substring
      (*splittedStrings)++;
    }
    start = end + strlen(pattern); // Move the start pointer after the pattern
    end = strstr(start, pattern);  // Find the next pattern
  }
  // Copy the remaining string after the last pattern
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