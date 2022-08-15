#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n, m ,k;
    int person;
    double ability;
    cin >> n >> m >> k;
    vector<double>arr(n, 0.0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> person >> ability;
            arr[person - 1] = max(ability, arr[person - 1]);
        }
    }
    sort(arr.begin(), arr.end(), greater<double>());
    double ans = 0.0;
    for (int i = 0; i < k; i++)
    {
        ans += arr[i];
    }
    cout << fixed;
    cout.precision(1);
    cout << ans << endl;

    return 0;
}
