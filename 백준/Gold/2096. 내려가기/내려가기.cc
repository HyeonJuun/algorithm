#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 100000 + 1;

int n;

int dp_max[2][3] = { 0 };
int dp_min[2][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x, y, z;
	int ans_max, ans_min;

	// 문제는 메모리가 작으니 배열을 n행 3열을 두는 것이 아니라
	// 어차피 아래로 내려가면서 더할 것이니 2개를 두고 그 두개를 반복해서 사용할 수 도 있다는 것에서 시작
	// 따라서 k는 0과 1을 반복하면서 배열을 채워나갈 것임
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		dp_max[k][0] = max(dp_max[1 - k][0], dp_max[1 - k][1]) + x;
		dp_max[k][1] = max(dp_max[1 - k][0], max(dp_max[1 - k][1], dp_max[1 - k][2])) + y;
		dp_max[k][2] = max(dp_max[1 - k][1], dp_max[1 - k][2]) + z;

		dp_min[k][0] = min(dp_min[1 - k][0], dp_min[1 - k][1]) + x;
		dp_min[k][1] = min(dp_min[1 - k][0], min(dp_min[1 - k][1], dp_min[1 - k][2])) + y;
		dp_min[k][2] = min(dp_min[1 - k][1], dp_min[1 - k][2]) + z;

		k = 1 - k;
	}

	ans_max = max(dp_max[1 - k][0], max(dp_max[1 - k][1], dp_max[1 - k][2]));
	ans_min = min(dp_min[1 - k][0], min(dp_min[1 - k][1], dp_min[1 - k][2]));

	cout << ans_max << " " << ans_min ;
	return 0;
}