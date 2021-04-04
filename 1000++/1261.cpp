#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
int adj[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int map[105][105];
int visited[105][105] = {0, };
int min_v = 987654321;
string a;
priority_queue<pair<int, pair<int, int> > > pq;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> m >> n;
    for(int i = 1; i<=n; i++) { 
        string s;
        cin >> s;
        for(int j = 1; j<=m; j++) {
           map[i][j] = s[j-1] - '0';
        }
    }
    
    pq.push(make_pair(0, make_pair(1,1)));
    visited[1][1] = 1;
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int price = -pq.top().first;
        pq.pop();
        if(x == n && y == m) {
                cout << price;
                return 0;
        }
        for(int i = 0; i<4; i++) {
            int new_x = x + adj[i][0];
            int new_y = y + adj[i][1];
            if(new_x<1 || new_y<1 || new_x>n || new_y>m) continue;
            if(visited[new_x][new_y] == 1) continue;
            if(map[new_x][new_y] == 1) {
                //cout << "plus 1  " <<new_x << new_y << price+1 << endl;
                pq.push(make_pair(-(price+1), make_pair(new_x, new_y)));

            }   
            else {
                //cout << new_x << new_y << price << endl;
                pq.push(make_pair(-price, make_pair(new_x, new_y))); 
            }        
            visited[new_x][new_y] = 1;
        }

        //cout << endl << endl << endl;
    }
    return 0;
}