#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	int buf[1001];

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &buf[i]);
		}

		sort(buf, buf + n);

		printf("%d\n", buf[n - 1]);

		if(n - 1 == 0)
		{
			printf("%d\n", -1);
		}
		else
		{
			for(int i = 0; i < n - 1; i++)
			{
				if(i == n - 2)
				{
					printf("%d\n", buf[i]);
				}
				else
					printf("%d ", buf[i]);
			}
		}
	}
}