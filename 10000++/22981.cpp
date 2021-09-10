#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long work[200001];
long long k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i<n; i++) cin >> work[i];
    sort(work, work + n);
    long long ans = 0;
    for(int i = 0; i<n-1; i++) {
        long long front = work[0] * (i+1);
        long long back = work[i+1] * (n-i-1);
        ans = max(ans, front+back);
    }
    
    if(k%ans==0) cout << k/ans << "\n";
    else cout << k/ans + 1 << "\n";
}