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
map<string, int> file;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		int loc = str.find('.');
		string s = str.substr(loc+1);
		file[s]++;
	}
	for (auto it = file.begin(); it != file.end(); it++)
	{
		cout << it->first << " " << it->second << '\n';
	}
	return 0;
}