#include <stdio.h>

int buf[100];

int main()
{

	freopen("input.txt", "r", stdin);

	long long a, b;
	int m;

	while(scanf("%d%lld%lld", &m, &a, &b) != EOF && m != 0)
	{
		//printf("%lld %lld\n", a, b);
		int size = 0;
		a = a + b;

		do
		{
			//printf("%d\n", a % m);
			buf[size++] = a % m;
			a /= m;
		}
		while(a > 0);

		while(size > 0)
		{
			printf("%d", buf[--size]);

		}

		printf("\n");
	}
}