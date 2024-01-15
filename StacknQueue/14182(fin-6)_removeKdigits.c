#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
one is input array
create another empty stack array, store from the most significant digit,
iterate: if next input in the input array is smaller than the top one of stack array, remove the top and put the new one from input array
45996991, move 2 digit, the place matters than the value of the input
>> 456991 (correct, it move the 9 from more siginificant digit)
>> 459961

513921, remove 2
5> 1 > 139 > 1321
remove 5, 9
*/
void removeKdigits(char *input, int k)
{
  // create empty array for stacking
  int len = strlen(input);
  int top = -1; // Stack top index, not len!
  // char stack[len];
  char *stack = (char *)malloc(sizeof(char) * len);

  // compare top of stack array with input array
  for (int i = 0; i < len; i++)
  {
    // if top is smaller, remove top and stack input[i]
    while (k > 0 && top >= 0 && stack[top] > input[i]) //**must use while
    {
      top--; //**top is the idx of the stack arr
      k--;// successfully remove k digit
    }
    // after removing top stack or not, directly put input[i] to top of stack
    // *must use pre-increment for top ! we need + first before insert new on top
    stack[++top] = input[i]; // move top input array to stack on top of stack arr **++top
    // // print check
    // printf("stack: %c, input: %c\n", stack[top], input[i]);
    // for (int i = 0; i <= top; i++)
    //   printf("%c", stack[i]);
    // printf("\n");
    // printf("top: %d\n", top);
  }
  // at the end top = top - k(remove k digit)
  // edge case:only one num , when input = 3/ 1, top need 0 > -1
  top = top - k;
  // printf("top: %d\n", top);

  // if leading zero: move index one ahead to avoid printing leading 0
  int i = 0;
  while (stack[i] == '0' && i <= top) //*it's '0'
  {
    i++;
  }
  // Print the stack array
  if (i > top) // equals to top == -1, nothing in stack, print 0
  {
    printf("0\n");
    return;
  }
  while (i <= top)
  {
    printf("%c", stack[i++]); // post-increment: we need print stack[0]first
  }
  printf("\n");

  free(stack);
}

int main()
{
  char input[1000001];
  int k;
  scanf("%s", input);
  scanf("%d", &k);
  removeKdigits(input, k);
  return 0;
}

/* modify the leading zero array: it will have TLE error
// leading zero: move string one place ahead
  while (stack[0] == '0')
  {
    for (int i = 0; i <= top; i++)
    {
      stack[i] = stack[i + 1];
      stack[top] = '\0';
    }
    top--; // update the last index of stack
  }
  // Print the stack array
  if (top == -1) // if top == -1, nothing in stack, print 0
  {
    printf("0\n");
    return;
  }
  for (int i = 0; i <= top; i++)
  {
    printf("%c", stack[i]);
  }
  printf("\n");
*/