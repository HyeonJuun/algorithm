#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

const int MAX = 300 + 1;

int n;
string str;
map<string, int> carIn;
int carOut[1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		carIn[str] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		int val = carIn[str];
		carOut[i] = val;
	}
	int ans = 0;
	for(int i=0; i<n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (carOut[i] > carOut[j])
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}