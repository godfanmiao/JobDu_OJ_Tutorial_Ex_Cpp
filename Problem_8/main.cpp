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
	int day, month, year;

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

int buf[5001][13][32];

int abs(int x)
{
	return x < 0 ? - x : x;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int cnt = 0;
	Date tmp;
	tmp.day = 1;
	tmp.month = 1;
	tmp.year = 0;

	while(tmp.year != 5001)
	{
		buf[tmp.year][tmp.month][tmp.day] = cnt ++;
		tmp.nextDay();
	}

	int year, month, day;

	while(scanf("%d%d%d", &year, &month, &day) != EOF)
	{
		printf("%d\n", buf[year][month][day] - buf[year][1][1] + 1);
	}

	return 0;
}