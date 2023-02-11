#include <iostream>
#include <vector>

using namespace std;

int n, r;
vector<int> v[60];
int par[60];
int sz[60];
int erase;

void solve(int cur)
{
  if(cur == erase)
    return;
  sz[cur] = 1;
  for(int i=0; i<v[cur].size(); i++)
  {
    solve(v[cur][i]);
    sz[cur] += sz[v[cur][i]];
  }
}
int main() {
  
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int x;
    cin >> x;
    if(x == -1)
      r = i;
    else
    {
      v[x].push_back(i);
      par[i] = x;
    }
  }
  cin >> erase;
  solve(r);
  int cnt =0;
  for(int i=0; i<n; i++)
  {
    if(sz[i] == 1)
      cnt++;
  }
  cout << cnt;
  return 0;
}