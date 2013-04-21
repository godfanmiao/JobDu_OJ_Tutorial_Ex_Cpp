#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct Student
{
	char name[110];
	int age;
	int score;

	bool operator < (const Student &cmp) const
	{
		if(score != cmp.score)
			return score < cmp.score;
		else
		{
			int tmp = strcmp(name, cmp.name);
			if(tmp != 0)
				return tmp < 0;
			else
			{
				return age < cmp.age;
			}
		}
	}
} buf[1001];

int main()
{
	freopen("input.txt", "r", stdin);

	int n;

	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%s%d%d", &buf[i].name, &buf[i].age, &buf[i].score);
		}

		sort(buf, buf + n);

		for(int i = 0; i < n; i++)
		{
			printf("%s %d %d\n", buf[i].name, buf[i].age, buf[i].score);
		}
	}
}