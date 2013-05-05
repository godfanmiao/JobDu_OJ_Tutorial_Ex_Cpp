#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	int a, b;
	int bufA[11];
	int bufB[11];


	while(scanf("%d%d", &a, &b) != EOF)
	{
		int aSize = 0;
		int bSize = 0;
		while(a > 0)
		{
			bufA[aSize++] = a % 10;
			a /= 10;
		}

		while(b > 0)
		{
			bufB[bSize++] = b % 10;
			b /= 10;
		}

		int ans = 0;

		for(int i = 0; i < aSize; i++)
		{
			for(int j = 0; j < bSize; j++)
			{
				ans += bufA[i] * bufB[j];
			}
		}

		printf("%d\n", ans);
	}
}