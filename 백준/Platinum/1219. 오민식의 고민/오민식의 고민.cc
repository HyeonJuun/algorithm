#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;
#define MAX 50
#define INF 2500000000
// 문제
// 오민식은 세일즈맨이다. 오민식의 회사 사장님은 오민식에게 물건을 최대한 많이 팔아서 최대 이윤을 남기라고 했다.
// 오민식은 고민에 빠졌다.
// 어떻게 하면 최대 이윤을 낼 수 있을까?
// 이 나라에는 N개의 도시가 있다. 도시는 0번부터 N-1번까지 번호 매겨져 있다. 오민식의 여행은 A도시에서 시작해서 B도시에서 끝난다.
// 오민식이 이용할 수 있는 교통수단은 여러 가지가 있다. 오민식은 모든 교통수단의 출발 도시와 도착 도시를 알고 있고, 비용도 알고 있다.
// 게다가, 오민식은 각각의 도시를 방문할 때마다 벌 수 있는 돈을 알고있다. 이 값은 도시마다 다르며, 액수는 고정되어있다. 또, 도시를 방문할 때마다 그 돈을 벌게 된다.
// 오민식은 도착 도시에 도착할 때, 가지고 있는 돈의 액수를 최대로 하려고 한다. 이 최댓값을 구하는 프로그램을 작성하시오.
// 오민식이 버는 돈보다 쓰는 돈이 많다면, 도착 도시에 도착할 때 가지고 있는 돈의 액수가 음수가 될 수도 있다.
// 또, 같은 도시를 여러 번 방문할 수 있으며, 그 도시를 방문할 때마다 돈을 벌게 된다. 모든 교통 수단은 입력으로 주어진 방향으로만 이용할 수 있으며, 여러 번 이용할 수도 있다.
// ------------------------------------------------------------------------
// 입력
// 첫째 줄에 도시의 수 N과 시작 도시, 도착 도시 그리고 교통 수단의 개수 M이 주어진다.
// 둘째 줄부터 M개의 줄에는 교통 수단의 정보가 주어진다. 교통 수단의 정보는 “시작 끝 가격”과 같은 형식이다.
// 마지막 줄에는 오민식이 각 도시에서 벌 수 있는 돈의 최댓값이 0번 도시부터 차례대로 주어진다.
// N과 M은 50보다 작거나 같고, 돈의 최댓값과 교통 수단의 가격은 1,000,000보다 작거나 같은 음이 아닌 정수이다.
// ------------------------------------------------------------------------
// 출력
// 첫째 줄에 도착 도시에 도착할 때, 가지고 있는 돈의 액수의 최댓값을 출력한다.
// 만약 오민식이 도착 도시에 도착하는 것이 불가능할 때는 "gg"를 출력한다. 그리고, 오민식이 도착 도시에 도착했을 때 돈을 무한히 많이 가지고 있을 수 있다면 "Gee"를 출력한다.
// ------------------------------------------------------------------------
// 문제 풀이
// 1. 벨만 포드 진행하셈..
// 2. 한번 돌았을 때 돈이 음수면 그냥 출력
// 3. 한번 돌았을 때 돈이 INF라면 gg 출력
// 4. 한번 돌았을 떄 돈이 양수면 한번 더 돌려보고 돈이 증가한다면 무한대로 돌 수 있는 거니깐 Gee 출력하고 돈이 줄거나?(가능할지는 모름) 돈이 똑같으면 그냥 그 돈 출력

int n, m, st, en;
int a, b, c, x;
int earn[MAX];
bool visited[MAX];
vector<pair<int, int>> map[MAX];
vector<long long> dist(MAX, INF);
queue<int> que;
bool bfs()
{
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        for (auto c : map[cur])
        {
            int nxt = c.first;
            if (visited[nxt])
                continue;
            visited[nxt] = true;
            que.push(nxt);
        }
    }
    if (visited[en])
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> st >> en >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        map[a].push_back({b, c});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> earn[i];
    }
    dist[st] = -earn[st];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (auto cur : map[j])
            {
                int nxt = cur.first;
                long long nxcost = cur.second;
                if (dist[j] != INF && dist[nxt] > dist[j] + nxcost - earn[nxt])
                {
                    dist[nxt] = dist[j] + nxcost - earn[nxt];
                    if (i == n)
                    {
                        // v-1번 돌리고 v번째라면 위의 if문을 들어왔다는 것이 노드가 업데이트 됨을 의미. 그러므로 cycleNode
                        visited[j] = true;
                        que.push(j);
                    }
                }
            }
        }
    }
    if (dist[en] == INF)
    {
        cout << "gg" << endl;
    }
    else
    {
        if (bfs())
        {
            cout << "Gee" << endl;
        }
        else
        {
            cout << -dist[en] << endl;
        }
    }
}
