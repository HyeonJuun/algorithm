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

int n, k;
vector<long long> v;
long long answer;

bool solve(long long num)
{
    if (num == 0)
        return true;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += v[i] / num;
    }
    return count >= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    long long le = 0, ri = v[v.size() - 1];

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