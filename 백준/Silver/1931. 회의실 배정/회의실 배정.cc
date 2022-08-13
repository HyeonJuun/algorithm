#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, begin, end;
    cin >> n;
    vector<pair <int, int> > s;
    for (int i = 0; i < n; i++)
    {
        cin >> begin >> end;
        s.push_back(make_pair(end, begin));
    }
    sort(s.begin(), s.end()); 
    int e_time = s[0].first;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (e_time <= s[i].second)
        {
            ans++;
            e_time = s[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}
