#include <stdio.h>

#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0

int dayOfMonth[13][2] = 
{
	0, 0,
	31, 31, 
	28, 29,
	31, 31,
	30, 30,
	31, 31, 
	30, 30,
	31, 31,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31
};
struct Date
{
	int year, month, day;

	void nextDay()
	{
		day ++;

		if(day > dayOfMonth[month][ISYEAP(year)])
		{
			day = 1;
			month ++;
		}

		if(month > 12)
		{
			year ++;
			month = 1;
		}

	}
};


int buf[3001][13][32];

int main()
{
	freopen("input.txt", "r", stdin);

	int year, cnt;

	while(scanf("%d%d", &year, &cnt) != EOF)
	{
		Date tmp;
		tmp.year = year;
		tmp.day = 1;
		tmp.month = 1;
		int count = 1;
		while(count != cnt)
		{
			tmp.nextDay();
			count ++;
		}

		printf("%04d-%02d-%02d\n", tmp.year, tmp.month, tmp.day);
	}
	return 0;
}