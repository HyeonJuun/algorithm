#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, l;
	vector<int> v;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++)
	{
		if (v[i] <= l)
			l++;
	}
	cout << l << endl;
	return 0;
}