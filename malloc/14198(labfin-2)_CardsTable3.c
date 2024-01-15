#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *cards[10];

char string[10002];
void Free()
{
  for (int i = 0; i < 10; i++)
  {
    if (cards[i] != NULL)
      free(cards[i]);
  }
}
void Clear()
{
  Free();
  for (int i = 0; i < 10; i++)
    cards[i] = NULL;
}
void Print()
{
  for (int i = 0; i < 10; i++)
  {
    printf("%d: ", i);
    if (cards[i] == NULL)
    {
      printf("No Contents\n");
    }
    else
    {
      printf("%s\n", &cards[i][1]);
      // for (int j = 1; j < cards[i][0]; j++)
      //   printf("%c", cards[i][j]);
      // printf("%c\n", cards[i][cards[i][0]]);
    }
  }
}
void All(char ch, int len)
{
  Free();
  for (int i = 0; i < 10; i++)
  {
    cards[i] = (char *)malloc(sizeof(char) * (len + 5));
    cards[i][0] = len; // what value here is wrong, as len being changed to char to store in card[i][0]
    for (int j = 1; j <= len; j++)
      cards[i][j] = ch;
    cards[i][len + 1] = '\0';
  }
}
void Place(int table)
{
  // free then allocate new
  if (cards[table] != NULL)
    free(cards[table]);
  cards[table] = (char *)malloc(sizeof(char) * (10002));
  scanf("%s", string);
  // place
  cards[table][0] = strlen(string);
  int len = cards[table][0]; // what value is wrong, that's why we cpy using string position, and not using strlen to loop
  strcpy(cards[table] + 1, string); //**use strcpy
  // for (int j = 1; j <=len; j++)
  //   cards[table][j] = string[j-1];
  // cards[table][len+1] = '\0';
}
void Swap(int tableA, int tableB)
{
  char *temp = cards[tableA]; //*temp is pointer points to char!! use char!!
  cards[tableA] = cards[tableB];
  cards[tableB] = temp;
}
void ShiftLeft()
{
  char *temp = cards[0];
  for (int i = 0; i < 9; i++)
    cards[i] = cards[i + 1];
  cards[9] = temp;
}
void ShiftRight()
{
  char *temp = cards[9];
  for (int i = 9; i > 0; i--)
    cards[i] = cards[i - 1];
  cards[0] = temp;
}

int main()
{
  char cmd[20];

  scanf("%s", cmd);

  while (strcmp(cmd, "exit") != 0)
  {
    if (strcmp(cmd, "clear") == 0)
    {
      Clear();
    }
    else if (strcmp(cmd, "print") == 0)
    {
      Print();
    }
    else if (strcmp(cmd, "all") == 0)
    {
      char ch;
      int len;
      scanf(" %c", &ch);
      scanf(" %d", &len);
      All(ch, len);
    }
    else if (strcmp(cmd, "place") == 0)
    {
      int table;
      scanf(" %d", &table);
      Place(table);
    }
    else if (strcmp(cmd, "swap") == 0)
    {
      int tableA, tableB;
      scanf("%d %d", &tableA, &tableB);
      Swap(tableA, tableB);
    }
    else if (strcmp(cmd, "shiftleft") == 0)
    {
      ShiftLeft();
    }
    else if (strcmp(cmd, "shiftright") == 0)
    {
      ShiftRight();
    }

    scanf("%s", cmd);
  }

  return 0;
}