#include<iostream>

using namespace std;
#define MAX 1000000007
long long ar[2][1000001];
int dp(int x){
    for(int i=3; i<=x; i++){
        ar[1][i] = ar[1][i-1] + ar[0][i-3];
        ar[0][i] = (ar[0][i-1]*2 + ar[0][i-2]*3 + 2*ar[1][i])%MAX;
    }
    return ar[0][x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    cin >> x;
    ar[0][0] = 1;
    ar[0][1] = 2;
    ar[0][2] = 7;
    ar[1][2] = 0 ;
    int a = dp(x);
    cout << a << endl;
}