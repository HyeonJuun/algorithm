#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int n, m;
int arr[100010];
long long prefix[100010];
long long mx = -1, sum = 0;

int main() {
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }
    for (int i = m; i < n +1; i++)
    {
        sum = prefix[i] - prefix[i-m];
        if (sum > mx)
            mx = sum;
    }
    cout << mx;
    return 0;
}