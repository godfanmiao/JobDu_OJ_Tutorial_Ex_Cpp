#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int buf[100];
	int c, n, v, w;

	while(scanf("%d", &c) != EOF)
	{
		for(int i = 0; i < c; i++)
		{
			scanf("%d%d%d", &n, &v, &w);
			for(int j = 0; j < n; j++)
				scanf("%d", &buf[j]);

			sort(buf, buf + n);
			int cnt = 0;
			double sum = 0.0;

			for(int j = 0; j < n; j++)
			{
				double tmpSum = sum;
				int tmpCnt = cnt;
		
				tmpSum += buf[j];
				tmpCnt ++;

				if(tmpSum / tmpCnt > w)
				{				
					break;
				}
				else
				{
					sum = tmpSum;
					cnt = tmpCnt;
				}
			}
			if(cnt == 0)
				printf("0 0.00\n");
			else
				printf("%d %.2lf\n", cnt * v, sum * 0.01 / cnt);
		}
	}

	return 0;
}