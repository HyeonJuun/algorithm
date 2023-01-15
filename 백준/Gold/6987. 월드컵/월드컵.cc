#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 10 + 1;

int result[MAX][MAX];
int makeResult[MAX][MAX];
vector<pair<int, int>> vs;
int ans[4];

void solve(int c, int cnt)
{
	if (cnt == 15)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (result[i][j] != makeResult[i][j])
					return;
			}
		}
		ans[c] = 1;
		return;
	}
	int home = vs[cnt].first;
	int away = vs[cnt].second;

	makeResult[home][0]++;
	makeResult[away][2]++;
	solve(c, cnt + 1);
	makeResult[home][0]--;
	makeResult[away][2]--;

	makeResult[away][0]++;
	makeResult[home][2]++;
	solve(c, cnt + 1);
	makeResult[away][0]--;
	makeResult[home][2]--;

	makeResult[home][1]++;
	makeResult[away][1]++;
	solve(c, cnt + 1);
	makeResult[home][1]--;
	makeResult[away][1]--;

}

int main()
{
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
			vs.push_back({ i, j });
	}
	for (int t = 0; t < 4; t++)
	{
		memset(makeResult, 0, sizeof(makeResult));
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> result[i][j];
			}
		}
		solve(t, 0);
		cout << ans[t] << ' ';
	}
	return 0;
}