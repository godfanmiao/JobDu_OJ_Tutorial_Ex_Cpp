#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	char buf[210];

	while(gets(buf))
	{
		int len = strlen(buf);

		sort(buf, buf + len);

		puts(buf);
	}

	return 0;
}