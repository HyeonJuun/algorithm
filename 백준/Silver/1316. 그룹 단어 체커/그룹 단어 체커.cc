#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        bool f = true;
        str.erase(unique(str.begin(), str.end()), str.end());
        sort(str.begin(), str.end());
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == str[j - 1])
            {
                f = false;
                break;
            }
        }
        if (f)
            cnt++;
    }
    cout << cnt;
    return 0;
}
