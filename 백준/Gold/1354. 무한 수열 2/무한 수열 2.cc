#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;

long long n, p, q, x, y;

unordered_map<long long, long long> mp;

long long solve(long long num)
{
    if (num <= 0)
        return 1;
    if (mp[num])
        return mp[num];
    return mp[num] = solve(num / p - x) + solve(num / q - y);
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> p >> q >> x >> y;
    cout << solve(n);
    return 0;
}