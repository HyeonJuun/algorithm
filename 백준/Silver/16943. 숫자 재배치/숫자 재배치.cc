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

#define MAX 10000
#define INF 987654321

string a, b;

bool visited[10];
int answer = -1;
void solve(string str)
{
    if (str.length() == a.length())
    {
        if (str[0] == '0')
            return;

        int cur = stoi(str);
        if (cur > answer)
        {
            if (cur < stoi(b))
                answer = cur;
        }
    }
    for (int i = 0; i < a.length(); i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        solve(str + a[i]);
        visited[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        visited[i] = true;
        string str = "";
        solve(str + a[i]);
        visited[i] = false;
    }
    cout << answer << endl;
    return 0;
}