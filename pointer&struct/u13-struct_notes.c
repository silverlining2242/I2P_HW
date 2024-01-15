#include <stdio.h>
#include <stdlib.h>

int main()
{
  // declare of datatype
  ////1st way: declare datatype and then use typedef
  struct object // object is like self-defined datatype, like 'int'
  {
    int x;
    int y;
  };                                // remember to put ;
  typedef struct object Coordinate; // (optional) replace 'struct object' with 'Coordinate'

  ////2nd way: combine declare datatype and typedef
  typedef struct object2 //'object2'can be omitted
  {
    int x;
    int y;
  } Coordinate2;

  // declare variable
  struct object p1;
  Coordinate p2;             // after we used typedef to replace struct + self-defined datatype
  struct object p3 = {5, 7}; // declare and assign at same time. like int arr[5] = {0};
  struct object *ptr4;       // declare a pointer points to the defined datatype object
  Coordinate2 pp1[5];        // declare an array of structures

  // assign value
  p1.x = 23;
  p1.y = 9;
  printf("p1: (%d,%d)\n", p1.x, p1.y);

  // use pointer to change another object's value
  printf("before changed p3: (%d,%d)\n", p3.x, p3.y);
  ptr4 = &p3;
  ptr4->x = 15;   // if it's pointer, assess using ->
  (*ptr4).y = 17; // or use * of whole pointer as object
  printf("after changed p3: (%d,%d)\n", p3.x, p3.y);

  /*Properties*/
  // 1. struct can contain another structure as its member
  typedef struct all_coordinate
  {
    struct object pair1;
    Coordinate2 pair2;
  } All;
  All all;
  all.pair1.x = 3;
  all.pair1.y = 4;

  printf("pair1: (%d,%d)\n", all.pair1.x, all.pair1.y);

  // 2. assignment of structure (memberwise copy)
  struct object cpy1 = p1;
  printf("cpy1: (%d,%d)\n", cpy1.x, cpy1.y);

  return 0;
}