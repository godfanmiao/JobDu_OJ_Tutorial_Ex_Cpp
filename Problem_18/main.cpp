#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Student
{
	char id[100];
	char name[100];
	char sex[10];
	int age;

	bool operator < (const Student &cmp) const
	{
		return strcmp(id, cmp.id) < 0;
	}
} buf[1100];

int main()
{
	freopen("input.txt", "r", stdin);

	int n, m;

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%s%s%s%d", buf[i].id, buf[i].name, buf[i].sex, &buf[i].age);
		}

		sort(buf, buf + n);

		scanf("%d", &m);

		char id[100];

		for(int i = 0; i < m; i++)
		{
			scanf("%s", id);

			int lo = 0, hi = n - 1;
			int ans = -1;
			while(lo <= hi)
			{
				int mid = (lo + hi) / 2;

				if(strcmp(id, buf[mid].id) == 0)
				{
					ans = mid;
					break;
				}
				else if(strcmp(id, buf[mid].id) < 0)
				{
					hi = mid - 1;
				}
				else
				{
					lo = mid + 1;
				}
			}
			if(ans == -1)
				printf("No Answer!\n");
			else
				printf("%s %s %s %d\n", buf[ans].id, buf[ans].name, buf[ans].sex, buf[ans].age);
		}


	}
	return 0;
}