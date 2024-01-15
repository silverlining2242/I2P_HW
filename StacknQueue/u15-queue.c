/*Queue implementation: array-based*/
#include <stdio.h>
#define SIZE 3

void enQueue(int);
void deQueue();
void display();

int items[SIZE], front = -1, rear = -1; // start with -1!

int main()
{
  deQueue(); // dequeue one for test if it's empty
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4); // will be FULL!
  display();
  deQueue(); // dequeue one
  display();

  return 0;
}

void enQueue(int value)
{
  if (rear == SIZE - 1)
    printf("\nQueue is Full! \n");
  else
  {
    if (front == -1) // only move front the first time we inserted
      front = 0;
    rear++; // after 1st, we only moved rear for enQueue
    items[rear] = value;
    printf("Inserted : %d\n", value);
  }
}

void deQueue()
{
  if (front == -1)
    printf("\nQueue is Empty !\n");
  else
  {
    printf("Deleted: %d\n", items[front]);
    front++; // starting idx from 0 to 1
    if (front > rear)
      front = rear = -1; // all is deleted
  }
}
void display()
{
  if (rear == -1)
    printf("Queue is Empty!\n");
  else
  {
    printf("Queue elements are: \n");
    for (int i = front; i <= rear; i++) //<= rear!
      printf("%d ", items[i]);
  }
  printf("\n");
}