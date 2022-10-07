#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n, l;
	cin >> n >> l;
	int t, x=-1, iter = -1;
	
	for(int i = l; i<=100;i++)
	{
		t = (i-1) * i /2;
		if((n - t) % i == 0 && (n-t) / i >=0)
		{
			x = (n-t) / i;
			iter = i;
			break;
		}
	}
	
	if(x == -1)
	{
		cout << -1 << endl;		
	}
	
	else
	{
		for(int i=0; i<iter; i++)
		{
			cout << x + i << " ";
		}
	}
	return 0;
}