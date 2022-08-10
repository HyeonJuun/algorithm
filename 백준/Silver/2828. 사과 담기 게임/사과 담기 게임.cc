#include <iostream>

using namespace std;



int main(void)
{
	int N, M;
	cin >> N >> M;
	int J;
	cin >> J;
	int idx = 1;
	int result = 0;
	for (int i = 0; i < J;i++)
	{
		int num;
		cin>> num;
		while (1)
		{
			bool flag = false;
			for (int j = idx;
				j <= idx + (M - 1); j++)
				if (j == num)
				{
					flag= true;
					break;
				}
			if (flag)
				break;
			if (idx > num)
				idx--;
			else
				idx++;

			result++;

		}

	}

	cout << result << "\n";

	return 0;

}
