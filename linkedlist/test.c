#include <stdio.h>
#include <string.h>
// #include "function.h"
#include <stdlib.h>

typedef struct node
{
  int idx;
  struct node *next; // a pointer points to node data type
} Node;

/*it is partial judge, only finish below function, and not change the others*/
void AddFront(Node **head, Node **back, int num);
void AddBack(Node **head, Node **back, int num);
void DeleteFront(Node **head, Node **back);
void Delete(Node **head, Node **back, int num);
void Swap(Node **head, Node **back);

int main()
{
  char str[50];
  // step 1: create two pointer that points to dummy node(Node 0)
  Node *head = (Node *)malloc(sizeof(Node));
  Node *back = head; //*back also points to the node 0 (head store the address of node 0)

  // step 2: change the dummy node(Node 0) 's value
  // we'll append the element after this dummy head to avoid runtime error.
  head->idx = -1;
  head->next = NULL;

  while (scanf("%s", str) != EOF)
  {

    int num;

    if (!strcmp(str, "AddFront"))
    {
      scanf("%d", &num);
      AddFront(&head, &back, num);
    }
    else if (!strcmp(str, "AddBack"))
    {
      scanf("%d", &num);
      AddBack(&head, &back, num);
    }
    else if (!strcmp(str, "DeleteFront"))
    {
      DeleteFront(&head, &back);
    }
    else if (!strcmp(str, "Delete"))
    {
      scanf("%d", &num);
      Delete(&head, &back, num);
    }
    else if (!strcmp(str, "Swap"))
    {
      Swap(&head, &back);
    }
  }

  // print all the element except the dummy head and free each them after print it each
  Node *print = head; // create a pointer print, that point to the same node as *head points to

  if (head->next == NULL) // Node 0's next not point to the Node 1
    printf("empty\n");

  while (print != NULL)
  {
    if (print->idx != -1) // print nodes except the dummy head(Node 0)
      printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));

    Node *del = print;
    print = print->next; // print move to next node, and will be printed in next iteration
    free(del);           // delete previous node that print points to
  }
}
// *head will always points to Dummy line!, and all nodes linked together with dummy to print
void AddFront(Node **head, Node **back, int num)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->idx = num;
  newNode->next = (*head)->next;

  (*head)->next = newNode;

  if (*head == *back)
  {
    (*back) = newNode;
    return;
  }
  return;
}

void AddBack(Node **head, Node **back, int num)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->idx = num;
  newNode->next = NULL;

  (*back)->next = newNode;
  (*back) = newNode;

  return;
}
void DeleteFront(Node **head, Node **back)
{
  // no
  if (*head == *back)
    return;
  // only one
  if ((*head)->next->next == NULL)
  {
    free((*head)->next);
    (*back) = (*head);
    (*back)->next = NULL;
    return;
  }
  Node *temp = (*head)->next;
  (*head)->next = (*head)->next->next;
  free(temp);
  return;
}
void Delete(Node **head, Node **back, int num) // deleted specific num
{
  // no
  if (*head == *back)
    return;
  // if delete only one
  if ((*head)->next->next == NULL && (*head)->next->idx == num)
  {
    free((*head)->next);
    (*head)->next = NULL;
    *back = *head;
    return;
  }

  // delete
  Node *prev = *head;
  Node *current = (*head)->next;

  while (current != NULL)
  {
    if (current->idx == num) // if del
    {
      prev->next = current->next;
      // if delete only one
      //  if ((*head)->next->next == NULL)
      //  {
      //    (*head)->next = NULL;
      //    *back = *head;
      //  }
      // if delete last
      if (current == (*back))
        *back = prev;

      free(current);
      current = prev->next;
    }
    else // if not del
    {
      prev = current;
      current = current->next;
    }
  }
}

void Swap(Node **head, Node **back)
{
  Node *prev = (*head);
  Node *current = (*head)->next;
  Node *next = (*head)->next;

  (*back) = (*head)->next;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  (*head)->next = prev;
  (*back)->next = NULL;
}
