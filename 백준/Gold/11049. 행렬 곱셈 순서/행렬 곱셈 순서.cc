#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 500 + 10

int n;
int mat[MAX][2];
int dp[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> mat[i][0] >> mat[i][1];
    }

    // i : 곱셈 연산에 참여한 행렬 수
    // j : 곱셈 시작 행렬
    // k : 시작점 j  부터 i+j 위치까지의 행렬 곱의 최소 연산 ㄱ밧
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; i + j <= n; j++)
        {
            dp[j][j + i] = 2e9;
            for (int k = j; k <= i + j; k++)
            {
                dp[j][j + i] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + mat[j][0] * mat[k][1] * mat[i + j][1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}