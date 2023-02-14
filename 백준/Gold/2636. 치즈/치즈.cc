#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

char arr[110][110];
bool visited[110][110];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m;
int res, t;
bool bfs()
{
  visited[0][0] = true;
  int cnt = 0;
  queue<pair<int, int>> q;
  q.push({0, 0});
  t++;
  while(!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    
    for(int i=0; i<4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx <0 || ny <0 || nx >= n || ny>=m)
        continue;
      if(!visited[nx][ny])
      {
        if(arr[nx][ny] == '0')
        {
          q.push({nx, ny});
        }
        else
        {
          arr[nx][ny] = '0';
          cnt++;
        }
        visited[nx][ny] = true;
      }
    }
  }
  if(cnt == 0)
  {
    cout << t - 1 << '\n' << res;
    return true;
  }
  else
  {
    res = cnt;
    return false;
  }
}

int main() {
  
  cin >> n >> m;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
    {
      cin >> arr[i][j];
    }
  }
  while(true)
  {
    if(bfs())
      break;
    memset(visited, false, sizeof(visited));
  }
  
  return 0;
}