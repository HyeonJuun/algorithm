#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
char List[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
string ChangeNum(int num, int x)
{
    string res = "";
    while (num / x != 0)
    {
        string tmp = res;
        res = List[num % x];
        res += tmp;
        num /= x;
    }
    string tmp = res;
    res = List[num % x];
    res += tmp;
    return res;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string Result = "";
    int cnt = 0;
    for (int i = 0; i < t * m; i++) 
    {
        Result += ChangeNum(i, n);
        //cout << Result << endl;
    }
    for (int i = p - 1; i < Result.length(); i += m)
    {
        answer += Result[i];
        cnt++;
        if(cnt >= t)
            break;
    }
    return answer;
}