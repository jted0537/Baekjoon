#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int maze[3];
int min_ans[2][3] = {0, };
int max_ans[2][3] = {0, };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int a,b,c;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> maze[0] >> maze[1] >> maze[2];
        min_ans[1][0] = min(min_ans[0][0]+maze[0], min_ans[0][1]+maze[0]);
        int minn = min(min_ans[0][0]+maze[1], min_ans[0][1]+maze[1]);
        min_ans[1][1] = min(minn, min_ans[0][2]+maze[1]);
        min_ans[1][2] = min(min_ans[0][1]+maze[2], min_ans[0][2]+maze[2]);
        for(int j =0; j<3; j++) min_ans[0][j] = min_ans[1][j];
        max_ans[1][0] = max(max_ans[0][0]+maze[0], max_ans[0][1]+maze[0]);
        int maxx = max(max_ans[0][0]+maze[1], max_ans[0][1]+maze[1]);
        max_ans[1][1] = max(maxx, max_ans[0][2]+maze[1]);
        max_ans[1][2] = max(max_ans[0][1]+maze[2], max_ans[0][2]+maze[2]);
        for(int j =0; j<3; j++) max_ans[0][j] = max_ans[1][j];
    }
    int maxx = 0;
    int minn = 1000000000;
    for(int i = 0; i<3; i++){
        maxx = max(max_ans[1][i],maxx);
        minn = min(min_ans[1][i],minn);
    }
    cout << maxx << " " << minn;
}