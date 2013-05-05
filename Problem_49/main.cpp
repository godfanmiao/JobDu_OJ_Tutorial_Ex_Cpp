#include <stdio.h>

int gcd(int a, int b)
{
	while(b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}

	return a;
}
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}


int main()
{

	freopen("input.txt", "r", stdin);

	int a, b;

	int n;

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			int m;
			scanf("%d", &m);
			a = 1;
			for(int j = 0; j < m; j++)
			{
				scanf("%d", &b);
				a = lcm(a, b);
			}

			printf("%d\n", a);
		}
	}

	return 0;
}