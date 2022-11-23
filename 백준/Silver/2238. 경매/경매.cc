#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 100000 + 1;

int u, n;
vector<pair<int, string>> v;
int price[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> u >> n;
	for (int i = 0; i < n; i++)
	{
		int p;
		string name;
		cin >> name >> p;
		v.push_back({ p, name });
		price[p]++;
	}
	int minNum = MAX;
	for (int i = 1; i < MAX; i++)
		if (price[i])
			minNum = min(minNum, price[i]);

	vector<int> minCnt;
	for (int i = 1; i < MAX; i++)
		if (price[i] == minNum)
			minCnt.push_back(i);
	sort(minCnt.begin(), minCnt.end());

	for (int i = 0; i < n; i++)
	{
		if (v[i].first == minCnt[0])
		{
			cout << v[i].second << " " << v[i].first << '\n';
			break;
		}
	}

	return 0;
}