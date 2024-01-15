#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "14136.h"
#include "test.c"
//#include "14136(hw9-3)_ZoroSlash.c"
char **split(char *string, char *pattern, int *splittedStrings);
void free_(char **result, int splittedStrings);

int main()
{
    char pattern[10]; // xyz
    char string[500]; // Ixyzamxyzluffy
    scanf("%s", string);
    scanf("%s", pattern);
    int splittedStrings = 0;
    char **result = split(string, pattern, &splittedStrings); // return 2D array address
    for (int i = 0; i < splittedStrings; ++i)
    {
        printf("%d: %s\n", i,result[i]);
    }
    free_(result, splittedStrings);
    return 0;
}