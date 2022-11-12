#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>
using namespace std;

const int MAX = 68 + 1;

int t, n;

long long koong[MAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	koong[0] = koong[1] = 1;
	koong[2] = 2;
	koong[3] = 4;
	for (int i = 4; i <= 67; i++)
	{
		koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];
	}
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << koong[n] << "\n";
	}
	return 0;
}