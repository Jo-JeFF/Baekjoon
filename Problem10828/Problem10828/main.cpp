#include <iostream>
#include <cstring>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	unsigned int arrStack[10000] = { 0, };
	int nStackIndex = 0;
	char szCommand[12] = { 0, };
	int nCommandCount = 0;
	std::cin >> nCommandCount;

	std::cin.ignore();

	while (nCommandCount--)
	{
		std::cin.getline(szCommand, 12);

		if (NULL != strstr(szCommand, "push"))
		{
			unsigned int unNum = (unsigned int)strtoul(szCommand + strlen("push") + 1, NULL, 10);
			if (nStackIndex < 10000)
			{
				arrStack[nStackIndex++] = unNum;
			}
		}
		else if (NULL != strstr(szCommand, "pop"))
		{
			// 만약 스택 안에 정수가 1라도 있다면
			if (0 < nStackIndex && nStackIndex < 10000)
			{
				// 그 수를 출력하고, nStackIndex 감소
				std::cout << arrStack[--nStackIndex] << "\n";
			}
			else
			{
				std::cout << -1 << "\n";
			}
		}
		else if (NULL != strstr(szCommand, "size"))
		{
			std::cout << nStackIndex << "\n";
		}
		else if (NULL != strstr(szCommand, "empty"))
		{
			if (nStackIndex == 0)
			{
				std::cout << 1 << "\n";
			}
			else
			{
				std::cout << 0 << "\n";
			}
		}
		else if (NULL != strstr(szCommand, "top"))
		{
			if (0 < nStackIndex && nStackIndex < 10000)
			{
				std::cout << arrStack[(nStackIndex - 1)] << "\n";
			}
			else
			{
				std::cout << -1 << "\n";
			}
		}
	}


	return 0;
}