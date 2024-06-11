#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <climits>
#include <cstring>
#include<sstream>

using namespace std;

int arr[30];
int mat[300][300];
int r, c;
string temp;
bool ok(int ty, int tx) {
	if (mat[ty][tx] != -1 || ty < 0 || ty >= r || tx < 0 || tx >= c) return false;
	return true;
}
int cp[5000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void dfs() {
	int L = 0,len=temp.length();

	int x = -1, y = 0, sub = 1;
	int flag = 0;
	while (L<len) {

		int C;
		if (temp[L] == ' ') {
			C = arr[0];
		}
		else {
			C = arr[temp[L] - 'A' + 1];
		}

		for (int j = 4 + L * 5; j >= 0 + L * 5; j--) {
			cp[j] = C % 2;
			C = C / 2;
		}
		L++;
	}
	int cnt = 0;
	while (cnt<len*5) {
		for (int i = 0; i < c; i++) {
			x += sub;
			mat[y][x] = cp[cnt];
			cnt++;
			if (cnt >= len * 5) break;
		}
		r--;
		if (r <= 0)break;
		for (int i = 0; i < r; i++) {
			y += sub;
			mat[y][x] = cp[cnt];
			cnt++;
			if (cnt >= len * 5) break;
		}
		c--;
		if (c <= 0) break;
		sub = -sub;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;
	int n; cin >> n;
	cin.ignore(32767, '\n');
	for (i = 1; i <= 26; i++) {
		arr[i] = i;
	}

	for (i = 0; i < n; i++) {
		getline(cin, temp);
		size_t sz;
		int r1 = r = stoi(temp, &sz);
		temp = temp.substr(sz + 1);
		int c1 = c = stoi(temp, &sz);
		temp = temp.substr(sz + 1);
		for (j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) mat[j][k] = -1;
		}

		dfs();
		for (j = 0; j < r1; j++) {
			for (int k = 0; k < c1; k++) {
				if (mat[j][k] == -1) cout << 0;
				else cout << mat[j][k];
			}
		}
		cout << "\n";
	}

	return 0;
}