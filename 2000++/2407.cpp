#include<iostream>

using namespace std;
unsigned long long ans = 1;
bool use[101] = {false, };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    if(n-m < m) m = n-m;
    int time = n+1;
    for(int i = 2; i<=m; i++) use[i] = true;
    while(time--){
        if(time==n-m) break;
        ans*=time;
        for(int i = 2; i<=m; i++){
            if(use[i] && ans%i==0) {
                ans/=i;
                use[i] = false;
            }
        }
    }
    cout << ans << "\n";
}