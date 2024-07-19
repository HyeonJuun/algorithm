#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count, temp, row = 0, col = 0;
	bool check = false;
	cin >> count;
	vector<vector<char>> sq(count, vector<char>(count, 0));

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			cin >> sq[i][j];
		}
	}
    // 배열에 값 입력

	for (int i = 0; i < count; i++)
	{
		temp = 0;
		check = false;
        // 초기화
		for (int j = 0; j < count; j++)
		{
			if (sq[i][j] == '.') temp++;
			else
			{
				temp = 0;
				check = false;
			}
            // X를 만났을 경우 check 초기화 및 . 연속 값을 초기화한다.

			if (temp >= 2 && check == false)
			{
				row++;
				check = true;
			}
            // 행 값을 올려주고, check 값을 true로 바꿔 가로 값 증가를 멈춘다.
		}
	}
    // 가로로 누울 자리 계산

	for (int i = 0; i < count; i++)
	{
		temp = 0;
		check = false;
		for (int j = 0; j < count; j++)
		{
			if (sq[j][i] == '.') temp++;
			else
			{
				temp = 0;
				check = false;
			}

			if (temp >= 2 && check == false)
			{
				col++;
				check = true;
			}
		}
	}
    // 세로로 누울 자리 게산

	cout << row << " " << col;
}