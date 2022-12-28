#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int N, M;
const int MAX = 10001;
vector<int> map[MAX];
bool visited[MAX];
queue<int> q;
vector<pair<int, int>> v; //<컴퓨터 번호, 해킹 가능한 컴퓨터 수> 벡터
int hacked = 1; //해킹 가능한 컴퓨터 수
 
void BFS(int v) {
    visited[v] = true;
    q.push(v);
 
    while (!q.empty()) {
        v = q.front();
        q.pop();
 
        for (int w = 0; w < map[v].size(); w++) {
            int nv = map[v][w];
            
            if (visited[nv] == 0) {
                visited[nv] = true;
                q.push(nv);
                hacked++;
            }
        }
    }
}
 
void resetVisit() {
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }
}
 
int main() {
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int a, b;
        cin >> a >> b;
        map[b].push_back(a);
    }
 
    for (int i = 1; i <= N; i++) {
        BFS(i);
        resetVisit();
        v.push_back(make_pair(i,hacked));
        hacked = 1;
    }
 
    //해킹 가능한 최대 컴퓨터 수 구하기
    int maxHack = -1; 
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second > maxHack) {
            maxHack = v[i].second;
        }
    }
 
    //maxHack에 해당하는 컴퓨터 번호 모두 출력
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == maxHack) {
            cout << v[i].first << " ";
        }
    }
    
}
