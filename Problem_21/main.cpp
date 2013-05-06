#include <stdio.h>
#include <algorithm>

using namespace std;

struct wareHouse
{
	double f;
	double j;
	double rate;

	bool operator < (const wareHouse & cmp) const
	{
		return rate > cmp.rate;
	}
} buf[1001];

int main()
{
	freopen("input.txt", "r", stdin);
	int m;
	double n;

	while(scanf("%lf %d", &n, &m) != EOF)
	{
		if(n == -1 && m == -1)
			break;
		for(int i = 0; i < m; i++)
		{
			scanf("%lf%lf", &buf[i].j, &buf[i].f);
			buf[i].rate = buf[i].j / buf[i].f;
		}

		sort(buf, buf + m);

		int cnt = 0;
		double sum = 0.0;

		while(n > 0 && cnt < m)
		{
			if(buf[cnt].f <= n)
			{
				sum += buf[cnt].j;
				n -= buf[cnt].f;
			}
			else 
			{
				sum += buf[cnt].rate * n;
				n = 0;
			}
			cnt ++;
		}

		printf("%.3lf\n", sum);
	}
}
