#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	bool ans;
	while(scanf("%d", &n) != EOF)
	{
		ans = true;
		
		if(n > 1)
		{
			for(int i = 2; i < n / 2; i++)
			{
				if(n % i == 0)
					ans = false;

			}
		}
		else
			ans = false;

		printf("%s\n", ans ? "yes" : "no");
	}

	return 0;
}