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
  for(int i = 0; i <n; i++)
  {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->idx = arr[i];
    newNode->next = NULL;

    (*back)->next = newNode;
    (*back) = newNode;
  }
  return;
}
// insert n times with value m
void CircularInsert(Node **head, Node **back, int n, int m)
{
  int k;
  Node *move = (*head)->next;
  for (int i = 0; i < n ;i++)
  {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->idx = m;
    
    if(i==0)
    {
      newNode->next = move ->next;
      move->next = newNode;
      k = move->idx;
    }
    else
    {
      //move k
      for(int i = 0; i < k; i++)
      {
        if(move->next==NULL)
          move = (*head)->next;
        else
          move = move->next;
      }
      //update k
      k = move->idx;
      //add Node
      if(move->next==NULL)
      {
        move->next = newNode;
        *back = newNode;
        (*back)->next = NULL;
      }
      else
      {
        newNode->next = move->next;
        move->next = newNode;
      }
    }
  }
}