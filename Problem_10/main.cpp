#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);

	int buf[101];

	int n, score;

	while(scanf("%d", &n) != EOF && n != 0)
	{
		for(int i = 0; i <= 100; i++)
			buf[i] = 0;

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &score);
			buf[score] ++;
		}
		
		scanf("%d", &score);
		printf("%d\n", buf[score]);
	}

	return 0;
}