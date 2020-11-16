#include<iostream>

using namespace std;

long long a,b,c;

long long cal(int a, int b, int c){
    if(b==1){
        return a%c;
    }
    else if(b%2==0){
        return ((cal(a,b/2,c)%c) * (cal(a,b/2,c)%c))%c;
    }
    else{
        return ((((a%c) * (cal(a,(b-1)/2,c)%c))%c) * (cal(a,(b-1)/2,c)%c))%c;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    long long ld = cal(a,b,c);
    cout << ld;
}
