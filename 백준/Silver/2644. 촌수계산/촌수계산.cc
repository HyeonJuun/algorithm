#include <iostream>
#include <queue>

using namespace std;
#define MAX 102

int n,target_x,target_y,m;
int cnt=0;
int arr[MAX][MAX];
int visited[MAX];
queue<int> q;

void bfs(int k) {
    q.push(k);

    while(!q.empty()) {
        k = q.front();
        q.pop();
        for(auto i=1;i<=n;i++) {
            if(arr[k][i]!=0 && !visited[i]) {
                q.push(i);
                visited[i]=visited[k]+1; 
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> target_x >> target_y;
    cin >> m;

    for(int i=0;i<m;i++) {
        int x,y;
        cin >> x >> y;
        arr[x][y]=1;
        arr[y][x]=1;
    }

    bfs(target_x);

    if(visited[target_y]==0)
        visited[target_y]=-1;
        
    cout << visited[target_y];
}