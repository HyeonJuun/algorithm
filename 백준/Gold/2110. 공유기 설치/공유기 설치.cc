#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF = 2e8;
int n, c;
int answer;
vector<int> arr;

int main() {
    
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int left = 0, right = arr[n - 1];

    while (left <= right)
    {
        int start = arr[0];
        int cnt = 1;
        int mid = (left + right) / 2;

        for (int i = 1; i < n; i++)
        {
            int end = arr[i];
            if (end - start >= mid)
            {
                cnt++;
                start = end;
            }
        }
        if (cnt >= c)
        {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << answer;
    return 0;
}
