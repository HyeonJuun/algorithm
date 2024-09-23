#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define MAX 10000 + 10
#define INF 987654321

int n, m, answer;
int egg[10][2];

void solve(int idx)
{
    if (idx == n)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (egg[i][0] <= 0)
                cnt++;
        }
        answer = max(answer, cnt);
        return;
    }

    if (egg[idx][0] <= 0)
    {
        solve(idx + 1);
    }
    else
    {
        bool ck = false;
        for (int i = 0; i < n; i++)
        {
            if (idx == i || egg[i][0] <= 0)
                continue;

            egg[i][0] -= egg[idx][1];
            egg[idx][0] -= egg[i][1];

            ck = true;
            solve(idx + 1);
            egg[i][0] += egg[idx][1];
            egg[idx][0] += egg[i][1];
        }

        if (!ck)
            solve(n);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> egg[i][0] >> egg[i][1];
    }
    solve(0);
    cout << answer << endl;
    return 0;
}