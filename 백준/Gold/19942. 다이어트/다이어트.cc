#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 100000 + 10
#define INF 987654321

int n;
int mp, mf, ms, mv;
int arr[20][5];
bool visited[20];
vector<int> answer;
int ans = INF;
int mx[4];
int sum[5];

void solve(int cur)
{
    bool flag = true;
    if (cur > n)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (mx[i] > sum[i])
        {
            flag = false;
            break;
        }
    }
    if (flag && sum[4] < ans)
    {

        answer.clear();
        ans = sum[4];
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                answer.push_back(i + 1);
        }
        return;
    }

    visited[cur] = true;
    for (int j = 0; j < 5; j++)
    {
        sum[j] += arr[cur][j];
    }
    solve(cur + 1);
    visited[cur] = false;
    for (int j = 0; j < 5; j++)
    {
        sum[j] -= arr[cur][j];
    }
    solve(cur + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> mx[0] >> mx[1] >> mx[2] >> mx[3];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
    }
    solve(0);
    if (ans == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}