#include <iostream>
#include <algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

const int MAX = 100000000 + 1;


int n, d, from, to, dist;

int main() 
{
    cin >> n >> d;
    vector<int> map(d + 1, MAX);
    //지름길의 정보를 저장한다.
    vector<pair<int, int>> sc[10001];
    for (int i = 0; i < n; i++)
    {
        cin >> from >> to >> dist;
        sc[to].push_back(make_pair(from, dist));
    }
    map[0] = 0;

    for (int i = 1; i <= d; i++)
    {
        // 지름길이 없으면 그냥 +1
        if (sc[i].size() == 0)
            map[i] = map[i - 1] + 1;
        // 만약 지름길이 있다면
        else
        {
            // 지름길의 개수만큼 반복문을 수행
            for (auto v:sc[i])
            {
                // 그냥 길로 +1 한것과 지름길로 왔을 때의 정보를 비교
                // map[v.first] 는 출발점까지의 최단거리 v.second는 지름길의 거리
                // 지름길로 온 거리와 그냥 온 거리를 비교한다.
                map[i] = min(map[i], min(map[i - 1] + 1, map[v.first] + v.second));
            }
        }
    }
    cout << map[d] << endl;
    return 0;

}