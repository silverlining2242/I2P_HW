/*stack: reverse word*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int top = -1;
int item;
char stack_string[MAX];

void pushChar(char item);
char popChar(void);
int isEmpty(void);
int isFull(void);

int main()
{
  char str[MAX];
  printf("Input a string: ");
  scanf("%[^\n]", str);

  for (int i = 0; i < strlen(str); i++)
    pushChar(str[i]);
  for (int i = 0; i < strlen(str); i++)
    str[i] = popChar();
  printf("Reverse String is: %s\n", str);

  return 0;
}
void pushChar(char item) // item is idex of arr
{
  if (isFull())
  {
    printf("\nStack is FULL!!\n");
    return;
  }
  top++;
  stack_string[top] = item;
}

char popChar() // always only take out 1 from top! and we declare arr globally
{
  if (isEmpty())
  {
    printf("\nStack is EMPTY ! \n");
    return 0;
  }
  item = stack_string[top];
  top--;

  return item; // return the value char of arr[i]
}
int isEmpty()
{
  return (top == -1) ? 1 : 0;
}
int isFull()
{
  return (top == MAX - 1) ? 1 : 0;
}