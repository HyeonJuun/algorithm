#include <cstring>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n, x;
        cin >> n;
		
		int score[101];
       	memset(score, 0, sizeof(score));
        for(int i=0; i<1000; i++)
        {
			cin >> x;
            score[x]++;
        }
		int answer = 0, mx = -1;
        for(int i=0; i<=100; i++)
        {
            if(mx <= score[i])
            {
                answer = i;
             	mx = score[i];   
            }
        }
		cout << "#" << n << " " << answer << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}