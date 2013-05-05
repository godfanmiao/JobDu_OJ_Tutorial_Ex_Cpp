#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	int buf[201];
	int score[201];

	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 1; i <= m; i++)
		{
			score[i] = 0;
		}

		for(int i = 1; i <= n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			buf[i] = tmp;
			score[tmp] ++;
		}

		for(int i = 1; i <= n; i++)
		{
			if(score[buf[i]] == 1)
				printf("BeiJu\n");
			else
				printf("%d\n", score[buf[i]] - 1);
		}
	}

	return 0;
}