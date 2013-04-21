#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	int buf[110];

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &buf[i]);
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = i; j > 0 && buf[j] < buf[j - 1]; j--)
			{
				int tmp = buf[j - 1];
				buf[j - 1] = buf[j];
				buf[j] = tmp;
			}
		}

		for(int i = 0; i < n; i++)
		{
			printf("%d ", buf[i]);
		}

		printf("\n");
	}
}