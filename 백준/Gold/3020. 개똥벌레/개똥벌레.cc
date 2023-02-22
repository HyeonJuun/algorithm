#include <iostream>
#include <algorithm>

using namespace std;

int n, h;
int deltha[500010];
int prefix[500010];

int x;
int main() {
  
  cin >> n >> h;
  for(int i=0; i<n; i++)
  {
    if(i % 2 == 0)
    {
      cin >> x;
      deltha[1]++;
      deltha[x + 1]--;
    }
    else
    {
      cin >> x;
      deltha[h + 1]--;
      deltha[h - x + 1]++;
    }
  }
  for(int i=1; i<=h;i ++)
  {
    prefix[i] = prefix[i-1] + deltha[i];
  }
  int mn = 100000000, cnt =0;
  for(int i=1; i<=h; i++)
  {
    if(prefix[i] < mn)
      mn = prefix[i];
  }
  cout << mn << " ";
  for(int i=1; i<=h; i++)
    {
      if(mn == prefix[i])
        cnt ++;
    }
  cout << cnt;
  return 0;
}