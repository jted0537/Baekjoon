#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int n,m;
int map[1001][1001];
int adj[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int checkmap[1001][1001][2] = {0, };
queue <pair<pair<int,int>, int> > q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            map[i][j] = s[j]-'0';
        }
    }
    q.push(make_pair(make_pair(0,0), 0));
    checkmap[0][0][0] = 1;
    while(!q.empty()){
        int dx = q.front().first.first;
        int dy = q.front().first.second;
        int check = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int newx = dx + adj[i][0];
            int newy = dy + adj[i][1];
            if(newx>=n || newx<0 || newy>=m || newy<0) continue;
            if(map[newx][newy] == 0 && checkmap[newx][newy][check] == 0){
                q.push(make_pair(make_pair(newx,newy),check));
                checkmap[newx][newy][check] = checkmap[dx][dy][check]+1;
            }
            if(map[newx][newy] == 1 && check == 0){
                q.push(make_pair(make_pair(newx,newy),1));
                checkmap[newx][newy][1] = checkmap[dx][dy][check]+1;
            }
        }
    }

    if(checkmap[n-1][m-1][0] == 0 && checkmap[n-1][m-1][1] == 0) cout << -1;
    else if(checkmap[n-1][m-1][0] == 0) cout << checkmap[n-1][m-1][1];
    else if(checkmap[n-1][m-1][1] == 0) cout << checkmap[n-1][m-1][0];
    else cout << min(checkmap[n-1][m-1][0],checkmap[n-1][m-1][1]);
}