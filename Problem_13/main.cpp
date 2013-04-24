#include <stdio.h>

bool buf[10001];

int main()
{
	freopen("input.txt", "r", stdin);

	int L, M;

	while(scanf("%d%d", &L, &M) != EOF)
	{
		for(int i = 0; i <= L; i++)
		{
			buf[i] = true;
		}

		for(int i = 0; i < M; i++)
		{
			int start, end;
			scanf("%d%d", &start, &end);

			for(int j = start; j <= end; j++)
			{
				buf[j] = false;
			}
		}

		int count = 0;
		for(int i = 0; i <= L; i++)
		{
			if(buf[i])
				count ++;
		}

		printf("%d\n", count);
	}

	return 0;
}