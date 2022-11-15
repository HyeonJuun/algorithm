#include <iostream>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    char c;
    int T, k, n;
    cin >> T;
    while(T--){
        cin >> k;
        multiset<int> q; // multiset 오름차순 정렬
        for (int i = 0; i < k;i++){
            cin >> c >> n;
            if(c =='I'){
                q.insert(n); // 삽입
            }else if(c == 'D'){
                if(q.empty()){
                    continue;
                }else if(n == 1){ // 최대값 제거시
                    auto iter = q.end(); // 맨 끝값 +1 
                    iter--; // 맨 끝값으로 이동
                    q.erase(iter); // 최대값 삭제
                }else if(n == -1){
                    q.erase(q.begin()); // 최소값 삭제
                }
            }
        }
        if(q.empty()){
            cout << "EMPTY" << '\n';
        }else {   
            auto iter = q.end();
            iter--;
            cout << *iter << " " << *q.begin() << '\n';
        }
    }
    return 0;
}