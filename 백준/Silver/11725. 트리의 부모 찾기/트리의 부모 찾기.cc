#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
queue<int>q;
vector<int>v[100001];
int parent[100001];
void bfs(){
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i=0;i<v[curr].size();i++){
            int next=v[curr][i];
            if(parent[curr]==next)continue;
            q.push(next);
            parent[next]=curr;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>N;
    for(int i=1;i<N;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(1);
    bfs();
    for(int i=2;i<=N;i++)cout<<parent[i]<<"\n";
}