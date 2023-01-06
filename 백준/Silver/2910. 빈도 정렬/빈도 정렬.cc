#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

const int MAX = 1000 + 1;

int n;
long long c;

map<int, int> m;
map<int, int> idx;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return idx[a.first] < idx[b.first]; //기존의 순서 지키기

	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int x; 
		cin >> x;
		m[x]++;

		if (idx[x] == 0)
			idx[x] = i + 1;

	}
	vector<pair<int, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), cmp);
	for (auto x : v)
	{
		for (int j = 0; j < x.second; j++)
		{
			cout << x.first << " ";
		}
	}
	return 0;
}