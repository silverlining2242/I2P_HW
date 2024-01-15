#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddBack(Node** head, Node** back, int* arr, int n);
void LinearDelete(Node** head, Node** back);