#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 10 + 1;

int n;
pair<char, char> tree[26];

void preorder(char x)
{
	if (x != '.')
	{
		cout << x;
		preorder(tree[(x - 'A')].first);
		preorder(tree[(x - 'A')].second);
	}
}
void inorder(char x)
{
	if (x != '.')
	{
		inorder(tree[(x - 'A')].first);
		cout << x;
		inorder(tree[(x - 'A')].second);
	}
}
void postorder(char x)
{
	if (x != '.')
	{

		postorder(tree[(x - 'A')].first);
		postorder(tree[(x - 'A')].second);
		cout << x;

	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;

		tree[(parent - 'A')].first = left;
		tree[(parent - 'A')].second = right;
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';
	return 0;
}