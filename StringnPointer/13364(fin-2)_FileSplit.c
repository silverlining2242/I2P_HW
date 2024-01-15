#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free2D(char **ptr, int num)
{
  for (int i = 0; i < num; i++)
    free(ptr[i]);
  free(ptr);
}

int isValid(char *str1, char *str2)
{
  // malloc space for 2D pointer
  char **subfiles_1 = (char **)malloc(sizeof(char *) * 50); // max sub-file after parsing
  char **subfiles_2 = malloc(sizeof(char *) * 50);

  // str1: parsing and store each to subfiles_1[i]
  char *str1_copy = strdup(str1);
  char *str1_split = strtok(str1_copy, "/"); // get first token
  int subfile_idx1 = 0;

  while (str1_split != NULL && subfile_idx1 < 50)
  {
    subfiles_1[subfile_idx1] = strdup(str1_split);
    str1_split = strtok(NULL, "/"); // update to find next token (strtok will picking up from last place)
    subfile_idx1++;
  }
  free(str1_copy);

  // str2: parsing and store each to subfiles_2[i]
  char *str2_copy = strdup(str2);
  char *str2_split = strtok(str2_copy, "/");
  int subfile_idx2 = 0;

  while (str2_split != NULL && subfile_idx2 < 50)
  {
    subfiles_2[subfile_idx2] = strdup(str2_split);
    str2_split = strtok(NULL, "/");
    subfile_idx2++;
  }
  free(str2_copy);

  // check: take each in subfiles_2 to check against each in subfiles_1
  for (int i = 0; i < subfile_idx2; i++)
  {
    int found = 0; // **place it here!
    // found str2 in str1
    for (int j = 0; j < subfile_idx1; j++)
    {
      if (strcmp(subfiles_2[i], subfiles_1[j]) == 0)
      {
        found = 1; // as long as it exists in str1, we can break to check str1, and iterate next str2_parsing
        break;
      }
    }
    // not found str2 in str1
    if (!found) // if found = 0, as only one parsing in str2 not founded in str1 return whole func!
    {
      free2D(subfiles_1, subfile_idx1);
      free2D(subfiles_2, subfile_idx2);
      return 0;
    }
  }
  // free
  free2D(subfiles_1, subfile_idx1);
  free2D(subfiles_2, subfile_idx2);

  return 1;
}

int main()
{
  int testcase;
  scanf("%d", &testcase);
  while (testcase--)
  {
    char str1[5005]; // max char of each file line
    char str2[5005];
    scanf("%s", str1);
    scanf("%s", str2);

    if (isValid(str1, str2))
      printf("valid\n");
    else
      printf("not valid\n");
  }
  return 0;
}
