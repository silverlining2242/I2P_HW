#include <stdio.h>

int main()
{

  // input
  int N, S;
  scanf("%d %d", &N, &S);
  int arr[50];
  for (int i = 0; i < N; i++)
  {
    scanf(" %d", &arr[i]);
  }

  //
  int pwd = 0;
  int i, j, k, m = 0;
  for (i = 0; i < N; i++) // position of string
  {
    int sum = 0;
    sum = arr[i];
    for (j = i + 1; j < N; j++)
    {
      sum= arr[i]; // sum = prev given i
      if (arr[j] >= arr[i])
      {
        // keep finding
        for (k = j + 1; k < N; k++)
        {
          sum = arr[i] + arr[j]; // sum = prev given i + j
          if (arr[k] >= arr[j])
          {
            //sum += arr[k]; //if using accumulate the sum is hard to calc when to be 0 and add up
            // keep finding
            for (m = k + 1; m < N; m++)
            {
              sum = arr[i] + arr[j] + arr[k]; //sum = prev given i + j + k
              if (arr[m] >= arr[k])
              {
                sum += arr[m];
                // check sum
                if (sum == S)
                {
                  pwd++;
                }
                //printf("arr[%d]:%d arr[%d]: %d arr[%d]: %d arr[%d]: %d sum: %d\n", i, arr[i], j, arr[j], k, arr[k], m, arr[m], sum);
                sum = 0;
              }
              else
              {
                continue;
              }
            }
          }
          else
          {
            continue;
          }
        }
      }
      else
      {
        continue;
      }
      
      //sum = 0;
    }
  }

  // print check
  printf("%d\n", pwd);

  return 0;
}