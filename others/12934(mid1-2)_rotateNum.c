#include <stdio.h>
#include <string.h>
/*
rotate 180, 0: valid, 1 : remain the same|| 6: change to 9, 9 change to 6
0 1 2 3 4 5 6 7 8 9
1 1 0 0 0 0 6 0 1 9
*/

int Check(char ch)
{
  int num = ch - '0';
  if (num >= 2 && num <= 5 || num == 7)
    return 0;
  if (num == 0 || num == 1 || num == 8)
    return 1;
  if (num == 6 || num == 9)
    return num;
}

int main()
{
  char str1[101]; // requirement 100 +1 for '\0' string terminator
  char str2[101]; // after reverse
  scanf("%s", str1);
  int len = strlen(str1);
  // reverse string
  int idx = 0;
  int flag = 1; // assume is valid string
  for (int i = len - 1; i >= 0; i--)
  {
    if (str1[i] == '0' && idx == 0) // no leading 0
      continue;
    // check change of str1 valid before store it to str2
    int valid = Check(str1[i]);
    if (valid == 0)
    {
      flag = 0;
      break;
    }
    else if (valid == 1)
    {
      str2[idx] = str1[i];
    }
    else if (valid == 6)
    {
      str2[idx] = '9';
    }
    else if (valid == 9)
    {
      str2[idx] = '6';
    }
    idx++;
  }
  str2[idx] = '\0'; // **add terminator, or it will have seg fault

  if (flag)
    printf("%s\n", str2);
  else
    printf("No\n");
  return 0;
}