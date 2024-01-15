#include <stdio.h>
void swap(int * u, int * v);

int main(void)
{
  int y = 2, z = 5;
  printf("Before calling swap(), y = %d and z = %d.\n", y, z);
  swap(&y, &z);
  printf("After calling swap(), y = %d and z = %d.\n", y, z);
  //>> not change return 0;
}

void swap(int * u, int * v)
{
  int temp;
  printf("In swap(), before swapping, u = %d and v = %d.\n", *u, *v);
  // u = &y
  // v = &z
  temp = *u; 
  *u = *v;
  *v = temp;

  printf("In swap(), after swapping, u = %d and v = %d.\n", *u, *v);
}
/*
Output :
Before calling swap(), y = 2 and z = 5.
In swap(), before swapping, u = 2 and v = 5.
In swap(), after swapping, u = 5 and v = 2.
After calling swap(), y = 2 and z = 5.
*/
