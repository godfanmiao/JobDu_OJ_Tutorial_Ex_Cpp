#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	int n;

	while(scanf("%d", &n) != EOF)
	{
		for(int m = 2 * (n - 1); m >= 0; m -= 2)
		{
			for(int i = 1; i <= m; i++)
			{
				printf(" ");
			}

			for(int j = 1; j <= 2 * (n - 1) + n - m; j++)
			{
				printf("*");
			}

			printf("\n");
		}
	}

	return 0;
}