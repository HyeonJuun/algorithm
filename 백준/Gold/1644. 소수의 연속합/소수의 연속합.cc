#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, k;
int arr[4000010];
int prime[4000010];
void SetPrime()
{
  for(int i=1; i<=4000000; i++)
    arr[i] = 1;
  arr[1] = 0;
  for(int i = 2; i * i <=4000000; i++)
  {
    if(arr[i] == 0)
      continue;
    for(int j = i * i; j<=4000000; j+=i)
    {
      arr[j] = 0;
    }
  }
  for(int i = 2; i<= 4000000; i++)
  {
    if(arr[i])
    {
      prime[k] = i;
      k++;
    }
  }
}
int main() {
  
  cin >> n;
  SetPrime();
  int s = 0, e = 0, sum = prime[0], cnt =0;
  while(e < k)
  {
    if(sum == n)
      {
        cnt++;
        e++;
        sum += prime[e];
      }
    if(sum > n)
    {
      sum-= prime[s];
      s++;
    }
    else
    {
      e++;
      sum += prime[e];
    }
  }
  cout << cnt;
  return 0;
}