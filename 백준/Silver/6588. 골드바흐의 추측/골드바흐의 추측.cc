#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 1000000 + 1;

int n;
int is_prime[MAX];

void Set_prime()
{
	for (int i = 2; i < MAX; i++)
		is_prime[i] = 1;
	is_prime[1] = 0;
	for (int i = 2; i * i <= MAX; i++)
	{
		if (is_prime[i] == 0)
			continue;
		for (int j = i * i; j <= MAX; j += i)
		{
			is_prime[j] = 0;
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	Set_prime();

	while (cin >> n)
	{
		if (n == 0)
			break;
		bool flag = false;
		for (int i = 3; i <= n; i++)
		{
			if (i % 2 == 1 && (n - i) % 2 == 1)
			{
				if (is_prime[i] == 1 && is_prime[n - i] == 1)
				{
					cout << n << " = " << i << " + " << n - i << '\n';
					flag = true;
					break;
				}
			}
		}
		if(!flag)
			cout << "Goldbach's conjecture is wrong." << '\n';
	}
	return 0;
}