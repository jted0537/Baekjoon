#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long v1[1000001] = {0, };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long minn, maxx;
    cin >> minn >> maxx;
    int cha = maxx-minn;
    int sum = 0;

    for(long long i = 2; i*i<=maxx; i++){
        long long x = minn/(i*i);
        if(minn%(i*i)!=0) x++;
        while(x*i*i <= maxx){
            v1[x*i*i-minn] = -1;
            x++;
        }
    }
    for(int i = 0; i<cha+1; i++){
        if(v1[i] != -1) sum++;
    }
    cout << sum;
}