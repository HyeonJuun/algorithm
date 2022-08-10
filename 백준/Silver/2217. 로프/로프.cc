#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(void)
{
    int n;
    int ans = 0;
    vector<int> x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x.push_back(a);
    }
    sort(x.begin(), x.end(), greater<>());

    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long sum = x[i] * (i + 1);
        if (sum > result)
            result = sum;
    }
    cout << result << endl;
    return 0;
}