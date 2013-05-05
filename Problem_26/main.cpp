#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

char str1[110];
char str2[110];
stack<int> S;
int main()
{
	freopen("input.txt", "r", stdin);

	while(gets(str1))
	{
		while(!S.empty())
		{
			S.pop();
		}

		int i;
		for(i = 0; str1[i] != '\0'; i++)
		{
			if(str1[i] == '(')
			{
				S.push(i);
				str2[i] = ' ';
			}
			else if(str1[i] == ')')
			{
				if(S.empty())
					str2[i] = '?';
				else
				{
					str2[i] = ' ';
					S.pop();
				}
			}
			else
			{
				str2[i] = ' ';
			}
		}

		while(!S.empty())
		{
			str2[S.top()] = '$';
			S.pop();
		}

		str2[i] = '\0';

		puts(str1);
		puts(str2);
	}

	return 0;
}