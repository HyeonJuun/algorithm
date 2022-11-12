#include <iostream>
#include <cmath>
using namespace std;

int W, H, X, Y, P;


int check_coordinate(int x, int y)
{
	if ((x >= X && x <= X + W) && (y >= Y && y <= Y + H))
		return 1;
	else if (pow(H / 2, 2) >= pow(X - x, 2) + pow(Y + H / 2 - y, 2) || pow(H / 2, 2) >= pow(X + W - x, 2) + pow(Y + H / 2 - y, 2))
		return 1;
	return 0;
}

int main(void)
{
	int answer = 0;
	int x, y;
	cin >> W >> H >> X >> Y >> P;
	for (int i = 0; i < P; i++)
	{
		cin >> x >> y;
		answer += check_coordinate(x, y);
	}
	cout << answer;
	return 0;
}