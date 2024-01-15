#include <stdio.h>
#include <string.h>
#include "function.h"

int main()
{
    char str[50];
    
    Node* head = (Node*) malloc(sizeof(Node));
    Node* back = head;
    // initialize the dummy head
    
    // we'll append the element after this dummy head to avoid runtime error.
    head->idx = -1;
    head->next = NULL;
    
    while (scanf("%s", str) != EOF) {
        
        int n, m;
        
        if (!strcmp(str, "AddBack")) {
            scanf("%d", &n);
            
            int* arr = (int*) malloc(sizeof(int) * n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            
            AddBack(&head, &back, arr, n);
            free(arr);
        } else if (!strcmp(str, "LinearDelete")) {
            LinearDelete(&head, &back);
        }
    }
    
    // print all the element except the dummy head and free them.
    Node* print = head;
         
    if (head->next == NULL) printf("empty\n");
    
    while (print != NULL) {
        if (print->idx != -1)
            printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));
        
        Node* del = print;
        print = print->next;
        free(del);
    }
}