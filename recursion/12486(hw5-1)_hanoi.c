#include <stdio.h>

// n disk
void hanoi(int n, char A, char B, char C);

int main()
{
  int n;
  scanf("%d", &n);
  hanoi(n, 'A', 'B', 'C');
  return 0;
}
// base A/ temp B/ goal C
void hanoi(int n, char A, char B, char C)
{
  // base case: if only one stack
  if (n == 1)
  {
    printf("move disk %d from rod %c to rod %c\n", n, A, C);
    return;
  }
  else
  {
    // induction case
    // we can think 2 stack case
    // move n-1 th (above for recursive) from base A to temp B
    hanoi(n - 1, A, C, B); // n-1 is for recursive iteration
    // then can move bottom to the goal target c (one step no recursive)
    printf("move disk %d from rod %c to rod %c\n", n, A, C); //print what you move
    // stack n-1 th (above for recursive) to stack back on goal
    hanoi(n - 1, B, A, C);
  }
}

/*
print from 0 > 1 > 2 > 3
void hanoi(int n, char A, char B, char C)
{
  if (n > 0)
  {
    hanoi(n - 1, A, B, C);
  }
  else
  {
    printf("end\n");
  }
  printf("move disk %d from rod %c to rod %c\n", n, A, C);

}
*/