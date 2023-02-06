#include <iostream>
#include<vector>

using namespace std;

int n, m;
int a, b;
int cnt, recnt;

bool visited[110];
bool revisited[110];
vector<int> v[110];
vector<int> rv[110];

void dfs(int node)
{
    visited[node] = true;
    
    for(int i=0; i<v[node].size(); i++)
    {
        int next = v[node][i];
        if(!visited[next])
        {
            cnt++;
            dfs(next);
        }
    }
}

void rdfs(int node)
{
    revisited[node] = true;
    
    for(int i=0; i<rv[node].size(); i++)
    {
        int next = rv[node][i];
        if(!revisited[next])
        {
            recnt++;
            rdfs(next);
        }
    }
}

void memreset()
{
  cnt = 0;
  recnt=0;
  for(int i=1; i<=n; i++)
  {
    visited[i] = false;
    revisited[i]= false;
  }
}
int main() {
  
  cin >> n >> m;
  for(int i=0; i< m;i++)
  {
    cin >> a >> b;
    v[a].push_back(b);
    rv[b].push_back(a);
  }
  int ans = 0;
  
  for(int i=1; i<=n;i++)
  {
    memreset();
    dfs(i);
    rdfs(i);
    
    if(cnt >= (n+1)/2 || recnt >=(n+1)/2)
    ans++;
  }
  cout << ans;
  return 0;
}