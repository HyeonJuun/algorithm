#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void){
    int n;
    cin >> n;
    map<string,int> m;
    map<string,int>::iterator iter;

    int ans = 0; //서로 다른 단어가 몇 개인지
    
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        iter = m.find(str); 
        //문자열을 입력받고 map에 없다면 서로 다른 단어 + map에 사이클 단어를 모두 넣어줌
        
        if(iter == m.end()){ //map에 없는 경우
            ans++;
            
            /*사이클 단어를 만드는 코드*/
            for(int j = 0;j<str.size();j++){ 
            string temp = "";
            for(int k = j;k<str.size();k++){
                temp = temp + str[k];
            }
                
            for(int q = 0;q<j;q++){
                temp = temp + str[q];
            }

                m.insert({temp,i});
                
        }
        
        }
        else{
            continue;
        }
      
        
        
    }
    cout << ans;
}