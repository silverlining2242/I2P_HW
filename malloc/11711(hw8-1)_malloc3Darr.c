/*
11711 Dynamic 3D array
to complete the function definition from h8-1_11711.h
the main execute is in hw-8_11711.c
*/
#include <stdio.h>
#include <stdlib.h> //this for memory allocation funtion or random number generations..

unsigned ***new_3d_array(unsigned n, unsigned m, unsigned k)
{
  unsigned *lk;   // 3rd layer for k
  unsigned **lm;  // 2nd layer for m
  unsigned ***ln; // 1st layer for n

  unsigned i, j;

  // Allocate memory for the 3rd layer
  // which represents the total number of elements in the 3D array.
  // is like to create n * m * k blocks of memory space
  lk = (unsigned *)malloc(sizeof(unsigned) * n * m * k);

  // Allocate memory for the 2nd layer
  // lm is pointer to a pointer unsigned **
  lm = (unsigned **)malloc(sizeof(unsigned *) * n * m);
  for (i = 0; i < n * m; i++)
  {
    lm[i] = &lk[i * k]; // Each element in lm points to a block of k unsigned values in lk
  }

  // Allocate memory for the 1st layer
  ln = (unsigned ***)malloc(sizeof(unsigned **) * n);
  for (i = 0; i < n; i++)
  {
    ln[i] = &lm[i * m]; // Each element in ln points to a block of m pointers in lm
  }

  return ln; // return address of ln
}

void delete_3d_array(unsigned ***arr)
{
  // delete backward from the most inside layer
  free(arr[0][0]);
  free(arr[0]);
  free(arr);
}
/*
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k);
void delete_3d_array(unsigned ***arr);
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    unsigned ***ptr1,**ptr2,*ptr3;
    ptr1=(unsigned ***)malloc(n*sizeof(unsigned**)+n*m*sizeof(unsigned*)+n*m*k*sizeof(unsigned));

    ptr2 = (unsigned**)(ptr1+n);
    for(int i=0;i<n;i++,ptr2+=m){
        *(ptr1+i)=ptr2;
    }

    ptr3 = (unsigned*)ptr2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++,ptr3+=k){
            *(*(ptr1+i)+j)=ptr3;
        }
    }
    return ptr1;
}
void delete_3d_array(unsigned ***arr){
    free(arr);
}
*/