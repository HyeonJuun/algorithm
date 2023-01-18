#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 100000 + 1;

int n, m;
int arr[MAX];
int prefix[MAX];

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		prefix[i] = prefix[i - 1] + arr[i];
	}
	cin >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << prefix[b] - prefix[a - 1] << '\n';
	}
	return 0;
}