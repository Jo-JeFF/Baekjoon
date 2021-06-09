#include <iostream>
#include <queue>

int main()
{
	std::queue<int> queueTemp;

	int nK = 0;
	int nN = 0;
	int nIndex = 0;

	std::cin >> nN >> nK;

	for (int i = 0; i < nN; ++i)
	{
		queueTemp.push(i + 1);
	}

	std::cout << "<";
	while (!queueTemp.empty())
	{
		++nIndex;

		if ( nIndex % nK == 0 )
		{
			std::cout << queueTemp.front();
			queueTemp.pop();

			if (0 != queueTemp.size())
			{
				std::cout << ", ";
			}
		}
		else
		{
			queueTemp.push(queueTemp.front());
			queueTemp.pop();
		}

	}
	std::cout << ">";

	

	return 0;
}