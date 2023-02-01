#include <iostream>
#include<stack>
using namespace std;

int n;
int arr[100010];
int l[100010];
int r[100010];
stack<int> st;
int main() {
  
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> arr[i];
  arr[0] = -1;
  st.push(0);
  for(int i=1; i<=n; i++)
  {
    while(arr[st.top()] >= arr[i]) st.pop();
    l[i] = st.top();
    st.push(i);
  }
  while(!st.empty())  st.pop();
  arr[n+1] = -1;
  st.push(n+1);
  for(int i=n; i>=1; i--)
  {
    while(arr[st.top()] >= arr[i]) st.pop();
    r[i] = st.top();
    st.push(i);
  }
  int ans = 0;
  for(int i=1; i<=n; i++)
  {
    int area = arr[i] * (r[i] - l[i] - 1);
    if(ans < area)
      ans = area;
  }
  cout << ans;
  return 0;
}