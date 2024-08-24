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

#define MAX 500 + 1
#define INF 987654321

long long k, n, x, answer;
vector<long long> v;

bool solve(long long num)
{
    long long res = 0, sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (sum >= num)
        {
            res++;
            sum = 0;
        }
    }
    return res >= n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    long long le = 0, ri = k * (*max_element(v.begin(), v.end()));

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