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

#define MAX 100000 + 10
#define INF 987654321

int c, n, answer;
vector<pair<int, int>> v;
int dp[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c >> n;
    for (int i = 0; i <= c; i++)
        dp[i] = -1;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % v[j].first == 0)
            {
                dp[i] = max(dp[i], (i / v[j].first) * v[j].second);
            }
            if (i - v[j].first >= 0)
            {
                dp[i] = max(dp[i], dp[i - v[j].first] + v[j].second);
            }
        }
        if (c <= dp[i])
        {
            answer = i;
            break;
        }
    }
    cout << answer << endl;
    return 0;
}