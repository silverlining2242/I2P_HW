#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char z[1001];
  char output[1000001];
  int outidx = 0;
  int scantime = 0;

  while (scanf("%s", z) == 1 && scantime <= 100)
  {
    // in while condition has scanf to z, no need to scanf again
    int len = strlen(z);
    // z[len] = '\0'; // scanf to %s will add \0 in the end, no need to assign '\0'

    //  calc
    int num = 0;
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
      // 如果是數字要收集並回傳總num ex: 12a >>要得到12
      // i = 0, num * 10 = 0, then add z[0]
      // i = 1, num(z[0])*10 + z[1]
      if (z[i] != '\'' && isdigit(z[i]))
      {
        num = num * 10;
        num = num + (z[i] - '0');
      }
      // if Alphabet, check num != 0 then print num times
      else if (isalpha(z[i]))
      {
        if (num == 0)
        {
          flag = 1;
          break;
        }
        else
        {
          for (int j = 0; j < num; j++)
          {
            output[outidx] = z[i]; // store num times of char to output string
            outidx++;              //***new idx +1
          }
          num = 0; //*** 歸零給next iteration
        }
      }
      // if ' ', no number inside
      else if (z[i] == '\'')
      {
        if (num == 0 || !isdigit(z[i + 1]) || i + 2 >= len || z[i + 2] != '\'')
        {
          flag = 1;
          break;
        }

        else
        {
          for (int j = 0; j < num; j++)
          {
            output[outidx] = z[i + 1];
            outidx++;
          }
          num = 0;
          i = i + 2;
        }
      }
    }
    // last -2 must be 0-9, last -1 must be a-z A-Z
    // z 0-9 || a-z ||A-Z >okay
    if (z[len - 1] == '\'')
    {
      if (isdigit(z[len - 2]))
      {
      }
      else
      {
        flag = 1;
      }
    }
    else
    {
      if (isalpha(z[len - 1]))
      {
      }
      else
      {
        flag = 1;
      }
    }

    //  print
    if (flag == 0)
    {
      output[outidx] = '\0';
      printf("%s\n", output);
      // outidx = 0; // reset output index
    }
    else if (flag == 1)
    {
      printf("Domo cannot crack this computer\n");
    }
    // reset num idx and empty the output array
    num = 0;
    outidx = 0; 
    memset(output, 0, sizeof(output));

    scantime++;
  }

  return 0;
}

/*
trlen() function is used to determine the length of a string (excluding the null terminator). In contrast, the sizeof() function is used to determine the size in bytes of a variable or data type (including the null terminator for strings).
*/