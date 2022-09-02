#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 1000 + 1;

int n;
// 시간, 번호 순서
vector<pair<int, int>> v;
vector<int> ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(make_pair(x, i));
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += v[i].first;
		ans.push_back(sum);
	}
	sum = 0;
	for (int i = 0; i < ans.size(); i++)
		sum += ans[i];
	cout << sum << endl;
	return 0;
}