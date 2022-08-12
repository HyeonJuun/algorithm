#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <long long> arr;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        sort(arr.begin(), arr.end());
        long long sum = arr[0] + arr[1];
        arr[0] = sum;
        arr[1] = sum;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        ans += arr[i];
    }
    cout << ans << endl;
    return 0;
}
