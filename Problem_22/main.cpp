#include <stdio.h>
#include <algorithm>

using namespace std;

struct Program
{
	int startTime;
	int endTime;

	bool operator < (const Program &cmp) const
	{
		return endTime < cmp.endTime;
	}
} buf[100];

int main()
{
	freopen("input.txt", "r", stdin);
	int n;

	while(scanf("%d", &n) != EOF && n != 0)
	{
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &buf[i].startTime, &buf[i].endTime);
		}

		sort(buf, buf + n);
		
		int endTime = 0;

		for(int i = 0; i < n; i++)
		{
			if(buf[i].startTime >= endTime)
			{
				cnt ++;
				endTime = buf[i].endTime;
			}
		}

		printf("%d\n", cnt);
	}
}