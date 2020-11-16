#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[1001] = {0, };
int arr_max[1001] = {0, };
int arr_min[1001] = {0, };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int max_num = 0;
    if(n==1){
        cin >> max_num;
        cout << "1";
        return 0;
    }
    if(n==2){
        cin >> max_num >> max_num;
        cout << "2";
        return 0;
    }
    int loc;
    for(int i = 0; i<n; i++){ 
        cin >> arr[i];
        arr_max[i] = 1;
        arr_min[i] = 1;
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j] && arr_max[i] < arr_max[j]+1) arr_max[i] = arr_max[j]+1;
        }
    }
    for(int i = n-2; i>=0; i--){
        for(int j = n-1; j>i; j--){
            if(arr[i] > arr[j] && arr_min[i] < arr_min[j]+1) arr_min[i] = arr_min[j]+1;
        }
    }
    for(int i = 0; i<n; i++) max_num = max(arr_max[i]+arr_min[i], max_num);
    cout << max_num-1;
    return 0;
}