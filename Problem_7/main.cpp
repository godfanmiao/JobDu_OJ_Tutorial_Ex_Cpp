#include <stdio.h>
#include <string.h>

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

char monthName[13][30] = 
{
	"",
	"January", 
	"February", 
	"March", 
	"April", 
	"May", 
	"June", 
	"July", 
	"August", 
	"September", 
	"October", 
	"November", 
	"December"
};

char weekName[7][30] = 
{
	"Sunday", 
	"Monday", 
	"Tuesday", 
	"Wednesday", 
	"Thursday", 
	"Friday", 
	"Saturday"
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

	int day, year;
	char monthStr[30];

	while(scanf("%d%s%d", &day, &monthStr, &year) != EOF)
	{
		int month = 1;

		while(strcmp(monthName[month], monthStr) != 0)
		{
			month ++;
		}

		printf("%s\n", weekName[((buf[year][month][day] - buf[2013][5][5]) % 7 + 7) % 7]);

	}
	return 0;
}