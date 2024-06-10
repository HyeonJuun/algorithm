#include <iostream>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;

	int Basket[100];
	for (int a = 1; a <= N; a++)
	{
		Basket[a] = a;
	}

	for (int a = 1; a <= M; a++)
	{
		int i, j;
		cin >> i >> j;
		int change = Basket[i];
		Basket[i] = Basket[j];
		Basket[j] = change;
	}

	for (int a = 1 ; a <= N; a++)
	{
		cout << Basket[a] << " ";
	}
}