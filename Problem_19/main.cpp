#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	int buf[80];

	while(scanf("%d", &n) != EOF)
	{
		while(n-- > 0)
		{
			int m;
			scanf("%d", &m);

			for(int i = 0; i < m; i++)
			{
				scanf("%d", &buf[i]);
			}
			bool first = true;
			for(int i = 0; i < m; i++)
			{
				if(i == 0)
				{
					if(buf[i + 1] != buf[i])
					{
						if(first)
						{
							first = false;
							printf("%d", i);
						}
						else
							printf(" %d", i);
					}
				}
				else if(i == m - 1)
				{
					if(buf[i - 1] != buf[i])
					{
						if(first)
						{
							first = false;
							printf("%d", i);
						}
						else
							printf(" %d", i);
					}
				}
				else
				{
					if(buf[i - 1] < buf[i] && buf[i] > buf[i + 1] || buf[i - 1] > buf[i] && buf[i] < buf[i + 1])
					{
						if(first)
						{
							first = false;
							printf("%d", i);
						}
						else
							printf(" %d", i);
					}
				}
			}

			printf("\n");
		}
	}
}