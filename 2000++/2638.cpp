#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int paper[101][101];
int visit_dfs[101][101] = {0, };
int visit_bfs[101][101] = {0, };

int adj[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
queue <pair<int, int> > q1;
int n, m;
void dfs(int x, int y){
    visit_dfs[x][y] = 1;
    for(int i = 0; i<4; i++){
        int new_x = x + adj[i][0];
        int new_y = y + adj[i][1];
        if(new_x>=n || new_x<0 || new_y>=m || new_y<0) continue;
        if(visit_dfs[new_x][new_y] == 1) continue;
        if(paper[new_x][new_y] == 1) continue;
        paper[new_x][new_y] = 2;//외부공기
        dfs(new_x,new_y);
    }
}
void bfs(void){
    int time = 0;
    paper[0][0] = 2;
    dfs(0,0);
    while(!q1.empty()){
        memset(visit_bfs,0, sizeof(visit_bfs));
        int count = 0;
        for(int i = 0; i<q1.size(); i++){
            int nowx = q1.front().first;
            int nowy = q1.front().second;
            q1.pop();
            visit_bfs[nowx][nowy] = 1;
            for(int j = 0; j<4; j++){
                int newx = nowx+adj[j][0];
                int newy = nowy+adj[j][1];
                if(visit_bfs[newx][newy] == 1) continue;
                if(newx>=n || newx<0 || newy>=m || newy<0) continue;
                if(paper[newx][newy]!=2) continue;
                count++;
            }
            if(count>=2){
                paper[nowx][nowy] = 2;
            }
            else{
                q1.push(make_pair(nowx,nowy));
            }
        }
        time++;
    }
    cout << time;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> paper[i][j];
            if(paper[i][j] == 1){
                q1.push(make_pair(i,j));
            }
        }
    }
    bfs();
}