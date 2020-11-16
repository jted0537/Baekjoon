#include<iostream>
#include<queue>
using namespace std;
class alpha{
public:
    int row;
    int col;
};
int mover[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int map[9][9] = {0, };
bool visited[9][9] = {false, };
int n, m;
queue <pair<int , int> > q1;
alpha ala[64];
int bfs(queue<pair<int, int> > real_q, pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    int buf_map[9][9];
    int sum = 0;
    for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) buf_map[i][j] = map[i][j];
    buf_map[p1.first][p1.second] = 1;
    buf_map[p2.first][p2.second] = 1;
    buf_map[p3.first][p3.second] = 1;
    bool visited[9][9] = {false, };
    while(!real_q.empty()){
        int cu_row = real_q.front().first;
        int cu_col = real_q.front().second;
        real_q.pop();
        visited[cu_row][cu_col] = true;
        for(int i = 0; i<4; i++){
            int new_row = cu_row + mover[i][0];
            int new_col = cu_col + mover[i][1];
            if(new_row>=n || new_row<0 || new_col>=m || new_col<0) continue;
            if(!visited[new_row][new_col] && buf_map[new_row][new_col] == 0){
                buf_map[new_row][new_col] = 2;
                real_q.push(make_pair(new_row,new_col));
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++) if(buf_map[i][j]==0) sum++;
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int k = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j]==2) q1.push(make_pair(i,j));
            else if(map[i][j] == 0){
                ala[k].row = i;
                ala[k].col = j;
                k++;
            }
        }
    }
    int maxx = 0;
    for(int i = 0; i<k-2; i++){
        for(int j = i+1; j<k-1; j++){
            for(int p = j+1; p<k; p++){
                queue<pair<int, int> > buf_q = q1;
                int p1_row = ala[i].row;
                int p1_col = ala[i].col;
                int p2_row = ala[j].row;
                int p2_col = ala[j].col;
                int p3_row = ala[p].row;
                int p3_col = ala[p].col;
                maxx = max(maxx, bfs(buf_q,make_pair(p1_row,p1_col),make_pair(p2_row,p2_col),make_pair(p3_row,p3_col)));         
            }
        }
    }
    cout << maxx << "\n";
}