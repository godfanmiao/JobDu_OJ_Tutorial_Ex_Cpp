#include <stdio.h>

int list[26];
int dp[26];

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int n;

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &list[i]);
		}

		dp[1] = 1;
		int tmax;
		for(int i = 1; i <= n; i++)
		{
			tmax = 1;
			for(int j = 1; j < i; j++)
			{
				if(list[j] >= list[i])
				{
					tmax = max(tmax, dp[j] + 1);
				}
			}
			dp[i] = tmax;
		}

		int ans = 1;

		for(int i = 1; i <= n; i++)
		{
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}

	return 0;
}