#include <stdio.h>
int h, w;
float kernel[3][3];
int extract[3][3];
int image[300][300];
// declare the max! not using image[h][w](may cause error, search: VLA), as we need to allocate memory upon compiling not run time
// we can only for loop til the h and w
// if we want to determine memory during run time, using malloc and free.
float result[300 - 3 + 1][300 - 3 + 1];

// given position of image to extract 3*3 temp
void extractmatrix(int image[][300], int x, int y)
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      extract[i][j] = image[x + i][y + j];
    }
  }
}
// multiply two matrix and return the sum (or directly print it)
void multi(float kernel[][3], int extract[][3])
{
  float sum = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      sum += kernel[i][j] * extract[i][j];
    }
  }
  printf("%4d ", (int)sum); //**change to int before print!! or it will be wrong!
  // return sum;
}

int main()
{
  // input
  scanf("%d %d", &w, &h);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      scanf(" %f", &kernel[i][j]);
    }
  }
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      scanf(" %d", &image[i][j]);
    }
  }
  // multiply
  for (int i = 0; i < h - 3 + 1; i++)
  {
    for (int j = 0; j < w - 3 + 1; j++)
    {
      extractmatrix(image, i, j); // get temp
      multi(kernel, extract);     // print it in function
    }
    printf("\n");
  }

  return 0;
}