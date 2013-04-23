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
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
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
			month = 1;
			year ++;
		}

	}
};

int buf[3001][13][32];

int main()
{
	freopen("input.txt", "r", stdin);

	Date tmp;
	tmp.year = 0; 
	tmp.month = 1;
	tmp.day = 1;
	int cnt = 0;

	while(tmp.year != 3001)
	{
		buf[tmp.year][tmp.month][tmp.day] = cnt;
		tmp.nextDay();
		cnt ++;
	}

	int year, day, month;
	char monthStr[30];
	while(scanf("%d%s%d", &day, &monthStr, &year) != EOF)
	{
		for(int i = 1; i <= 12; i++)
		{
			if(strcmp(monthName[i], monthStr) == 0)
			{
				month = i;
				break;
			}
		}

		int ans = ((buf[year][month][day] - buf[2013][4][22] + 1) % 7 + 7) % 7;

		printf("%s\n", weekName[ans]);
	}

	return 0;
}