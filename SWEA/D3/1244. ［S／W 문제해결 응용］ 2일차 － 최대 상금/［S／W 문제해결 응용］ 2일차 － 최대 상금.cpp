#include<iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

string num;
int ans, change;

void dfs(int ind, int cur)
{
	if(cur == change)
    {
        ans = max(ans, stoi(num));
    	return;
    }
    
    for(int i = ind; i<num.size() - 1; i++)
    {

        for(int j= i+1; j<num.size(); j++)
        {
			swap(num[i], num[j]);
            dfs(i, cur + 1);
            swap(num[i], num[j]);
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; test_case++)
	{
        cin >> num >> change;
        ans = 0;
        
        if(change > num.size())
            change = num.size();
        
        dfs(0, 0);
        
        cout << "#" << test_case << " " << ans << '\n';
    }           
            
        
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}