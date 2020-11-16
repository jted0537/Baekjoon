#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int weight[2][100001] = {0, };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, col;
    cin >> n;
    while(n--){
        cin >> col;
        for(int i = 0; i<2; i++){
            for(int j = 0; j<col; j++){
                cin >> weight[i][j];
            }
        }
        weight[0][1] = weight[0][1] + weight[1][0];
        weight[1][1] = weight[1][1] + weight[0][0];
        for(int i = 2; i<col; i++){
            weight[0][i] = max(weight[1][i-1]+weight[0][i], weight[1][i-2]+weight[0][i]);
            weight[1][i] = max(weight[0][i-1]+weight[1][i], weight[0][i-2]+weight[1][i]);
        }
        cout<< max(weight[0][col-1],weight[1][col-1]) << "\n";
    }
}