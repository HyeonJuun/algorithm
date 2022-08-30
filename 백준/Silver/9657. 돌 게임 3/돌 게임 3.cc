#include <iostream>
#include <algorithm>

using namespace std;

bool arr[1001];

int main() {
    int n;
    cin >> n;

    arr[1] = true;
    arr[2] = false;
    arr[3] = true;
    arr[4] = true;

    for (int i = 5; i <= n; ++i) {
        if (arr[i - 1] && arr[i - 3] && arr[i - 4]) arr[i] = false;
        else arr[i] = true;
    }

    if (arr[n]) cout << "SK";
    else cout << "CY";
}