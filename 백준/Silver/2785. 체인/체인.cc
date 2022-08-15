#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    while (true)
    {
        if (v.size() == 1)
            break;

        v[v.size() - 2] += v[v.size() - 1];
        v.pop_back();
        cnt++;
        v[0]--;
        if (v[0] == 0)
        {
            for (int i = 0; i < v.size() - 1; i++)
            {
                v[i] = v[i + 1];
            }
            v.pop_back();
        }
    }
    cout << cnt << endl;
    return 0;
}
