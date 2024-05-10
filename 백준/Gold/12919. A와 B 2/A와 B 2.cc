#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <stack>

using namespace std;
string s, t;
bool answer;

void solve()
{
    queue<string> q;
    q.push(t);

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();

        if (cur == s)
        {
            answer = true;
            return;
        }
        if (cur[cur.length() - 1] == 'A')
        {
            string nxt = cur.substr(0, cur.length() - 1);
            q.push(nxt);
        }
        if (cur[0] == 'B')
        {
            string nxt = cur.substr(1, cur.length());
            reverse(nxt.begin(), nxt.end());
            q.push(nxt);
        }
    }
}
int main()
{
    cin >> s >> t;
    solve();
    if (answer)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
