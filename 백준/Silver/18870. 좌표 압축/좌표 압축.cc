#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX = 8 + 1;

int arr[MAX];
int sel_arr[MAX];
int visited[MAX];

int n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> v, back;
	int cnt;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
		back.push_back(x);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(v.begin(), v.end(), back[i])- v.begin() << " ";
	}
	return 0;
}