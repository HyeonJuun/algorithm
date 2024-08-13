#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 1000 + 10
#define INF 987654321

long long n, m;
vector<long long> v;
long long answer;

bool solve(long long num)
{
    long long cnt = 0;

    for (int i = 0; i < v.size(); i++)
    {
        cnt += num / v[i];
        if (cnt >= m)
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    long long mx = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        if (mx > v[i])
            mx = v[i];
    }

    sort(v.begin(), v.end());
    long long s = 1, e = v[v.size() - 1] * m, mid;

    while (s <= e)
    {
        mid = (s + e) / 2;

        if (solve(mid))
        {
            answer = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    cout << answer << endl;
    return 0;
}