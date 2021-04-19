#include<iostream>

using namespace std;

int adj[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int map[501][501];
int visited[501][501];
int n;
int new_x, new_y;

int dfs(int x, int y){
    if(visited[x][y]) return visited[x][y];
    visited[x][y] = 1;
    for(int i = 0; i<4; i++) {
        new_x = x + adj[i][0];
        new_y = y + adj[i][1];
        if(new_x<0 || new_x>=n || new_y<0 || new_y>=n) continue;
        if(map[x][y] < map[new_x][new_y]) {
            visited[x][y] = max(visited[x][y], dfs(new_x, new_y)+1);
        }
    }
    return visited[x][y];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int res;
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            res = max(res, dfs(i, j));
        }
    }
    cout << res << endl;
}