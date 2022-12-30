#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

const int MAX = 20 + 1;

int n, m;


vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

void check_pic()
{
	int min_cnt = 987654321;
	for (int i = 0; i < v.size(); i++)
	{
		min_cnt = min(min_cnt, v[i].second);
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (min_cnt == v[i].second)
		{
			v.erase(v.begin() + i);
			break;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x; cin >> x;
		bool isnew = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (x == v[i].first)
			{
				isnew = true;
				v[i].second++;
				break;
			}
		}
		if (isnew == false)
		{
			if (v.size() < n)
			{
				v.push_back({ x, 1 });
			}
			else if (v.size() == n)
			{
				check_pic();
				v.push_back({ x, 1 });
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " ";
	}
	return 0;
}