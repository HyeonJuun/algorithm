#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using ll = long long;
int N, M,K;
vector<pair<int, ll>> adj[100005];
ll d[100005];
const ll MAX = 1e18;
//즉, 아래에서 언급되는 '면접장까지의 거리'란 
//그 도시에서 도달 가능한 가장 가까운 면접장까지의 최단 거리를 뜻한다.

priority_queue<pair<ll,ll>,vector<pair<ll, ll>>,greater<pair<ll, ll>>> pq;

void solve() {
   
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (d[cur.second] < cur.first) continue;
        for (auto nxt : adj[cur.second]) {
            if (d[nxt.second] > d[cur.second] + nxt.first) {
                d[nxt.second] = d[cur.second] + nxt.first;
                //dist = min(d[nxt.second], dist);
                pq.push({ d[nxt.second],nxt.second });
            }
        }
    }

}
int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int from, to;
        ll dist;
        cin >> from >> to >> dist;
        adj[to].push_back({ dist,from });
    }

    fill(d, d + N + 3, MAX);

    ll maxnum = -1;
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        d[num] = 0;
        pq.push({ d[num],num });
    }

    solve();
    int idx = -1;
    for (int i = 1; i <= N; i++) {
        if (maxnum < d[i]) {
            idx = i;
            maxnum = d[i];
        }
    }
    cout << idx << "\n" << maxnum;
    return 0;
}