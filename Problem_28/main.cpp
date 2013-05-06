#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	stack<int> S;
	char signal[2];
	int n;
	while(scanf("%d", &n) != EOF && n != 0)
	{
		//printf("n:%d\n", n);
		while(!S.empty())
			S.pop();
		for(int i = 0; i < n; i++)
		{
			scanf("%s", &signal);
			
			if(strcmp(signal, "A") == 0)
			{
				if(S.empty())
				{
					printf("%c\n", 'E');
				}
				else
					printf("%d\n", S.top());
			}
			else if(strcmp(signal, "P") == 0)
			{
				int x;
				scanf("%d", &x);
				S.push(x);
			}
			else if(strcmp(signal, "O") == 0)
			{
				if(!S.empty())
					S.pop();
			}
		}

		printf("\n");
	}
	return 0;
}