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
  // create pointer points to newNode (why not directly create a Node?, as Node in func will be local variable, we need a pointer, and use pointer to change value of Node)
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->idx = num;
  newNode->next = (*head)->next; //*head always at Dummy and points to 1st node

  (*head)->next = newNode;

  if (*head == *back) // first initialized *head and *back both point to dummy
  {
    (*back) = newNode; // move back to points the last node (newNode)
    // newNode->next = NULL; //this is redundant as when initialized it is all to NULL
    //(*back)->next = NULL; //this is redundant as when initialized it is all to NULL
    return;
  }

  return;
}
// AddBack(&head,&back,num)
// in main back(*back) is pointer, that store the address of the node
// use (**back) pointer points to a pointer(*back), use it to what pointer *back store the address of Node.(so we can move what it points to)
// while change we assess the pointer's address(which is the value store in other functions)
// others: in main, there is int a, in another func we use int *a, to change the value of a in tha main function
void AddBack(Node **head, Node **back, int num)
{
  // step -1: create a pointers *newNode, points to a Node 1, and modify inside Node 1's value
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->idx = num;
  newNode->next = NULL;

  (*back)->next = newNode; // step -2: link the node 0 and node 1/ next iteration will link node 1 and node 2
  (*back) = newNode;       // step -3: change *back pointer to point to the latest node

  // below is redundant, as when first initiate *head = *back
  // if (*head == *back) // first initialized *head and *back both point to dummy
  // {
  //   (*head)->next = newNode; // dummy(where *head is) points to newNode
  //   return;
  // }
  return;
}
void DeleteFront(Node **head, Node **back)
{
  // first initialized no nodes yet, only node 0
  if ((*head) == (*back))
    return;

  // If there was only one node in the list
  if ((*head)->next->next == NULL)
  {
    free((*head)->next);
    (*head)->next = NULL;
    *back = *head;
    return;
  }
  // more than 1 nodes
  Node *temp = (*head)->next; // *temp points to (*head=dummy) points to, which is the first node
  (*head)->next = (*head)->next->next;
  free(temp);
  return;
}
void Delete(Node **head, Node **back, int num) // deleted specific num
{
  // no delete
  if (*head == *back) //(*head)->idx == -1 && (*back)->idx == -1) //(*head == NULL)  empty list
    return;
  // if delete only one
  if ((*head)->next->next == NULL && (*head)->next->idx == num)
  {
    free((*head)->next);
    (*head)->next = NULL;
    *back = *head;
    return;
  }

  Node *current = (*head)->next;
  Node *prev = (*head);

  while (current != NULL)
  {
    if (current->idx == num) // step1: delete
    {
      prev->next = current->next;
      // if delete the last
      if (current == *back)
        *back = prev;

      // other cases:
      free(current);        // delete current
      current = prev->next; // Move to the next node after deletion
    }
    else // step1: not delete but move forward
    {
      prev = current;
      current = current->next; // Move to the next node
    }
  }
}

void Swap(Node **head, Node **back)
{
  // we need three, cuz we need to reverse the pointer so need A, B, C
  Node *prev = (*head);
  Node *current = (*head)->next;
  Node *next = (*head);  // as prev
  *back = (*head)->next; // Update back points to the first node

  while (current != NULL)
  {
    next = current->next; // move *next to the front of current
    current->next = prev; // Reverse the pointer
    prev = current;       // move *prev to the place of current;
    current = next;       // move *current to the place of next;
  }
  (*head)->next = prev; // after while loop, prev points to last node, update the head to last node
  (*back)->next = NULL; // make sure
}
/*
The memory allocated using malloc within a function persists beyond the function's scope if the pointer pointing to that memory is passed outside the function. In your code, AddFront and AddBack functions allocate memory for new nodes and link them to the existing list via pointers.

In both AddFront and AddBack functions, you're correctly allocating memory for new nodes and manipulating pointers to maintain the linked list structure. The key aspect is that you're updating the back pointer, which is being passed by reference (Node **back), to point to the last node in the list after each addition. This allows the main function to maintain access to the entire list since it holds pointers to both the head and the last node.

In your code, AddFront and AddBack functions are correctly linking the newly allocated nodes to the existing list and updating the back pointer, which enables the main function to print the entire list, including the nodes added by AddBack.

This behavior occurs because pointers are passed by reference in C. When you pass a pointer to a function and modify the data it points to (in this case, modifying the linked list structure), those changes persist beyond the function's scope, allowing the main function or other functions to access and manipulate the updated data.

>>
so you said if the function in AddBack the space of Node (newNode) I created is linked with the Node in main function, it will persist beyond its function scope and remain existed , even though the function called ended?
if I created a newNode , not linked with node in the main function, it will perish after the function call ended?
>>
When you allocate memory for a new node (like newNode) within a function using malloc, that memory remains allocated until you explicitly deallocate it using free. However, the scope and accessibility of that memory depend on whether you've linked it to existing data structures (like the main linked list).

If you create a newNode within a function and do not link it to any existing data structures outside that function, it will indeed persist in memory after the function ends. However, without a reference to that memory space, you won't be able to access or use it further in your program, resulting in a memory leak.

On the other hand, if you create a newNode within a function and properly link it to the existing data structures (for example, by updating pointers in the main linked list), then the memory allocated for that node will persist beyond the function call and remain part of the main data structure. This is because you've changed the state of the main data structure by linking the new node, and those changes remain even after the function call ends.

In summary, memory allocated using malloc persists until explicitly deallocated with free. Whether the changes made within a function persist beyond the function's scope depends on whether those changes affect the state of the larger program, such as updating pointers or connecting new nodes to existing data structures outside the function.
*/