#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int buf[100];

	int n, m;

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%d", &buf[i]);

		sort(buf, buf + n);

		scanf("%d", &m);

		for(int i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x);

			int lo = 0, hi = n - 1;
			int ans = -1;

			while(lo <= hi)
			{
				int mid = (lo + hi) / 2;

				if(buf[mid] == x)
				{
					ans = mid;
					break;
				}
				else if(buf[mid] > x)
					hi = mid - 1;
				else
					lo = mid + 1;
			}

			if(ans == -1)
				printf("NO\n");
			else
				printf("YES\n");
		}

	}
	return 0;
}