#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);

	int h;
	while(scanf("%d", &h) != EOF)
	{
		for(int i = 1; i <= h; i++)
		{
			for(int j = 2 * (h - i); j > 0; j--)
			{
				printf(" ");
			}
			for(int k = h + (i - 1) * 2; k > 0; k--)
			{
				printf("*");
			}

			printf("\n");
		}
	}
	return 0;
}