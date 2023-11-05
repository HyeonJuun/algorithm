#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	for(int i = 1; i <= 10; i++)
    {
        int t;
        vector<int> v;
        cin >> t;
        
        for(int j = 0; j < 100; j++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        
        for(int j = 0; j < t; j++)
        {
            sort(v.begin(), v.end());
            if(v.back() - v.front() <= 1)
                break;
            v[0]++;
            v[99]--;
        }
        sort(v.begin(), v.end());
        cout << "#" << i << " " << v.back() - v.front() << endl;
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}