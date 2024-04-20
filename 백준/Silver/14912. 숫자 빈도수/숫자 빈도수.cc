#include <iostream>
#include <string>
using namespace std;
 
int main(void){
 
    int n;
    char check;
    cin >> n >> check;
    int cnt = 0;
 
    for(int i = 1;i<=n;i++){
        string str = to_string(i); //string형태로 바꿔주고
        for(int j = 0;j<str.size();j++){ //check와 같다면 cnt증가
            if(str[j] == check){
                cnt++;
            }
        }
    }
    cout << cnt;
}