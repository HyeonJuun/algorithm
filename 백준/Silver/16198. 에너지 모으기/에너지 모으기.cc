#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 1000000 + 1;

int n;
int ans = 0;
vector<int> v;

void solve(int sum)
{
	if (v.size() == 2)
	{
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i < v.size() - 1; i++)
	{
		int add = v[i - 1] * v[i + 1];
		int tmp = v[i];

		v.erase(v.begin() + i);
		solve(sum + add);
		v.insert(v.begin() + i, tmp);
	}
}



int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int w;
	for (int i = 0; i < n; i++)
	{
		cin >> w;
		v.push_back(w);
	}
	solve(0);
	cout << ans;
	return 0;
}