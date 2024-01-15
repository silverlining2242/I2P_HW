#include <stdio.h>
#include "11711.h"
unsigned random_seed = 7122;
unsigned Random()
{
	return random_seed = random_seed * 0xdefaced + 1;
}
int main()
{
	int n, m, k, r;
	scanf("%d%d%d%d%u", &r, &n, &m, &k, &random_seed);
	while (r--)
	{
		unsigned ***arr = new_3d_array(n, m, k);
		int i, j, l;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < m; ++j)
			{
				for (l = 0; l < k; ++l)
				{
					arr[i][j][l] = Random();
				}
			}
		}
		for (i = 0; i < 5; ++i)
		{
			unsigned a, b, c;
			a = Random() % n;
			b = Random() % m;
			c = Random() % k;
			if (i) //space between each 
				putchar(' ');
			printf("%u", arr[a][b][c]);
		}
		puts(""); // puts print a newline at the end
		delete_3d_array(arr);
	}
	return 0;
}
