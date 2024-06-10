#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 100000

using namespace std;

int n, t, k;
bool visited[MAX];

void solve()
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = true;

    while (!q.empty())
    {

        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // cout << "c : " << c << "  dist : " << dist << endl;

        if (cur == k)
        {
            cout << cnt << endl;
            return;
        }
        if (cnt == t)
            continue;

        int nxt = cur + 1;
        if (nxt < MAX && !visited[nxt])
        {
            visited[nxt] = true;
            q.push({nxt, cnt + 1});
        }

        if (cur != 0)
        {
            int x = cur * 2;
            if (x >= MAX)
                continue;
            string str = to_string(x);
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] != 0)
                {
                    int tmp = str[i] - '0';
                    tmp--;
                    str[i] = tmp + '0';
                    break;
                }
            }
            int nxt = stoi(str);

            if (!visited[nxt] && nxt < MAX)
            {
                visited[nxt] = true;
                q.push({nxt, cnt + 1});
            }
        }
    }
    cout << "ANG" << endl;
}
int main()
{
    cin >> n >> t >> k;
    solve();

    return 0;
}