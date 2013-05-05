#include <stdio.h>

bool buf[1000001];

int main()
{
	for(long long i = 2; i <= 1000000; i++)
		buf[i] = true;

	int count = 0;
	for(long long i = 2; i <= 1000000; i++)
	{
		if(buf[i] == true)
		{
			count ++;

			for(long long j = i * i; j <= 1000000; j += i)
			{
				buf[j] = false;
			}
		}
		else
			continue;
	}
	//printf("%d\n", count);

	int n;
	freopen("input.txt", "r", stdin);

	while(scanf("%d", &n) != EOF)
	{
		int count = 0;
		for(int i = 2; i <= 10000000; i++)
		{
			if(buf[i] == true)
			{
				count ++;
				if(count == n)
				{
					printf("%d\n", i);
					break;
				}
			}
		}
	}

	return 0;
}