#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// map
int n, m;
int map[55][55];
int visited[55][55];

// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


// combination
bool combi[11];

// bfs 
queue<pair<int, int>> q;
vector<pair<int, int>> buff;
// virus 
vector<pair<int, int>> virusXY;
// 감염 가능구역 
vector<pair<int, int>> possibleXY;
// ans 
int ans = 987654321;



void virus()
{
    fill(&visited[0][0], &visited[n][n], -1);
    for(auto &el : buff)
    {
        visited[el.first][el.second] = 0;
        q.push({el.first, el.second});
    }
    
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] != -1 || map[ny][nx] == 1)
                continue;
            if(map[ny][nx] == 0 || map[ny][nx] == 2)
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny , nx});
            }
        }
    }
}

void combination(int idx, int cnt)
{   // 모든 활성 바이러스를 쓴다면 
    if(cnt == m)
    {
        bool flag = 1;
        int MAX = 0;
        virus();
        for(auto &el : possibleXY)
        {
            int ff = el.first;
            int ss = el.second;
            
            if(visited[ff][ss] == -1)
            {
                flag = 0;
                break;
            }
            else
                MAX = max(MAX, visited[ff][ss]);
        }
        if(flag)
            ans = min(MAX, ans);
        
        return;
    }

    for(int i=idx; i < virusXY.size(); i++)
    {
        int ff = virusXY[i].first;
        int ss = virusXY[i].second;
        if(combi[i])
            continue;
        else
        {
            combi[i] = 1;
            buff.push_back({ff, ss});
            combination(i, cnt+1);
            buff.pop_back();
            combi[i] = 0;
        }
    }
}

// 비활성 바이러스 : 바이러스에 감염은 되었지만, 전염은 활성화가 되어야 한다. 
int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2)
                virusXY.push_back({i, j});
            if(map[i][j] == 0)
                possibleXY.push_back({i, j});
        }
    
    combination(0, 0);

    if(ans == 987654321)
        cout << -1 << endl;
    else
    {
        if(ans != 0)
            cout << ans << endl;
        else
            cout << ans << endl;
    }
    return 0;
}