#include<iostream>
#include<string>

using namespace std;

int main()
{
	string n;
	while (1)
	{
		cin >> n;
		int cnt = 1;
		if (n == "0")
		{
			break;
		}
		
		for (int i = 0; i < n.length(); i++)
		{
			if (n[i] - '0' == 1)
			{
				cnt += 2;
			}
			else if (n[i] - '0' == 0)
			{
				cnt += 4;
			}
			else
			{
				cnt += 3;
			}
			cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}