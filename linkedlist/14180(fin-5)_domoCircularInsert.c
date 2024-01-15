#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "function.h"

typedef struct node
{
  int idx;
  struct node *next;
} Node;

/*it is partial judge, only finish below function, and not change the others*/
void AddBack(Node **head, Node **back, int *arr, int n);
void CircularInsert(Node **head, Node **back, int n, int m);

int main()
{
  char str[50];

  Node *head = (Node *)malloc(sizeof(Node));
  Node *back = head;
  // initialize the dummy head

  // we'll append the element after this dummy head to avoid runtime error.
  head->idx = -1;
  head->next = NULL;
  // printf("head itself: %p, head point to node 0: %p\n ", &head, *head);

  while (scanf("%s", str) != EOF)
  {

    int n, m;

    if (!strcmp(str, "AddBack"))
    {
      scanf("%d", &n);

      int *arr = (int *)malloc(sizeof(int) * n);
      for (int i = 0; i < n; i++)
      {
        scanf("%d", &arr[i]);
      }

      AddBack(&head, &back, arr, n);
      free(arr);
    }
    else if (!strcmp(str, "CircularInsert"))
    {
      scanf("%d %d", &n, &m);

      CircularInsert(&head, &back, n, m);
    }
  }

  // print all the element except the dummy head and free them.
  Node *print = head;

  if (head->next == NULL)
    printf("empty\n");

  while (print != NULL)
  {
    if (print->idx != -1)
      printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));

    Node *del = print;
    print = print->next;
    free(del);
  }
}
// *head will always points to Dummy line!
void AddBack(Node **head, Node **back, int *arr, int n)
{
  // printf("**head itself: %p\n ", (void*)(&head));
  // printf("*head itself: %p, *head point to node:  %p\n ", head, *head);
  for (int i = 0; i < n; i++)
  {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->idx = arr[i];
    newNode->next = NULL;

    (*back)->next = newNode; // link the node 0 and 1// next iterate will link node 1 and node 2
    (*back) = newNode;       // change *back pointer to point to the latest node
    // if (*back == *head)
    // {
    //   (*head)->next = newNode; //*head will always point to dummy!so only update its next node
    // }
  }
  // printf("*head itself: %p, points to node:  %p\n ", head, *head);
  // printf("*back itself: %p, points to node:  %p\n ", back, *back);
  // printf("----- %d ------\n",i);
  return;
}
// insert n times with value m
void CircularInsert(Node **head, Node **back, int n, int m)
{
  int k;                      // NOW's value, move idx how many places
  Node *move = (*head)->next; // move start with the first Node

  for (int i = 0; i < n; i++)
  {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->idx = m;

    if (i == 0) // insert 1st right after arr[0]
    {

      newNode->next = move->next;
      move->next = newNode;
      // update k
      k = move->idx;
    }
    else
    {
      // move the move pointer to the node that right before the inserted node
      for (int i = 0; i < k; i++)
      {
        if (move->next == NULL)
          move = (*head)->next; //**aware!
        else
          move = move->next;
      }
      // update k
      k = move->idx;
      // printf("k idx's value: %d\n", move->idx);

      // if the move is to the last node, insert after it: append node!
      if (move->next == NULL)
      {
        move->next = newNode;
        newNode->next = NULL;
        (*back) = newNode; //*aware
      }
      else // insert node in the middle
      {
        newNode->next = move->next;
        move->next = newNode;
        // Node *temp = move->next; //non necessary
        // move->next = newNode;
        // newNode->next = temp;
      }
    }
  }
}