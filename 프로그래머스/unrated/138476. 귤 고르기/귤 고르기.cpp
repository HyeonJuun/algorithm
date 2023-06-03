#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> mp;

bool cmp(pair<int,int> a, pair<int, int> b)
{
    if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(int i=0; i<tangerine.size(); i++)
    {
        mp[tangerine[i]]++;
    }
    vector<pair<int, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);
    
    int sum =0;
    for(int i =0; i<v.size();i++)
    {
        answer++;
        sum += v[i].second;
        if(sum >= k)
            break;
    }
    return answer;
}