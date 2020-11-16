#include<iostream>
#include<cmath>

using namespace std;
long long z(int n,long long c, long long r);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long r, c;
    cin >> n >> r >> c;
    cout << z(n,r,c);
    return 0;
}

long long z(int n, long long y, long long x){
    long long adder = 0;
    if(n==1){
        if(x==1)
            adder++;
        if(y==1)
            adder+=2;
        return adder;
    }
    if(x>=pow(2,n-1)){
        adder += pow(4,n-1);
        x -= pow(2,n-1);
    }
    if(y>=pow(2,n-1)){
        adder += pow(2,2*n-1);
        y -= pow(2,n-1);
    }
    return adder + z(n-1,y,x);
}