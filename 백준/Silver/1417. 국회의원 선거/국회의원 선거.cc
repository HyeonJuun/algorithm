#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 50
int arr[MAX];

int main() {
	int n, cnt = 0;
	int dasom = 0;
	cin >> n;
	//cin >> dasom;

	for (int i = 0; i < n; i++) 
	{
		int m;
		cin >> m;
		arr[i] = m;
	}
	while (true)
	{
		int max_vote = 0;
		int max_idx = 0;

		for (int i = 1; i < n ; i++)
		{
			if (max_vote < arr[i]) {
				max_vote = arr[i];
				max_idx = i;
			}
		}
		if (arr[0] > max_vote)
		{
			cout << cnt << endl;
			break;
		}

		arr[0] = arr[0] + 1;
		arr[max_idx] = arr[max_idx] - 1;
		cnt++;

	}
	return 0;
}
