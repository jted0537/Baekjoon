#include <iostream>

using namespace std;

int wood[501][501];
int n, m;
int row_max[501];
int col_max[501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int flag = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> wood[i][j];
        }
    }
    for(int i = 0; i<m; i++) cin >> col_max[i];
    for(int j = n-1; j>=0; j--) cin >> row_max[j];

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(wood[i][j] != 0) wood[i][j] = min(col_max[j], row_max[i]);
        }
    }

    for(int i = 0; i<n; i++) {
        int buf = -1;
        for(int j = 0; j<m; j++){
            buf = max(buf, wood[i][j]);
        }
        if(buf != row_max[i]) flag = 1;
    }
    for(int i = 0; i<m; i++) {
        int buf = -1;
        for(int j = 0; j<n; j++) {
            buf = max(buf, wood[j][i]);
        }
        if(buf != col_max[i]) flag = 1;
    }

    if(flag == 1) cout << "-1" << "\n";
    else{
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) cout << wood[i][j] << " ";
            cout << "\n";
        }
    }
}