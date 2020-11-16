#include<iostream>

using namespace std;

int n;
int ans[1001] = {0, };
int arr[1001] = {0, };
int maxi = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++) ans[i] = 1;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 1; i<n; i++){
        int al = arr[i];
        for(int j = 0; j<i; j++){
            if(arr[j] < al && ans[i] < ans[j]+1) ans[i] = ans[j]+1;
        }
    }
    for(int i = 0; i<n; i++) maxi = max(maxi, ans[i]);
    cout << maxi;
}