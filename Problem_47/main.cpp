#include <stdio.h>

int gcd(int a, int b)
{
	if(a > b)
		return gcd(b, a - b);
	if(a == b)
		return a;
	if(a < b)
		return gcd(b, b - a);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int a, b;

	while(scanf("%d%d", &a, &b) != EOF)
	{
		printf("%d\n", gcd(a, b));
	}
	return 0;
}