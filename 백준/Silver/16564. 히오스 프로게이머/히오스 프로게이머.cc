#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 500 + 10
#define INF 2e9
using namespace std;

long long n, k, answer;
vector<int> v;

bool solve(long long x)
{
    long long res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < x)
        {
            res += x - v[i];
        }
    }
    return res <= k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    long long le = 0, ri = 2000000000;

    while (le <= ri)
    {
        long long mid = (le + ri) / 2;
        if (solve(mid))
        {
            answer = mid;
            le = mid + 1;
        }
        else
            ri = mid - 1;
    }
    cout << answer << endl;
    return 0;
}