#include <stdio.h>
#include <stdlib.h>
typedef struct t_data
{
  int size;
  int *ptr; // a pointer point to int object
} DATA;
void create_data(DATA *, int);
DATA clone_data(DATA);
void show_data(DATA);
void delete_data(DATA *);

int main(void)
{
  DATA x, x_clone;

  create_data(&x, 100);
  show_data(x);

  x_clone = clone_data(x);
  // why not x_clone = x directly? Cus point to same address but not create a whole new memory space
  delete_data(&x);
  show_data(x_clone);

  return 0;
}
void create_data(DATA *z, int sz)
{
  int i;
  z->size = sz;
  z->ptr = (int *)malloc(sz * sizeof(int));
  for (i = 0; i < sz; i++)
  {
    (z->ptr)[i] = i;
  }
}
void show_data(DATA d)
{
  int i;
  printf("sizeof DATA:%u\n", sizeof(d));
  for (i = 0; i < d.size; i++)
  {
    printf("%d ", (d.ptr)[i]);
    if ((i + 1) % 10 == 0)
      printf("\n");
  }
}
DATA clone_data(DATA x)
{
  int i;
  DATA y;
  y.size = x.size;
  y.ptr = (int *)malloc(y.size * sizeof(int)); // create another whole space for the array
  for (i = 0; i < y.size; i++)
  {
    (y.ptr)[i] = (x.ptr)[i];
  }
  return y;
}
void delete_data(DATA *z)
{
  free(z->ptr); // release the memory pointed to by ptr
  z->ptr = NULL;
  z->size = 0;
}
