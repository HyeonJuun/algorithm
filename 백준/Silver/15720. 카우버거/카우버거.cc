#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    
    int buger, side, coke;
    cin >> buger >> side >> coke;
    vector<int> b;
    vector<int> s;
    vector<int> c;
    int sum = 0;

    for (int i = 0; i < buger; i++)
    {
        int a;
        cin >> a;
        b.push_back(a);
        sum += a;
    }
    for (int i = 0; i < side; i++)
    {
        int a;
        cin >> a;
        s.push_back(a);
        sum += a;
    }
    for (int i = 0; i < coke; i++)
    {
        int a;
        cin >> a;
        c.push_back(a);
        sum += a;
    }
    cout << sum << endl;
    sort(b.begin(), b.end(), greater<>());
    sort(s.begin(), s.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());
    int ans = 0;
    int num = min(b.size(), min(s.size(), c.size()));
    for (int i = 0; i < num; i++)
    {
        ans += 0.9 * b[i];
        ans += 0.9 * s[i];
        ans += 0.9 * c[i];
    }
    for (int i = num; i < b.size(); i++)
    {
        ans += b[i];
    }
    for (int i = num; i < s.size(); i++)
    {
        ans += s[i];
    }    
    for (int i = num; i < c.size(); i++)
    {
        ans += c[i];
    }
    cout <<  ans << endl;
    return 0;
}
