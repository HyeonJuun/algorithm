#include <iostream>

using namespace std;

int main() {
	int n, ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2, r1, r2, d, rsub, rsum;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		rsub = (r1 - r2) * (r1 - r2);
		rsum = (r1 + r2) * (r1 + r2);

		if (d == 0)
		{
			if (rsub == 0)
				cout << "-1" << endl;
			else
				cout << "0" << endl;
		}
		else if (rsum == d || rsub == d)
			cout << "1" << endl;
		else if (rsub < d && d < rsum)
			cout << "2" << endl;
		else
			cout << "0" << endl;
	}
}