#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int c;

struct Student
{
	char id[10];
	char name[20];
	int score;
	
	bool operator < (const Student &cmp) const
	{
		int tmp;
		switch(c)
		{
			case 1:
				return strcmp(id, cmp.id) < 0;		
			case 2:
				tmp = strcmp(name, cmp.name);
				if(tmp != 0)
					return tmp < 0;
				else
					return strcmp(id, cmp.id) < 0;
			case 3:
				if(score != cmp.score)
					return score < cmp.score;
				else
					return strcmp(id, cmp.id) < 0;
		}
	}
} buf[100001];

int main()
{
	freopen("input.txt", "r", stdin);
	
	int n;
	int count = 1;
	while(scanf("%d%d", &n, &c) != EOF)
	{
		if(n == 0)
			break;
		for(int i = 0; i < n; i++)
		{
			scanf("%s%s%d", &buf[i].id, &buf[i].name, &buf[i].score);
		}
		
		sort(buf, buf + n);
		
		printf("Case %d:\n", count++);
		
		for(int i = 0; i < n; i++)
		{
			printf("%s %s %d\n", buf[i].id, buf[i].name, buf[i].score);
		}
	}
	
	return 0;
}