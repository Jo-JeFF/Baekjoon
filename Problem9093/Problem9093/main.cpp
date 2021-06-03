#include <iostream>
#include <stack>
#include <cstring>

#define MAX_STRING 1000
#define MAX_WORD 20

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::wcin.tie(NULL);

	int nTestCaseCount = 0;

	std::cin >> nTestCaseCount;
	std::cin.ignore();

	char szString[MAX_STRING] = { 0, };
	while (nTestCaseCount--)
	{
		std::cin.getline(szString, MAX_STRING);

		int nLength = (int)strnlen(szString, MAX_STRING);

		std::stack<char> stackTemp;
		for (int i = 0; i <= nLength; ++i)
		{
			if (szString[i] == ' ' || szString[i] == '\0')
			{
				while (!stackTemp.empty())
				{
					printf("%c", stackTemp.top());
					stackTemp.pop();
				}
				printf(" ");
			}
			else
			{
				stackTemp.push(szString[i]);
			}
		}
		printf("\n");
	}
}