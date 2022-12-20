#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 1000 + 1;

int n, number, strike, ball;
bool arr[MAX];
string tmp, one, two;
int strike_cnt, ball_cnt, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	memset(arr, true, sizeof(arr));
	for (int i = 123; i <= 999; i++)
	{
		tmp = to_string(i);
		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2])
			arr[i] = false;
		if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
			arr[i] = false;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> number >> strike >> ball;

		for (int i = 123; i <= 999; i++)
		{
			strike_cnt = 0;
			ball_cnt = 0;
			if (arr[i])
			{
				one = to_string(number);
				two = to_string(i);

				for (int x = 0; x < 3; x++)
				{
					for (int y = 0; y < 3; y++)
					{
						if (x == y && one[x] == two[y])
							strike_cnt++;
						if (x != y && one[x] == two[y])
							ball_cnt++;
					}
				}
				if (strike_cnt != strike || ball_cnt != ball)
					arr[i] = false;
			}
		}
	}
	for (int i = 123; i <= 999; i++)
	{
		if (arr[i])
			ans++;
	}
	cout << ans << '\n';
	return 0;
}