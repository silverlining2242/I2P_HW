#include <stdio.h>
#include <stdlib.h>

typedef struct t_complex
{
  double r;
  double i;
} Complex;                                 // complex number
void add(Complex a, Complex b, Complex *t) // a+b->(*t)
{
  t->r = a.r + b.r; //(like c.r= a.r+b.r; )
  t->i = a.i + b.i; //(like c.i= a.i+b.i; )
}

void set_complex(Complex *p, double r, double i) // use pointer to change variable in main func
{
  p->r = r;
  p->i = i;
}
void show_complex(Complex t)
{
  printf("%.2f%+.2fi\n", t.r, t.i);
}
int main(void)
{
  Complex x, y, z;

  set_complex(&x, 1, 2); // set real as 1, imaginary of 2
  set_complex(&y, 2, -3);
  add(x, y, &z);
  show_complex(z);

  return 0;
}
