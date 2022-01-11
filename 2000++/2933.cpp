#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int r, c, n;
char map[101][101];
int adj[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
vector<int> v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

void bfs(int x, int y) {
    queue<pair<int, int> > q[4];
    vector<pair<int, int> > v1[4];
    for(int i = 0; i < 4; i++) {
        int new_x = x + adj[i][0];
        int new_y = y + adj[i][1];
        if(new_x < 0 || new_y < 0 || new_x >= r || new_y >= c) continue;
        if(map[new_x][new_y] == 'x') q[i].push(make_pair(new_x, new_y));
    }

    for(int i = 0; i < 4; i++) {
        bool flag = false;
        bool visited[101][101] = {false, };
        if(q[i].empty()) continue;
        visited[q[i].front().first][q[i].front().second] = true;
        v1[i].push_back(make_pair(q[i].front().first, q[i].front().second));
        while(!q[i].empty()) {
            int cur_x = q[i].front().first;
            int cur_y = q[i].front().second;
            q[i].pop();
            for(int j = 0; j < 4; j++) {
                int new_x = cur_x + adj[j][0];
                int new_y = cur_y + adj[j][1];
                if(new_x < 0 || new_y < 0 || new_x >= r || new_y >= c) continue;
                if(map[new_x][new_y] == '.') continue;
                if(visited[new_x][new_y]) continue;
                if(new_x == r-1) flag = true;
                visited[new_x][new_y] = true;
                q[i].push(make_pair(new_x, new_y));
                v1[i].push_back(make_pair(new_x, new_y));
            }
        }
        sort(v1[i].begin(), v1[i].end(), cmp);

        //for(int j = 0; j < v1[i].size(); j++) cout << v1[i][j].first << " " << v1[i][j].second << endl;

        if(!flag) {
             // 결국에 바닥에 닿지 않은친구
            char bufmap[101][101];
            bool flag2 = false;
            for(int k = 0; k < r; k++) {
                for(int l = 0; l < c; l++) {
                    bufmap[k][l] = map[k][l];
                }
            }
            
            for(int j = 1; j< r; j++) {
                for(int k = 0; k < v1[i].size(); k++) {
                    if(bufmap[v1[i][k].first + j][v1[i][k].second] == 'x' || v1[i][k].first + j>=r) {
                        flag2 = true;
                        break;
                    }
                    bufmap[v1[i][k].first + j][v1[i][k].second] = 'x';
                    bufmap[v1[i][k].first + j - 1][v1[i][k].second] = '.';
                }
                if(!flag2) {
                    for(int k = 0; k < r; k++) {
                        for(int l = 0; l < c; l++) {
                            map[k][l] = bufmap[k][l];
                        }
                    }
                }
                else break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);   
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r  >> c;
    int buf;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> buf;
        v.push_back(buf);
    }

    for(int i = 0; i < n; i++) {
        if(i%2 == 0) { // 왼쪽부터
            int j = 0;
            while(map[r- v[i]][j] != 'x') j++;
            if(j >= c) continue;
            map[r-v[i]][j] = '.';
            bfs(r-v[i], j); 
        }
        else {
            int j = c-1;
            while(map[r-v[i]][j] != 'x') j--;
            if(j < 0) continue;
            map[r-v[i]][j] = '.';
            bfs(r-v[i], j);
        }
    }

    for(int i = 0; i< r; i++) {
        for(int j = 0; j < c; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
    
}