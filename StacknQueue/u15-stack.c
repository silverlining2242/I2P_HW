/*Stack Implementation (Array-based) method 1 create big array not linked */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0; // use for printing range
// create a stack
struct stack
{
  int items[MAX]; // the number stack of all is items[MAX], each is the one item in arr
  int top;
};
typedef struct stack st;

void createEmptyStack(st *s);
int isfull(st *s);
int isempty(st *s);
void push(st *s, int newitem);
void pop(st *s);
void printStack(st *s);

int main()
{
  // create pointer *s points to st data type and allocate memory space
  st *s = (st *)malloc(sizeof(st)); // only one big array

  createEmptyStack(s);

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  printStack(s);

  pop(s);

  printf("\nAfter popping out\n");
  printStack(s);
}

void createEmptyStack(st *s)
{
  s->top = -1; // upper has no one
}

int isfull(st *s)
{
  if (s->top == MAX - 1) // top index is from 0 , so last is MAX -1
    return 1;
  else
    return 0;
}

int isempty(st *s)
{
  if (s->top == -1) // arr[0] not inserted yet
    return 1;
  else
    return 0;
}
void push(st *s, int newitem)
{
  if (isfull(s))
  {
    printf("STACK FULL\n");
  }
  else
  {
    s->top++;                   // arr[0].top change from -1 to 0 = idx (top == itself arr idx)
    s->items[s->top] = newitem; // items[0] = 1;
  }
  count++; // count=1
}
void pop(st *s)
{
  if (isempty(s))
  {
    printf("STACK EMPTY\n");
  }
  else
  {
    printf("Item popped = %d", s->items[s->top]);
    s->top--; // change idx 3 to 2 >> removed arr[3]
  }
  count--;
  printf("\n");
}
void printStack(st *s)
{
  printf("Stack: ");
  for (int i = 0; i < count; i++)
  {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}