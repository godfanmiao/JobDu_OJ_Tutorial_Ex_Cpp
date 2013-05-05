#include <stdio.h>

bool buf[10001];
int ans[10001];

int main()
{

	freopen("input.txt", "r", stdin);
	int n;

	for(int i = 2; i <= 10000; i++)
		buf[i] = true;
	for(int i = 2; i <= 10000; i++)
	{
		if(buf[i] == true)
		{
			for(int j = i * i; j <= 10000; j += i)
			{
				buf[j] = false;
			}
		}
		else
			continue;
	}


	while(scanf("%d", &n) != EOF)
	{
		int count = 0;
		for(int i = 2; i < n; i++)
		{
			if(buf[i] == true && i % 10 == 1)
				ans[count++] = i;
		}

		if(count == 0)
			printf("-1\n");
		else
		{
			for(int i = 0; i < count; i++)
			{
				if(i == count - 1)
					printf("%d\n", ans[i]);
				else
					printf("%d ", ans[i]);
			}
		}
	}

	return 0;
}