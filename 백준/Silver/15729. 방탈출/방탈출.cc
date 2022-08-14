#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> l;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        l.push_back(a);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (l[i] == 0)
            continue;
        else if(l[i] == 1) 
        {
            cnt++;
            l[i] = 0;
            l[i + 1] = 1 - l[i + 1];
            l[i + 2] = 1 - l[i + 2];
        }
    }
    cout << cnt << endl;
    return 0;
}
