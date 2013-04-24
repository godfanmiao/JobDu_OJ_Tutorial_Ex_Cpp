#include <stdio.h>
#define OFFSET 500000

bool buf[1000001];

int main()
{
	freopen("input.txt", "r", stdin);

	int n, m;

	while(scanf("%d%d", &n, &m) != EOF)
	{
		for(int i = -500000; i <= 500000; i++)
		{
			buf[i + OFFSET] = false;
		}

		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			buf[tmp + OFFSET] = true;
		}

		if (m > n)
			m = n;

		for(int i = 500000; i >= -500000 && m > 0; i--)
		{
			if(buf[i + OFFSET])
			{
				m--;
				printf("%d", i);
				if(m == 0 || i == -500000)
				{
					printf("\n");
				}
				else
					printf(" ");
			}
		}
	}

	return 0;
}