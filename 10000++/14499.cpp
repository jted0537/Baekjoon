#include<iostream>
using namespace std;

int N, M;
int r,c;
int K;

int map[21][21];
int cmd[1001];
int dice[7] = {0, };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> r >> c >> K;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i<K; i++){
        cin>>cmd[i];
    }

    for(int i = 0; i<K; i++){
        if(cmd[i] == 1){
            c++;
            if(r < 0 || c < 0 || r>N-1 || c> M-1) {
                c--;
                continue;
            }
            
            int tmp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = tmp;
            if(map[r][c] == 0) {
                map[r][c] = dice[1];
            }
            else{
                dice[1] = map[r][c];
                map[r][c] = 0;
            }
        } 
        else if(cmd[i] == 2){
            c--;
            if(r < 0 || c < 0 || r>N-1 || c> M-1) {
                c++;
                continue;
            }
            int tmp = dice[6];
            dice[6] = dice[3];
            dice[3] = dice[1];
            dice[1] = dice[4];
            dice[4] = tmp;
            if(map[r][c] == 0) {
                map[r][c] = dice[1];
            }
            else{
                dice[1] = map[r][c];
                map[r][c] = 0;
            }
            
        }
        else if(cmd[i] == 3){
            r--;
            if(r < 0 || c < 0 || r>N-1 || c> M-1) {
                r++;   
                continue;
            }
            int tmp = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = dice[1];
            dice[1] = tmp;
            if(map[r][c] == 0) {
                map[r][c] = dice[1];
            }
            else{
                dice[1] = map[r][c];
                map[r][c] = 0;
            }
        }
        else {
            r++;
            if(r < 0 || c < 0 || r>N-1 || c> M-1) {
                r--;
                continue;
            }
            int tmp = dice[2];
            dice[2] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = tmp;
            if(map[r][c] == 0) {
                map[r][c] = dice[1];
            }
            else{
                dice[1] = map[r][c];
                map[r][c] = 0;
            }
        }
        
        cout << dice[6] << endl;
    }
}