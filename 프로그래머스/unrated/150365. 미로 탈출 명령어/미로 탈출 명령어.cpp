#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> ans;
bool isanswer = false;
string answer = "";

void dfs(int n, int m, int x, int y, int ex, int ey, int k, int dep, string route)
{
    if(isanswer)
            return;
    if(k == dep)
    {
        if(x == ex && y == ey)
        {
            answer = route;
            isanswer = true;
        }
        return;
    }
    if(x > n || x < 1 || y > m || y < 1)
        return;
    if(k - dep < abs(x -ex) + abs(y - ey))
        return;
    dfs(n, m, x + 1, y, ex, ey, k, dep+1, route + "d");
    dfs(n, m, x, y - 1, ex, ey, k, dep+1, route + "l");
    dfs(n, m, x, y + 1, ex, ey, k, dep+1, route + "r");
    dfs(n, m, x - 1, y, ex, ey, k, dep+1, route + "u");
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    int remain = abs(x -r) + abs(y - c);
    if((k - remain) % 2 != 0 || remain > k)
        answer = "impossible";
    else
    {
        dfs(n, m, x, y, r, c, k, 0, "");
    }
    if(!isanswer)
        answer = "impossible";
    return answer;
}