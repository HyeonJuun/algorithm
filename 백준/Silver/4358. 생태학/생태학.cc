#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

const int MAX = 300 + 1;

string str;
map<string, int> tree;
float total = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while (getline(cin, str))
	{
		
		if (tree.find(str) != tree.end())
			tree[str] += 1;
		else
			tree[str] = 1;
		total++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = tree.begin(); it!=tree.end(); it++)
	{
		float percent = (it->second / total) * 100;
		cout << it->first << " ";
		cout << percent << '\n';
	}
	return 0;
}