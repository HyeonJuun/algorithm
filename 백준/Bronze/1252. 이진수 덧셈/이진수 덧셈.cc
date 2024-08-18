#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    string a, b;
    cin >> a >> b;
 
    // 문자열의 길이가 b가 더 길다면 둘을 바꿔준다.
    if (a.length() < b.length()) swap(a, b);
 
    // 두 문자열의 길이를 맞춰준다.
    while (a.length() != b.length()) b = '0' + b;
 
    // 뒤에서부터 보며 이진법 덧셈을 진행한다.
    string temp = "";
    bool flag = 0;
    for (int i = a.length() - 1; i > -1; i--)
    {
        int t1 = a[i] == '1' ? 1 : 0;
        int t2 = b[i] == '1' ? 1 : 0;
 
        if (t1 + t2 + flag == 3)
        {
            temp ='1' + temp;
        }
        else if (t1 + t2 + flag == 2)
        {
            flag = 1;
            temp = '0' + temp;
        }
        else if (t1 + t2 + flag == 1)
        {
            flag = 0;
            temp = '1' + temp;
        }
        else if (t1 + t2 + flag == 0)
        {
            flag = 0;
            temp = '0' + temp;
        }
    }
 
    // 마지막에 flag가 1이라면 맨 앞에 1을 더해준다.
    if (flag == 1) temp = '1' + temp;
 
    // 문자열의 앞쪽이 0일 경우를 대비해 잘라준다.
    string ans = "";
    flag = false;
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] != '0') flag = true;
 
        if (flag == true) ans += temp[i];
    }
 
    // flag가 false라면 0으로만 이루어진 문자열이므로 0 출력
    if (flag == true) cout << ans;
    else cout << 0;
 
    return 0;
 
}
 
