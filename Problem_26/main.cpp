#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	char str1[110];
	char str2[110];
	stack<int> S;

	while(scanf("%s", str1) != EOF)
	{
		while(!S.empty())
			S.pop();
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
					S.pop();
					str2[i] = ' ';
				}
			}
			else
			{
				str2[i] = ' ';
			}
		}

		str2[i] = '\0';

		while(!S.empty())
		{
			str2[S.top()] = '$';
			S.pop();
		}

		puts(str1);
		puts(str2);
	}
	return 0;
}