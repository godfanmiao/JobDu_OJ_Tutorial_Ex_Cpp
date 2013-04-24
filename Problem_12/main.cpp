#include <stdio.h>
int buf[1000000];

int main()
{
	freopen("input.txt", "r", stdin);

	int book[201];

	int n, m;

	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = 0; i <= 200; i++)
			book[i] = 0;

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &buf[i]);
		}

		for(int i = 0; i < n; i++)
		{
			book[buf[i]] ++;
		}

		for(int i = 0; i < n; i++)
		{
			int ans = book[buf[i]] - 1;
			if(ans == 0)
				printf("BeiJu\n");
			else
				printf("%d\n", ans);
		}
	}
	return 0;
}