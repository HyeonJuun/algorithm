#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
    int answer = 0;
    vector<int> tt(1320, 0);
    
    for(int i=0; i<m;i++)
    {
        int s = timetable[i][0];
        int e = timetable[i][1];
        for(int j = s; j<=e; j++)
            tt[j]++;
    }
    
    int p = *max_element(tt.begin(), tt.end());
    
    if(p <= 1)
        return 0;
    
    int maxdist = 2 * n - 2;
    for(int dist = maxdist; dist > 0; dist--)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j= 0; j < n; j++)
            {
                vector<pair<int, int>> v({{i, j}});
                for(int y = i; y<n; y++)
                {
                    for(int x =0 ; x<n; x++)
                    {
                        if(y == i & x == j)
                            continue;
                        
                        bool canpush = true;
                        for(auto pe : v)
                        {
                            int d = abs(pe.first - y) + abs(pe.second - x);
                            if(d < dist)
                            {
                                canpush = false;
                                break;
                            }
                        }
                        if(canpush)
                        {
                            v.emplace_back(y, x);
                            if(p == v.size())
                                return dist;
                        }
                    }
                }
            }
        }
    }
    return 0;
}