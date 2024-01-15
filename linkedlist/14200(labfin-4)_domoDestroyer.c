#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
// #include "function.h"
typedef struct node
{
  int idx;
  struct node *next;
} Node;

void AddBack(Node **head, Node **back, int *arr, int n);
void LinearDelete(Node **head, Node **back);

int main()
{
  char str[50];

  Node *head = (Node *)malloc(sizeof(Node));
  Node *back = head;
  // initialize the dummy head

  // we'll append the element after this dummy head to avoid runtime error.
  head->idx = -1;
  head->next = NULL;

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
    else if (!strcmp(str, "LinearDelete"))
    {
      LinearDelete(&head, &back);
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
void AddBack(Node **head, Node **back, int *arr, int n)
{
  // clear all first, delete from front
  while (*head != *back)
  {
    // if only one
    if ((*head)->next == (*back))
    {
      Node *temp = (*head)->next;
      (*back) = (*head);
      free(temp);
      break;
    }
    Node *temp = (*head)->next;
    (*head)->next = temp->next; //*head)->next->next;
    free(temp);
  }
  // then add
  for (int i = 0; i < n; i++)
  {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->idx = arr[i];
    newNode->next = NULL;

    (*back)->next = newNode;
    (*back) = newNode;
  }
}
void LinearDelete(Node **head, Node **back)
{
  // if empty
  if (*head == *back)
    return;

  // if only one Node
  if ((*head)->next->next == NULL)
  {
    free((*head)->next);
    (*back) = (*head);
    (*head)->next = NULL;
    return;
  }
  int k;

  Node *move = (*head)->next; // move it to what we need to delete
  Node *prev = (*head);       // to store prev move right before we delete
  k = move->idx;

  // delete first one
  prev->next = move->next;
  free(move);
  move = (*head)->next;

  for (int i = 0; i < k - 1; i++)
  {
    if (move->next == NULL && i < k - 2)
      break;
    else
    {
      prev = prev->next;
      move = move->next;
    }
  }
  printf("prev: %d\n", prev->idx);
  printf("move: %d\n", move->idx);
  k = move->idx;
  for (int i = 0; i < k; i++)
  {
    if (move->next == NULL)
      break;
    else
    {
      prev = prev->next;
      move = move->next;
    }
  }
  printf("prev: %d\n", prev->idx);
  printf("move: %d\n", move->idx);

  // // //
  // Node *preoldmove = move;
  // Node *oldmove = move;
  // Node *nextoldmove = move->next;

  // // move the move and prev
  // for (int i = 0; i < k; i++)
  // {
  //   if(move ==NULL)
  //   {
  //     return;
  //   }
  //   else if (move ->next == NULL)
  //   {
  //     preoldmove->next = oldmove->next;
  //     //free(oldmove);
  //     *back = preoldmove;
  //     (*back)->next = NULL;
  //   }
  //   else
  //   {
  //     move = move->next;
  //     prev = prev->next;
  //   }
  // }
  // // delete old move
  // preoldmove->next = oldmove->next;
  // //free(oldmove);
  // *back = preoldmove;
  // (*back)->next = NULL;

  // // update k
  // k = move->idx;

  return;
}