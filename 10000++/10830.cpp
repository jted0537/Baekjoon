#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int mat[5][5] = {0, };
int mat_val[41][5][5];
vector<int> v1;

int n;
void cal(int a[5][5], int b[5][5], int m){
    int new_mat[5][5] = {0, };
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                new_mat[i][j] += a[i][k] * b[k][j];
                new_mat[i][j]%=1000;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            mat_val[m][i][j] = new_mat[i][j];
        }
    }
}
void make_digit(long long b){
    while(b!=0){
        v1.push_back(b%2);
        b/=2;
    }
}
void set_buf(int a[5][5]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i==j) a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans[5][5] = {0, };
    int buf[5][5] = {0, };
    long long b;
    bool flag = false;
    cin >> n >> b;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> mat[i][j];
            mat_val[0][i][j] = mat[i][j];
        }
    }
    make_digit(b);
    for(int i = 1; i<v1.size(); i++){
        cal(mat_val[i-1], mat_val[i-1], i);
    }
    set_buf(ans);
    for(int i = 0; i<v1.size(); i++) {
        if(v1[i] == 1){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    for(int l = 0; l<n; l++){
                        buf[j][k] += ans[j][l] * mat_val[i][l][k];
                        buf[j][k]%=1000;
                    }
                }
            }
            for(int m = 0; m<n; m++){
                for(int j = 0; j<n; j++){
                    ans[m][j] = buf[m][j];
                }
            }
            memset(buf, 0, sizeof(buf));
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}