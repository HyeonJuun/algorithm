#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100000 + 1;

int n, t, ans_x = 0, ans_y = 0;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

vector<pair<int, string>> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		int sec; string dir;
		cin >> sec >> dir;
		v.push_back({ sec, dir });
	}
	int dir = 0;
	if (n == 0) {

		cout << t << " " << ans_y;

		return 0;

	}

	for (int i = 0; i < v.size(); i++)
	{
		int a = v[i].first;
		string s = v[i].second;
		if (i != 0)
		{
			a = v[i].first - v[i - 1].first;
		}
		ans_x += dx[dir] * a;
		ans_y += dy[dir] * a;

		if (s == "right")
		{
			dir = (dir + 1) % 4;
		}
		else if (s == "left")
		{
			dir = dir - 1;
			if (dir == -1)
				dir = 3;
		}
		if (i == v.size() - 1 && v[i].first != t)
		{
			ans_x += dx[dir] * (t - v[i].first);
			ans_y += dy[dir] * (t - v[i].first);
		}
	}
	cout << ans_x << " " << ans_y << '\n';
	return 0;
}