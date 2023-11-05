
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		
        int num;
        cin >> num;
        vector<int> arr(num, 0);
        for(int i=0;i<num; i++)
        {
        	cin >> arr[i];
        }
        long long mx = -1, ans = 0;
        for(int i= num- 1; i>= 0 ; i--)
        {
        	if(arr[i] > mx)
            {
             	mx = arr[i];   
            }
            else
            {
                ans += (mx - arr[i]);
            }
        }
        cout << "#" << test_case << " " << ans << '\n';
		

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}