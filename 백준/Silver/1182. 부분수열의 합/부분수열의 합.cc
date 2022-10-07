#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;
int n, s, cnt =0;

void func(int i, int sum)
{
	if(i == n)
		return;
	if(sum + v[i] == s)
		cnt++;
	
	func(i + 1, sum);
	func(i + 1, sum + v[i]);
	
}
int main()
{
	cin >> n >> s;
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x); 
	}

	func(0, 0);
	cout << cnt << endl;
	return 0;
}