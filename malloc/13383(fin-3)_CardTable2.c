#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *cards[10];

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
      printf("No card\n");
    }
    else
    {
      for (int j = 1; j <= cards[i][0]; j++)
        printf("%d%c", cards[i][j], j == cards[i][0] ? '\n' : ' ');
    }
  }
}
void All(int value, int len)
{
  Free();
  for (int i = 0; i < 10; i++)
  {
    cards[i] = (int *)malloc(sizeof(int) * (len + 1));
    cards[i][0] = len;
    for (int j = 1; j <= len; j++)
      cards[i][j] = value;
  }
}
void Place(int table, int len)
{
  // free then allocate new
  if (cards[table] != NULL)
    free(cards[table]);
  cards[table] = (int *)malloc(sizeof(int) * (len + 1));
  // place
  cards[table][0] = len;
  for (int j = 1; j <= len; j++)
    scanf("%d", &cards[table][j]);
}
void Swap(int tableA, int tableB)
{
  int *temp = cards[tableA];
  cards[tableA] = cards[tableB];
  cards[tableB] = temp;
}
void ShiftLeft()
{
  int *temp = cards[0];
  for (int i = 0; i <9; i++)
    cards[i] = cards[i+1];
  cards[9] = temp;

}
void ShiftRight()
{
  int *temp = cards[9];
  for (int i = 9; i> 0; i--)
    cards[i] = cards[i-1];
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
      int value, len;
      scanf("%d %d", &value, &len);
      All(value, len);
    }
    else if (strcmp(cmd, "place") == 0)
    {
      int table, len;
      scanf("%d %d", &table, &len);
      Place(table, len);
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