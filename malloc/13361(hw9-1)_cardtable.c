#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *cards[10]; // an array store ten elements of pointers (int *)
void Free(void)
{
  for (int i = 0; i < 10; i++)
  {
    if (cards[i] != NULL) // if the pointer not point to anything , no need to free
      free(cards[i]);     // free all cards[i][j], as cards[i] is position points to 2nd layer
  }
}
void Clear(void)
{
  Free();
  for (int i = 0; i < 10; i++)
    cards[i] = NULL; // a pointer does not point to any memory location.
  /*assigning NULL to a pointer after freeing the memory is a common practice to ensure the pointer no longer points to the deallocated memory. This helps in preventing accidental misuse of freed memory.*/

  // below combine clear + Free has RE!!
  // for (int i = 0; i < 10; i++)
  // {
  //   if (cards[i] != NULL) // necessary?
  //   {
  //     free(cards[i]);   // Free first
  //   }
  //   cards[i] = NULL; // make sure each store NULL (points to NULL)
  // }
}

void Print(void)
{
  for (int i = 0; i < 10; i++)
  {
    printf("%d: ", i);
    if (cards[i] == NULL)
      printf("No card\n");
    else
    {
      for (int j = 1; j <= cards[i][0]; j++) // cards[cards][# of cards]
        printf("%d%c", cards[i][j], j == cards[i][0] ? '\n' : ' ');

      // for (int j = 1; j < cards[i][0]; j++) // cards[cards][# of cards]
      //   printf("%d ", cards[i][j]);
      // printf("%d\n", cards[i][cards[i][0]]);
    }
  }
  //

  // for (int i = 0; i < 10; i++)
  // {
  //   if (cards[i] == NULL)
  //     printf("%d: No card\n", i);
  //   else
  //   {
  //     printf("%d: ", i);
  //     for (int j = 1; j < cards[i][0]; j++) // cards[table][# of cards]
  //       printf("%d ", cards[i][j]);
  //     printf("%d\n", cards[i][cards[i][0]]);
  //   }
  // }
}
void All(int num, int len)
{
  // **must Free, and cannot use Clear!
  Free();
  for (int i = 0; i < 10; i++)
  {
    cards[i] = (int *)malloc(sizeof(int) * (len + 1));
    cards[i][0] = len; // use [0] to store the total num of card
    for (int l = 1; l <= len; l++)
      cards[i][l] = num;
  }
}
void Place(int table, int len)
{
  // free tables card
  if (cards[table] != NULL) // *without if condition is still okay
    free(cards[table]);
  cards[table] = (int *)malloc(sizeof(int) * (len + 1));
  // **below has RE!!
  // if (cards[table] != NULL)
  // {
  //   free(cards[table]);
  //   cards[table] = (int *)malloc(sizeof(int) * (len + 1));
  // }
  cards[table][0] = len;
  for (int i = 1; i <= len; i++)
    scanf("%d", &cards[table][i]);
}
void Swap(int table_a, int table_b)
{
  int *tmp;
  tmp = cards[table_a];
  cards[table_a] = cards[table_b];
  cards[table_b] = tmp;
}
int main() // int argc, const char *argv[]) //what does it mean here?
{
  // Clear();
  char cmd[10];
  scanf("%s", cmd);
  while (strcmp(cmd, "exit") != 0)
  {
    if (strcmp(cmd, "all") == 0)
    {
      int num, len; // num: card value / len: # of cards
      scanf("%d %d", &num, &len);
      All(num, len);
    }
    else if (strcmp(cmd, "clear") == 0)
    {
      Clear();
    }
    else if (strcmp(cmd, "place") == 0)
    {
      int table, len;
      scanf("%d %d", &table, &len);
      Place(table, len);
    }
    else if (strcmp(cmd, "swap") == 0)
    {
      int table_a, table_b;
      scanf("%d %d", &table_a, &table_b);
      Swap(table_a, table_b);
    }
    else if (strcmp(cmd, "print") == 0)
    {
      Print();
    }
    scanf("%s", cmd);
  }
  return 0;
}