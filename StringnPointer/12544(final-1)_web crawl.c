#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <unistd.h> //use access func

#define MAX_L 100
#define MAX_C 1002

void ParsePrint(char **arr, int lines)
{
  const char *titleS = "<title>";
  const char *titleE = "</title>";
  const char *anchorE = "</a>";
  int anchorlen = strlen(anchorE) - 1; // which is 3
  int count = 0;                       // count for </a>
  for (int i = 0; i < lines; i++)
  {
    // find titleD
    char *start = strstr(arr[i], titleS);
    // start: position of finding <title>, it will be position of "<"
    if (start != NULL) // it is if!!! not while, only 1 in a sentence
    {

      start += strlen(titleS);
      // printf("diff cell spaces: %d\n", start - arr[i]);
      char *end = strstr(start, titleE); // find </title>, the position of "<" **another end
      if (end != NULL)
      {
        *end = '\0'; // replace it with \0 to terminate string and print it
        printf("%s\n", start);
      }
    }

    // find anchorE
    char *start2 = strstr(arr[i], anchorE);
    while (start2 != NULL)
    {
      count++;
      start2 += anchorlen;
      start2 = strstr(start2, anchorE);
    }
  }
  printf("%d\n", count);
  return;
}

int main()
{
  // malloc 2D
  char **arr = (char **)malloc(sizeof(char *) * MAX_L);
  for (int i = 0; i < MAX_L; i++)
  {
    arr[i] = (char *)malloc(sizeof(char) * MAX_C); // arr[i] = *arr
  }

  // read from stdin
  // press ctrl+D to terminate the input
  int line = 0;

  while (fgets(arr[line], MAX_C, stdin) != NULL && line < MAX_L) 
  {
    line++;
  }
  if (strlen(arr[line]) >= MAX_C - 1 ) // fgets read in "\n"
  {
    for (int i = 0; i < line; i++) //**line!
    {
      free(arr[i]);
    }
    free(arr);
    return 1;
  }
  // execute
  ParsePrint(arr, line);

  // free and close
  for (int i = 0; i < line; i++) //**line!
  {
    free(arr[i]);
  }
  free(arr);

  // fclose(fin);

  return 0;
}
//// read from file
// FILE *fin;
// const char *path = "../12544_sampleIn.txt"; // use .. to go back one layer file
// fin = fopen(path, "r");
// // check read
// (access(path, R_OK) == 0) ? printf("File is readable\n") : printf("Fail\n");
// if (fin == NULL)
// {
//   perror("Error"); // perror or strerror
//   return 1;
// }
// else
// {
//   printf("Open success\n");
// }
// while (fgets(arr[line], MAX_C, fin) != NULL && line < MAX_L) // it stops reading upon reaching \n
// {
//   line++;
// }