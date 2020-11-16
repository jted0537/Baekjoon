#include<iostream>

using namespace std;

int in_order[100001];
int post_order[100001];

void order(int il, int ir, int pl, int pr){
    int root = post_order[pr];
    int i;
    if(il>ir || pl>pr) return;
    cout << root << " ";
    for(i = il; in_order[i]!=root; i++);
    order(il,i-1,pl,pl+(i-il)-1);
    order(i+1,ir,pl+(i-il),pr-1);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> in_order[i];
    for(int i = 0; i<n; i++) cin >> post_order[i];
    int root = post_order[n-1];
    order(0,n-1,0,n-1);
}