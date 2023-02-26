#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ans = -1;
int N;
string from, to;

char change(char ch){
    if(ch == '0')
        return '1';
    else return '0';
}

void solution(string &str, int cnt, int x){
    if(x == N){
        if(str[x-1] == to[x-1]){
            if(ans == -1) ans = cnt;
            else ans = min(ans, cnt);
        }
        return;
    }

    if(str[x-1] == to[x-1])
        solution(str, cnt, x+1);
    else{ // 뒤집기
        str[x-1] = change(str[x-1]);
        str[x] = change(str[x]);
        if(x+1 < N)
            str[x+1] = change(str[x+1]);
        solution(str, cnt+1, x+1);
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> from >> to; 
    
    string tmp = from;
    solution(from, 0, 1);

    if(ans == -1){
        from = tmp;
        from[0] = change(from[0]);
        from[1] = change(from[1]);
        solution(from, 1, 1);
    }
    cout << ans << '\n';
    return 0;
}