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

long long s, c, x, answer, sum;
vector<long long> v;
bool solve(long long num)
{
    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        res += v[i] / num;
    }
    return res >= c;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> c;

    for (int i = 0; i < s; i++)
    {
        cin >> x;
        v.push_back(x);
        sum += x;
    }

    long long le = 1, ri = 1000000000, answer;

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

    cout << sum - answer * c << endl;
    return 0;
}