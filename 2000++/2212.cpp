#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, K;
vector<int> v;
vector<int> v2;




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int result = 0;

    cin >> N >> K;
    for(int i = 0; i<N; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i<N-1; i++){
        v2.push_back(v[i+1]-v[i]);
    }

    sort(v2.begin(), v2.end(), less<int>());

    for(int i = 0; i<N-K; i++){
        result += v2[i];
    }

    cout << result;

}