#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n, c;
struct Student
{
	char id[10];
	char name[10];
	int score;

	bool operator < (const Student &cmp) const
	{
		int t1 = strcmp(id, cmp.id);
		int t2;
		switch(c)
		{
		case 1:
			return t1 < 0;
		case 2:
			t2 = strcmp(name, cmp.name);
			if(t2 == 0)
				return t1 < 0;
			else
				return t2 < 0;
		case 3:
			if(score == cmp.score)
				return t1 < 0;
			else
				return score < cmp.score;

		}
	}
} buf[100000];

int main()
{
	freopen("input.txt", "r", stdin);

	int cnt = 0;

	while(scanf("%d%d", &n, &c) != EOF)
	{
		if(n == 0)
			break;
		cnt ++;

		for(int i = 0; i < n; i++)
		{
			scanf("%s%s%d", &buf[i].id, &buf[i].name, &buf[i].score);
		}

		sort(buf, buf + n);

		printf("%s %d:\n", "Case", cnt);
		
		for(int i = 0; i < n; i++)
		{
			printf("%s %s %d\n", buf[i].id, buf[i].name, buf[i].score);
		}
	}

	return 0;
}

