#include<iostream>
#include<set>
#include<vector>
using namespace std;

int map[4][4];
set<int> s1;
int adj[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, vector<int> v) {
    if(v.size() == 7) {
        int num = 0;
        for(int i = 0; i<7; i++) {
            num*=10;
            num+=v[i];
        }
        s1.insert(num);
        return;
    }
    for(int i = 0; i<4; i++) {
        int new_x = x+adj[i][0];
        int new_y = y+adj[i][1];
        if(new_x<0 || new_x>3 || new_y<0 || new_y>3) continue;
        v.push_back(map[new_x][new_y]);
        dfs(new_x, new_y, v);
        v.pop_back();
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        s1.clear();
        for(int j = 0; j<4; j++) {
            for(int k = 0; k<4; k++) cin >> map[j][k];
        }
        for(int j = 0; j<4; j++) {
            for(int k = 0; k<4; k++) {
                vector<int> v;
                v.push_back(map[j][k]);
                dfs(j, k, v);
            }
        }
        cout << "#" << i+1 << " " << s1.size() << "\n"; 
    }
}