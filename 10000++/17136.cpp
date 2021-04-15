#include<iostream>

using namespace std;

#define MAX 10

int map[10][10] = {0, };
int ans = 987654321;
int paper[5] = {5,5,5,5,5};


void make_map_2(int x, int y, int num, int a) {
    for(int i = 0; i<num; i++){
        for(int j = 0; j<num; j++){
            map[x+i][y+j] = a;
        }
    }
}

int finder(int x, int y, int num) {
    for(int i = 0; i<num; i++) {
        for(int j = 0; j<num; j++) {
            if(x+i>=MAX || y+j>=MAX || map[x+i][y+j] == 0) return 0;
        }
    }
    return 1;
}


void dfs(int x, int y){
    if(y >= MAX) {
        dfs(x+1, 0);
        return;
    }
    if(x >= MAX) {
        for(int i = 0; i<10; i++) {
            for(int j = 0; j<10; j++) {
                if(map[i][j] == 1) return;
            }
        }
        ans = min(ans, 25-(paper[0]+paper[1]+paper[2]+paper[3]+paper[4]));
        return;
    }

    for(int i = 5; i>0; i--) {
        if(paper[i-1] == 0) continue;
        int as = finder(x, y, i);
        if(as==1) {
            make_map_2(x, y, i, 0);
            paper[i-1]--;
            dfs(x, y+i);
            paper[i-1]++;
            make_map_2(x, y, i, 1);
        } 
    }

    if(map[x][y] == 0) dfs(x, y+1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            cin >> map[i][j];
        }
    }

    dfs(0,0);

    if (ans == 987654321) {
        cout << "-1" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
