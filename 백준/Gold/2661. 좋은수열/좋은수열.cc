#include <iostream>

using namespace std;
int n;
int arr[110];
bool printed = false;
bool check(int x, int length)
{
  for(int i = 0; i< length; i++)
  {
    if(arr[x - i] != arr[x - i - length])
      return true;
  }
  return false;
}
void solve(int dep)
{
  if(printed == true)
      return;
    
  if(dep == n)
  {
    for(int i=0; i<n;i++)
      cout << arr[i];
    cout << '\n';
    printed = true;
    return;
  }
  
  for(int i=1; i<=3;i++)
  {
    arr[dep] = i;
    bool flag = false;
    for(int j =1; j<=(dep + 1) / 2; j++)
    {
      if(!check(dep, j))
      {
        flag = true;
        break;
      }
    }
    if(flag == false)
      solve(dep + 1);
  }
}
int main() {
  
  cin >> n;
  solve(0);
  return 0;
}