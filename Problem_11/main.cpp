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

		if(n < m)
			m = n;

		for(int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			buf[tmp + OFFSET] = true;
		}

		for(int i = 500000; m > 0 && i >= -500000; i--)
		{
			if(buf[i + OFFSET] == true)
			{
				if(m == 1)
					printf("%d\n", i);
				else
					printf("%d ", i);
				m --;
			}
		}

	}

	return 0;
}