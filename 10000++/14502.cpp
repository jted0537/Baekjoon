#include<iostream>
#include<queue>
using namespace std;

class non {
public:
    int row;
    int col;
};
int n,m;
int adj[4][2] = {{1, 0}, {-1,0}, {0,1}, {0,-1}};
int map[8][8];
non zero[64];
queue <pair<int, int> > virus, virus_buffer;

int bfs(int x1, int y1, int x2, int y2, int x3, int y3) {
    int x, y, new_x, new_y, cnt = 0;
    int map_buffer[8][8];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            map_buffer[i][j] = map[i][j];
        }
    }
    map_buffer[x1][y1] = 1;
    map_buffer[x2][y2] = 1;
    map_buffer[x3][y3] = 1;
    virus_buffer = virus;

    while(!virus_buffer.empty()){
        x = virus_buffer.front().first;
        y = virus_buffer.front().second;
        virus_buffer.pop();

        for(int i = 0; i<4; i++){
            new_x = x + adj[i][0], new_y = y + adj[i][1];
            if(new_x >= n || new_x < 0 || new_y >= m || new_y<0 ) continue;
            if(map_buffer[new_x][new_y] == 1 || map_buffer[new_x][new_y] == 2) continue;
            else if(map_buffer[new_x][new_y] == 0) {
                map_buffer[new_x][new_y] = 2;
                virus_buffer.push(make_pair(new_x, new_y));
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) if(map_buffer[i][j] == 0) cnt++;
    }
    return cnt;  
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l = 0;
    int maxx = -1;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2) {
                virus.push(make_pair(i,j));
            }
            else if(map[i][j] == 0) {
                zero[l].row = i, zero[l].col = j;
                l++;
            }
        }
    }

    for(int i = 0; i<l-2; i++){
        for(int j = i+1; j<l-1; j++){
            for(int k = j+1; k<l; k++){
                int x1 = zero[i].row, y1 = zero[i].col;
                int x2 = zero[j].row, y2 = zero[j].col;
                int x3 = zero[k].row, y3 = zero[k].col;
                maxx = max(maxx, bfs(x1,y1,x2,y2,x3,y3));
            }
        }
    }
    
    cout << maxx << endl;
}