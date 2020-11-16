#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
 
int n, m, k;
long long init_tree(vector<long long> &tree, vector<long long> &arr,int start, int end, int root){
    int mid = (start+end)/2;
    if(start==end) return tree[root] = arr[start];
    else return tree[root] = init_tree(tree,arr,start,mid,root*2)+init_tree(tree,arr,mid+1,end,root*2+1);
}
void update(vector<long long> &tree, int root, int start, int end, int index, long long diff){
    if(start > index || end < index) return;
    tree[root]+=diff;
    if(start != end){
        update(tree, root*2, start, (start+end)/2, index, diff);
        update(tree, root*2+1, (start+end)/2+1, end, index, diff);
    }
}
long long get_sum(vector<long long> &tree, int root, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(start>=left && end<=right) return tree[root];
    int mid = (start+end)/2;
    return get_sum(tree, root*2, start, mid, left, right) + get_sum(tree, root*2+1, mid+1,end,left,right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin >> n >> m >> k;
    vector<long long> arr(n);
    int h = (int)ceil(log2(n));
    int size = (1 <<(h+1));
    int buf;
    vector<long long> tree(size);
    for(int i = 0; i<n; i++) cin >> arr[i];
    init_tree(tree, arr,0,n-1,1);
    for(int i = 0; i<m+k; i++){
        cin >> a;
        if(a==1){
            int b;
            long long c;
            cin >> b >> c;
            b-=1;
            long long dif = c-arr[b];
            arr[b] = c;
            update(tree, 1, 0, n-1, b, dif);
        }
        else if(a==2){
            int b,d;
            cin >> b >> d;
            cout << get_sum(tree, 1, 0, n-1, b-1, d-1) << "\n";
        }
    }
    return 0;
}