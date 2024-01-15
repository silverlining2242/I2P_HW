#include <stdio.h>
#include <stdbool.h>
#include <math.h> //use fabs
/*The solution with this question starts with the number of numbers after every iteration. Once an operation is used, the total number available decreases by 1 hence by the third iteration, there will be only one number left, this will be our base case.*/
#define EPSILON 1e-6

bool judgePoint24(double cards[], int size)
{
  // base case
  if (size == 1) // one one cards
  {
    return fabs(cards[0] - 24.0) < EPSILON; // fabs return absolute value
  }
  // recur: chose two to op
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (i != j) // 2D array to opt with two chosen num, don't op with itself
      {
        double newCards[4];
        int newidx = 0;
        // only store none chosen num to newCards (will be 0 1)
        for (int k = 0; k < size; k++)
        {
          if (k != i && k != j)
          {
            newCards[newidx++] = cards[k];
            // newidx++ //**put here !! not outside
          }
        }
        // newCards[2] = chosen to op result
        // after loop idx will plus one, and use it to store two chosen num op result
        // first call newidx = 2, as _ _ _, the last is to be stored new op
        newCards[newidx] = cards[i] + cards[j]; // two chosen num to op and store into newcards[idx];
        if (judgePoint24(newCards, newidx + 1)) // **newidx+1; as iteration should from 0 1 2, (3)
          return true;

        newCards[newidx] = cards[i] - cards[j];
        if (judgePoint24(newCards, newidx + 1))
          return true;

        newCards[newidx] = cards[i] * cards[j];
        if (judgePoint24(newCards, newidx + 1))
          return true;

        if (cards[j] != 0) // it's card j not j!!!
        {
          newCards[newidx] = cards[i] / cards[j];
          if (judgePoint24(newCards, newidx + 1))
            return true;
        }
      }
    }
  }

  return false; //**very important!!!!
}

int main()
{
  double cards[4]; // can be put globally
  int q;
  scanf("%d", &q);
  while (q--)
  {
    for (int i = 0; i < 4; i++)
    {
      scanf("%lf", &cards[i]); //*%lf
    }
    bool result = judgePoint24(cards, 4);
    if (result)
      printf("Safe\n");
    else
      printf("Disqualified\n");
  }

  return 0;
}