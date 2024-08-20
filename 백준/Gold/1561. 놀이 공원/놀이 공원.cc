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

#define MAX 10 + 1
#define INF 987654321

long long n, m;
long long answer;
vector<long long> v;

bool solve(long long num)
{
    long long res = m;
    for (int i = 0; i < v.size(); i++)
    {
        res += num / v[i];
    }
    return res >= n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    if (n <= m)
    {
        cout << n << endl;
        return 0;
    }

    long long le = 1, ri = 60000000000;
    long long time = 0;
    while (le <= ri)
    {
        long long mid = (le + ri) / 2;

        if (solve(mid))
        {
            time = mid;
            ri = mid - 1;
        }
        else
            le = mid + 1;
    }
    long long ch = m;

    for (int i = 0; i < m; i++)
    {
        ch += (time - 1) / v[i];
    }
    for (int i = 0; i < m; i++)
    {
        if (time % v[i] == 0)
            ch++;
        if (ch == n)
        {
            answer = i + 1;
            break;
        }
    }
    cout << answer << endl;
    return 0;
}