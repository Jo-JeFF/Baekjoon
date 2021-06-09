#include <iostream>
#include <cstring>
#include <deque>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nTCCount = 0;
	char szCommand[12] = { 0, };
	std::deque<int> dequeTemp;

	std::cin >> nTCCount;

	std::cin.ignore();
	while (nTCCount--)
	{
		std::cin.getline(szCommand, sizeof(szCommand));

		if (NULL != strstr(szCommand, "push"))
		{
			unsigned long ulNum = strtoul(szCommand + strlen("push") + 1, NULL, 10);
			dequeTemp.push_back((int)ulNum);
		}
		else if (NULL != strstr(szCommand, "pop"))
		{
			if (!dequeTemp.empty())
			{
				std::cout << dequeTemp.front() << "\n";
				dequeTemp.pop_front();
			}
			else
			{
				std::cout << -1 << "\n";
			}
		}
		else if (NULL != strstr(szCommand, "size"))
		{
			std::cout << dequeTemp.size() << "\n";
		}
		else if (NULL != strstr(szCommand, "empty"))
		{
			if (dequeTemp.empty())
			{
				std::cout << 1 << "\n";
			}
			else
			{
				std::cout << 0 << "\n";
			}
		}
		else if (NULL != strstr(szCommand, "front"))
		{
			if (dequeTemp.empty())
			{
				std::cout << -1 << "\n";
			}
			else
			{
				std::cout << dequeTemp.front() << "\n";
			}
		}
		else if (NULL != strstr(szCommand, "back"))
		{
			if (dequeTemp.empty())
			{
				std::cout << -1 << "\n";
			}
			else
			{
				std::cout << dequeTemp.back() << "\n";
			}
		}
	}
}