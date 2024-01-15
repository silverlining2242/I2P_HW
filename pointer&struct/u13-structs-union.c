#include <stdio.h>
#pragma pack(4)
// pragma: provide additional information to the compiler or control specific aspects of the compilation process.#pragma pack: Controls structure packing and alignment.
// #pragma pack(4) specify how many bytes(8) we want to use for memory alignment
// ex: if pack(4), we can still use remaining 4 bytes space to store next data that is larger then 4 btyes

struct example1
{
  short a; // 2 bytes > 4
  long b;
}; // it takes 12
struct example2
{
  char c;                  // 4
  struct example1 struct1; // 12
  short s;                 // 2 > 4
};                         // it takes 20 bytes
#pragma pack().            // goes to original?
int main()
{
  struct example1 e1;
  struct example2 e2;
  printf("%ld\n", sizeof(e1));
  printf("%ld\n", sizeof(e2));
  return 0;
}
