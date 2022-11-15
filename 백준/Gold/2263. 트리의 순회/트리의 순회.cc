#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100000 + 1;

int n;

int inOrder[MAX];
int postOrder[MAX];
int idx[MAX];

void preOder(int inBegin, int inEnd, int postBegin, int postEnd)
{

	if (inBegin > inEnd || postBegin > postEnd)
		return;

	int root = postOrder[postEnd];
	cout << root << " ";

	preOder(inBegin, idx[root] - 1, postBegin, postBegin + (idx[root] - inBegin) - 1);
	preOder(idx[root] + 1, inEnd, postBegin + (idx[root] - inBegin), postEnd - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inOrder[i];
	for (int i = 0; i < n; i++)
		cin >> postOrder[i];

	for (int i = 0; i < n; i++)
		idx[inOrder[i]] = i;
	preOder(0, n - 1, 0, n - 1);
	cout << '\n';
	return 0;
}