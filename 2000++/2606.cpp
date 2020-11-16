#include<iostream>
#include<queue>

using namespace std;
int n, m;
int adj[101][101];
queue <int> q;
bool visit[101] = {false, };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }
    q.push(1);
    visit[1] = true;
    while(!q.empty()){
        int z = q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if(i==z) continue;
            else{
                if(!visit[i] && adj[z][i] == 1){
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }
    int num=0;
    for(int i=1; i<=n; i++){
        if(visit[i])
            num++;
    }
    cout << num-1;
}