#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct info {		//bfs때 사용
	int y, x, color, val, rainbow;
};
struct info2 {		//중력때 사용
	int row, val;
};
struct cmp {
	bool operator()(info &a, info &b) {
		if (a.val == b.val) {
			if (a.rainbow == b.rainbow) {
				if (a.y == b.y) {
					return a.x < b.x;
				}
				return a.y < b.y;
			}
			return a.rainbow < b.rainbow;
		}
		return a.val < b.val;
	}
};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int arr[20][20],dup[20][20];
bool check[20][20];
bool finish = false;
int num, m, result = 0;

void bfs() {
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			check[i][j] = false;
	priority_queue<info, vector<info>, cmp> pq;
	queue<info> q;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			int val = arr[i][j];
			if (val <= 0 || check[i][j] || val == m + 1) continue;
			check[i][j] = true;
			int cnt = 1;
			vector<info> rainbowBlock;
			q.push({ i,j,val,1,0 });
			while (!q.empty()) {
				int cy = q.front().y;
				int cx = q.front().x;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = cx + dx[k];
					int ny = cy + dy[k];
					if (nx >= 0 && ny >= 0 && nx < num && ny < num && !check[ny][nx]) {
						int nv = arr[ny][nx];
						if (nv == val || nv == m+1) {
							check[ny][nx] = true;
							q.push({ ny,nx,val,1,0 });		//y,x말고는 상관X
							cnt++;
							if (nv == m + 1) {		//무지개면 어디 블록에서든 접근 가능하도록 나중에 다시 check값 변경
								rainbowBlock.push_back({ ny,nx,0,0,0 });
							}
						}
					}
				}
			}
			int len = rainbowBlock.size();
			for (int k = 0; k < len; k++) {
				int cx = rainbowBlock[k].x;
				int cy = rainbowBlock[k].y;
				check[cy][cx] = false;
			}
			if (cnt > 1)
				pq.push({ i,j,val,cnt,len });
		}

	if (pq.empty()) {
		finish = true;
		return;
	}

	//가장 큰 블록 지운다
	int biggest = pq.top().val;
	result += (biggest*biggest);

	int eraseColor = pq.top().color;
	int ex = pq.top().x;
	int ey = pq.top().y;
	q.push({ ey,ex,0,0,0 });
	arr[ey][ex] = 0;
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < num && ny < num && (arr[ny][nx] == eraseColor || arr[ny][nx] == m + 1)) {
				q.push({ ny,nx,0,0,0 });
				arr[ny][nx] = 0;
			}
		}
	}
}

void initDup() {
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			dup[i][j] = 0;
}

void gravity() {
	initDup();
	for (int j = 0; j < num; j++) {
		//0 제외 모든 원소 수집
		vector<info2> v;
		for (int i = num - 1; i >= 0; i--) {
			if (arr[i][j] != 0) {
				v.push_back({ i,arr[i][j] });
			}
		}

		int idx = num - 1;
		for (int i = 0; i < v.size(); i++) {
			int val = v[i].val;
			int row = v[i].row;
			if (val == -1)
				idx = row;
			dup[idx][j] = val;
			idx--;
		}
	}
	memcpy(arr, dup, sizeof(arr));
}

void rotate() {
	initDup();
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			dup[num - j - 1][i] = arr[i][j];
	memcpy(arr, dup, sizeof(arr));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> num >> m;
	int val;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			cin >> val;
			arr[i][j] = val;
			//무지개돌 값 변경
			if (val == 0)
				arr[i][j] = m + 1;
		}
	while (1) {
		bfs();
		if (finish) break;
		//중력
		gravity();
		//90도 반시계 회전
		rotate();
		//중력
		gravity();
	}
	cout << result;
	return 0;
}