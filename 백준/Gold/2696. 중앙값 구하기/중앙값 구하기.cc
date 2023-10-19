#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int t, m;
int x;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while (t--)
    {
        cin >> m;
        if (m % 2 == 0)
            cout << m / 2 + 2 << endl;
        else
            cout << m / 2 + 1 << endl;

        priority_queue<int> frontHalf;
        priority_queue<int, vector<int>, greater<int>> backHalf;
        
        int arr[10000];
        vector<int> ans;

        for (int i = 1; i <= m; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= m; i++)
        {
            x = arr[i];

            if (frontHalf.size() == backHalf.size())
                frontHalf.push(x);
            else
                backHalf.push(x);

            if (!frontHalf.empty() && !backHalf.empty() && frontHalf.top() > backHalf.top())
            {
                int tmp1 = frontHalf.top();
                int tmp2 = backHalf.top();
                frontHalf.pop();
                backHalf.pop();

                frontHalf.push(tmp2);
                backHalf.push(tmp1);
            }

            if (i % 2 != 0)
                ans.push_back(frontHalf.top());

        }
        
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
            if ((i + 1) % 10 == 0)
                cout << '\n';
        }
    }
    
    return 0;
}
