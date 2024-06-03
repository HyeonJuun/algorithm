#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 50 + 1

using namespace std;

vector<int> v;
vector<int> sum;
int n, answer = -1, p_cnt, m_cnt;
bool visited[MAX];
void solve(int dep, int p, int m, int res)
{
    if (dep == n)
    {
        int total = 1;
        for (int i = 0; i < sum.size(); i++)
        {
            total *= sum[i];
            // cout << sum[i] << endl;
        }
        answer = max(answer, total);
        return;
    }
    if (p == 0 && m == 0 && res != 0)
    {
        sum.push_back(res);
        solve(dep + 1, 0, 0, res);
        sum.pop_back();
    }
    if (p > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                solve(dep + 1, p - 1, m, res + v[i]);
                visited[i] = false;
            }
        }
        // cout << "plus :" << p << " mul : " << m << " dep : " << dep << " " << res << " " << endl;
    }
    if (m > 0)
    {
        // cout << "plus :" << p << " mul : " << m << " dep : " << dep << " " << res << " " << endl;

        sum.push_back(res);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                solve(dep + 1, p, m - 1, v[i]);
                visited[i] = false;
            }
        }
        sum.pop_back();
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> p_cnt >> m_cnt;
    visited[0] = true;
    solve(0, p_cnt, m_cnt, v[0]);
    cout << answer << endl;
    return 0;
}