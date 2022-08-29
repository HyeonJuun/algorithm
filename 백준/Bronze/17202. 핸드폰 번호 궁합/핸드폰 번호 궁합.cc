#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 40 + 1;

int n, cnt1 = 0, cnt2 = 0;

string p1, p2;
vector<int> v;

void dp(vector<int> v)
{
	if (v.size() == 2)
	{
		cout << v[0] << v[1];
		return;
	}
	vector<int> new_v;
	for (int i = 1; i < v.size(); i++)
	{
		new_v.push_back((v[i - 1] + v[i]) % 10);
	}
	dp(new_v);
}
int main(void)
{
	cin >> p1 >> p2;
	for (int i = 0; i < 8; i++)
	{
		v.push_back(int(p1[i]) - 48);
		v.push_back(int(p2[i]) - 48);
	}
	dp(v);
	return 0;

}
