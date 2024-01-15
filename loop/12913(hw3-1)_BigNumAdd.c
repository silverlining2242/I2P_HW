/*use array to complete the addition operation*/
#include <stdio.h>
int lenA, lenB;
int digitA[100], digitB[100];
int revA[100], revB[100];
int sum[101];

void reverse(int arr[], int change[], int n)
{
  for (int i = 0; i < n; i++)
  {
    change[i] = arr[n - 1 - i];
  }
  return;
}

int main()
{
  // input

  scanf("%d", &lenA);
  for (int i = 0; i < lenA; i++)
  {
    scanf("%1d", &digitA[i]);
  }
  scanf("%d", &lenB);
  for (int i = 0; i < lenB; i++)
  {
    scanf("%1d", &digitB[i]);
  }

  // reverse arr
  reverse(digitA, revA, lenA);
  reverse(digitB, revB, lenB);

  // add up
  int max = (lenA >= lenB) ? lenA + 1 : lenB + 1; // +1 for carry for next digit
  int carry = 0;
  for (int i = 0; i < max; i++)
  {
    if (i >= lenA)
    {
      sum[i] = (revB[i] + carry) % 10;
      carry = (revB[i] + carry) / 10; // update for next iteration
    }
    else if (i >= lenB)
    {
      sum[i] = (revA[i] + carry) % 10;
      carry = (revA[i] + carry) / 10;
    }
    else if (i >= lenA && i >= lenB)
    {
      sum[i] = carry;
    }
    else
    {
      sum[i] = (revA[i] + revB[i] + carry) % 10;
      carry = (revA[i] + revB[i] + carry) / 10;
    }
  }
  // printf("%d\n",sum[max-1]);
  if (sum[max - 1] == 0) // if the biggest digit = 0, don't print
    max--;

  // print reverse
  for (int i = max - 1; i >= 0; i--)
  {
    printf("%d", sum[i]);
  }

  return 0;
}
/* directly adding from reverse
  int i = lenA - 1; // array start from 0 ~ n-1
  int j = lenB - 1;
  int k = 0; // Index for the result array

  // Perform addition from right to left
  while (i >= 0 || j >= 0 || carry > 0)
  {

    // int digitA = A[i] ;
    // int digitB = B[j] ;
    // 4 3/3 2/ 2 1/ 1 0/ 0 -1(which cause bug)
    int digitA = (i >= 0) ? A[i]  : 0; // this is important to prevent accessing invalid position of A[i]
    int digitB = (j >= 0) ? B[j]  : 0;

    int sum = digitA + digitB + carry; // carry from last loop
    carry = sum / 10;                  // carry is int so 15/10 will be 1
    result[k] = (sum % 10) ;      // the number is reverse 543 > 345

    k++;
    i--; // add from smallest digit
    j--;
  }

*/