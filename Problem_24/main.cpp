#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int l, n;
	int buf[600];

	while(scanf("%d%d", &l, &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &buf[i]);
		}

		sort(buf, buf + n);
		
		bool ans = false;
		int sum = 0;
		int cnt = 0;

		while(n > 0)
		{
			sum += buf[n - 1];
			cnt ++;
			if(sum >= l)
			{
				ans = true;
				break;
			}
			n --;
		}

		if(ans)
			printf("%d\n", cnt);
		else
			printf("%s\n", "impossible");
	}

	return 0;
}