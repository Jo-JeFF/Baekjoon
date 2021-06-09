#include <iostream>
#include <cstring>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::wcin.tie(NULL);

	// - Stack�� ������� �ʴ� ���
	// '(' �� +1, ')' �� -1�� ���
	// �������� 0�� �ƴϸ� FALSE
	// �������� 0�̸� TRUE

	int nTestCase = 0;
	int nResult = 0;
	bool bEnd = false;
	char szTemp[51] = { 0, };

	std::cin >> nTestCase;
	std::cin.ignore();
	while (nTestCase--)
	{
		std::cin.getline(szTemp, 51);

		if (strlen(szTemp) < 2)
		{
			std::cout << "NO\n";
			bEnd = true;
		}

		for (int i = 0; i < (int)strlen(szTemp); ++i)
		{
			switch (szTemp[i])
			{
			case '(':
				nResult++;
				break;

			case ')':
				nResult--;
				break;
			}
			if (nResult < 0)
			{
				std::cout << "NO\n";
				bEnd = true;
				break;
			}
		}

		if (!bEnd)
		{
			if (nResult == 0) std::cout << "YES\n";
			else std::cout << "NO\n";
		}
		nResult = 0;
		bEnd = false;
	}
}