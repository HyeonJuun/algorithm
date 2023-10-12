#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>

using namespace std;

int answer, n, k;

vector<priority_queue<int>> pqVec;

int main() {
    
    cin >> n >> k;
    pqVec.resize(12);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pqVec[a].push(b);
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j <= 11; j++)
        {
            if (pqVec[j].empty() || pqVec[j].top() == 0)
                continue;

            int x = pqVec[j].top();
            pqVec[j].pop();
            pqVec[j].push(x - 1);
        }
    }

    for (int j = 1; j <= 11; j++)
    {
        if (pqVec[j].empty())
            continue;
        answer += pqVec[j].top();
    }
    
    cout << answer << endl;
    return 0;
}
