#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int n, k;
string str = "";
map<string, int> visited;
int bfs(string s)
{
    string ans = s;
    sort(ans.begin(), ans.end());
    queue<pair<string, int>> q;
    q.push({ s, 0 });
    visited[s] = 1;

    while (!q.empty())
    {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == ans)
            return cnt;
        for (int i = 0; i <= n - k; i++)
        {
            string tmp = cur.substr(i, k);
            reverse(tmp.begin(), tmp.end());
            string nxt = cur.substr(0, i);
            nxt += tmp;
            nxt += cur.substr(i + k);
            if (!visited[nxt])
            {
                q.push({ nxt, cnt + 1 });
                visited[nxt] = 1;
            }
        }
    }
    return -1;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        str += c;
    }
    cout << bfs(str) << '\n';
    return 0;
}