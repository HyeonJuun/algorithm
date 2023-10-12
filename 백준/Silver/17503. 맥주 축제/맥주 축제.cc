#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, k;

int mx = 2e9;

int main() {
    
    cin >> n >> m >>  k;
    
    vector<pair<long, long>> bear(k);
    for (int i = 0; i < k; i++)
        cin >> bear[i].second >> bear[i].first;

    sort(bear.begin(), bear.end());
    priority_queue<long> pq;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        pq.push(-bear[i].second);
        sum += bear[i].second;

        if (pq.size() > n)
        {
            sum += pq.top();
            pq.pop();
        }

        if (pq.size() == n && sum >= m)
        {
            cout << bear[i].first << endl;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
