#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> getsplit(string s) { // 공백을 기준으로 단어 split 하기
    stringstream ss(s);
    vector<string> tmp;
    string t;
    while (getline(ss, t, ' ')) {
        tmp.push_back(t);
    }
    return tmp;
}

bool checkbig(char c) { // 대문자 체크
    if (c >= 65 && c <= 90) {
        return true;
    }
    return false;
}

string getkey(string s, vector<int> &al) {
    bool selected = false;
    vector<string> word = getsplit(s);
    string tmp = "";

    for (int i = 0; i < word.size(); i++) { 
        // 명령어의 각 단어의 첫 글자를 확인하는 구간.
        char a = word[i][0];
        if (checkbig(a)) a += 32;
        if (!selected && al[a - 'a'] == 0) {
            al[a - 'a'] = 1;
            string key = "[" + word[i].substr(0, 1) + "]"; // 단어의 맨 앞을 [ ] 로 감싸는 작업.
            word[i].replace(0, 1, key);
            selected = true;
        }
        tmp += word[i]; // 탐색을 완료한 각 단어를 하나로 합침.
        if (i < word.size() - 1) tmp += " ";
    }
    s = tmp; // 합친 단어를 기존에 덮어씌우기

    if (!selected) { // 만약 단어의 앞자리가 모두 이미 지정된 단축키면 이쪽으로 넘어옴.
        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            if (checkbig(a)) a += 32;
            if (a != ' ' && al[a - 'a'] == 0) {
                al[a - 'a'] = 1;
                string key = "[" + s.substr(i, 1) + "]";
                s.replace(i, 1, key);
                break;
            }
        }
    }
    return s;
}

int main()
{
    vector<int> al(27, 0);
    int N;
    string s;
    vector<string> orders;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        orders.push_back(s);
    }
    for (int i = 0; i < N; i++) {
        orders[i] = getkey(orders[i], al);
        cout << orders[i] << "\n";
    }
}
