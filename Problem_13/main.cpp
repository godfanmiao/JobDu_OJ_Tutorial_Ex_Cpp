#include <stdio.h>

bool trees[10001];

int main()
{
	freopen("input.txt", "r", stdin);

	int l, m;
	while(scanf("%d%d", &l, &m) != EOF)
	{
		for(int i = 0; i <= l; i++)
		{
			trees[i] = true;
		}

		int start, end;

		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d", &start, &end);
			for(int j = start; j <= end; j++)
				trees[j] = false;
		}

		int cnt = 0;

		for(int i = 0; i <= l; i++)
		{
			if(trees[i] == true)
				cnt ++;
		}

		printf("%d\n", cnt);
	}
	return 0;
}