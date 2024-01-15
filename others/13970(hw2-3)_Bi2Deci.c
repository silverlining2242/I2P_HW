#include <stdio.h>
#include <math.h>
// not put rev[5] to restrict passing argu, but put n in another parameter
int BtoD(char rev[], int n)
{
  int decimal;
  for (int i = 0; i < n; i++)
  {
    decimal += (rev[i] - '0') * pow(2, i); // remember to convert 1 in char using -'0'
  }

  return decimal;
}

int main()
{
  // if it's 6 char string ,declare 7, always left 1 to store string terminator '\0'
  char input[7]; // 6 digit binary representation, 1st is signed bit 0 is uppercase
  scanf("%s", input);

  // reverse string and obit signed bit
  char rev[6]; // we need create new arr, if modify the original, like 1234, it will be 4334
  for (int i = 0; i < 5; i++)
  {
    rev[i] = input[6 - 1 - i];
  }
  rev[5] = '\0'; // terminate string! last index is 5
  // printf("%s\n",rev); //check

  // calc binary to decimal
  int decimal = BtoD(rev, 5);
  // printf("%d\n", decimal); //check

  // print out the char based on the decimal
  char ch = 'A' - 1 + decimal; // if decimal = 1, should be'A'
  // printf("%d %d %d\n", input[0], 'A', 'a'); // A is 65, a is 97, '0' = 48/ 97-65 = 32
  ch += (input[0] - '0') * 32; // input[0] = 0 upper/ 1 lower; without using if-else
  printf("%c\n", ch);

  return 0;
}
/*
input: 010010
0 is uppercase
10010 in binary is 18,which is R
*/
/* 2nd way, reading 1 char at a time and calculate

int main(){
    int a,b,c,d,e,f;
    scanf("%1d%1d%1d%1d%1d%1d", &a, &b, &c, &d, &e, &f);
    char ch = a *32 + b * 16 + c * 8 + d * 4 + e * 2 + f + 64;
    printf("%c\n", ch);
}

// by  Aurick


*/