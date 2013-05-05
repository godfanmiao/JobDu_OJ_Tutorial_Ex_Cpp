#include <stdio.h>
#include <algorithm>
using namespace std;

long long buf[300];

int main()
{
	freopen("input.txt", "r", stdin);

	int n, m;

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%lld", &buf[i]);
		}

		sort(buf, buf + n);

		scanf("%d", &m);

		for(int i = 0; i < m; i++)
		{
			long long x;
			scanf("%lld", &x);

			int ans = -1;
			int lo = 0, hi = n - 1;

			while(lo <= hi)
			{
				int mid = (lo + hi) / 2;

				if(buf[mid] == x)
				{
					ans = mid;
					break;
				}
				else if(buf[mid] < x)
				{
					lo = mid + 1;
				}
				else
					hi = mid - 1;
			}

			if(ans == -1)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}

	return 0;
}