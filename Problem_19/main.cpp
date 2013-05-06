#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	int buf[80];
	
	int index[80];

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			int k;
			scanf("%d", &k);

			for(int j = 0; j < k; j++)
			{
				scanf("%d", &buf[j]);
			}
			int size = 0;

			for(int j = 0; j < k; j++)
			{
				if(j == 0)
				{
					if(buf[j] != buf[j + 1])
						index[size ++] = j;
				}
				else if(j == k - 1)
				{
					if(buf[j - 1] != buf[j])
						index[size ++] = j;
				}
				else
				{
					if(buf[j - 1] < buf[j] && buf[j] > buf[j + 1] || buf[j - 1] > buf[j] && buf[j] < buf[j + 1])
						index[size ++] = j;
				}
			}

			for(int j = 0; j < size; j++)
			{
				if(j == size - 1)
					printf("%d\n", index[j]);
				else
					printf("%d ", index[j]); 
			}
		}
	}

	return 0;
}