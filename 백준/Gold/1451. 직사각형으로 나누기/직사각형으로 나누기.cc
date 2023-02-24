#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int arr[MAX][MAX];
int n, m;
long long maxval=0; //모든 값이 9인 경우 long long 값이 필요함

long long sum(int sr, int sc, int er ,int ec) {
	long long ret = 0;
	for (int i = sr; i <= er; i++) {
		for (int j = sc; j <= ec; j++) {
			ret += arr[i][j]; 
		}
	}
	return ret;
}

void col_divide() { //col 을 나눔
	if (m < 3)	return;
	for (int i = 0; i < m - 2; i++) {
		for (int j = i+1; j < m - 1 - i; j++) {
			long long a = sum(0, 0, n-1, i);
			long long b = sum(0, i + 1, n-1, j);
			long long c = sum(0, j + 1, n-1, m - 1);
			if (maxval < a * b * c)
				maxval = a * b * c;
		}
	}
	return;
}

long long row_divide() { //row를 나눔
	if (n < 3)	return 0;	
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1 - i; j++) {
			long long a = sum(0, 0, i, m-1);
			long long b = sum(i+1, 0, j,m-1);
			long long c = sum(j+1, 0, n - 1, m - 1);
			if (maxval < a * b * c)
				maxval = a * b * c;
		}
	}
	return maxval;
}

void bigcol_divide() { //가로로 긴 직사각형이 하나 있음
	if (n < 2 || m < 2)	return;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			//ㅗ 모양
			long long a = sum(0, 0, i, j);
			long long b = sum(0, j+1, i, m - 1);
			long long c = sum(i+1, 0, n - 1, m - 1);
			if (maxval < a * b * c)
				maxval = a * b * c;

			a = 0; b = 0; c = 0;
			//ㅜ 모양
			a = sum(0, 0, i, m-1);
			b = sum(i+1, 0, n-1, j);
			c = sum(i + 1, j+1, n - 1,m - 1);
			if (maxval < a * b * c)
				maxval = a * b * c;
		}
	}
	return;
}

void bigrow_divide() {//세로로 긴 직사각형이 하나 있음
	if (n < 2 || m < 2)	return;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			//ㅓ 모양
			long long a = sum(0, 0, i, j);
			long long b = sum(i+1, 0, n-1, j);
			long long c = sum(0, j+1, n - 1, m - 1);
			if (maxval < a * b * c)
				maxval = a * b * c;

			a = 0; b = 0; c = 0;
			//ㅏ 모양
			a = sum(0, 0, n-1, j);
			b = sum(0, j+1, i, m-1);
			c = sum(i+1, j+1, n - 1, m - 1);
			if (maxval < a * b * c)
				maxval = a * b * c;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char tem[51];
		cin >> tem;
		for (int j = 0; j < m; j++) {
			arr[i][j] = tem[j] - '0';
		}
	}
	col_divide();
	row_divide();
	bigcol_divide();
	bigrow_divide();

	cout << (long long)maxval << "\n";
	return 0;
}