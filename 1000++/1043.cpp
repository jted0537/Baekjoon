#include<iostream>
#include<vector>
using namespace std;
int n,m;
int tr_people;
vector<int> truth[51];
int a[51] = {0, };
int getParent(int parent[], int x){
    if(parent[x] == x) return x;
    else return parent[x] = getParent(parent, parent[x]);
}
void unionParent(int parent[], int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);
    if(x<y) parent[y] = x;
    else parent[x] = y;
}
bool findParent(int parent[], int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);
    if(x==y) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tr_num;
    int num;
    int x;
    cin >> n >> m;
    cin >> tr_num;
    int ans = m;
    for(int i = 0; i<=n; i++) a[i] = i;
    for(int i = 0; i<tr_num; i++){ 
        cin >> tr_people;
        unionParent(a,0,tr_people);
    } 
    for(int i = 1; i<=m; i++){ 
        cin >> num;
        for(int j = 0; j<num; j++){
            cin >> x;
            truth[i].push_back(x);
        }
        for(int k = 1; k<truth[i].size(); k++) unionParent(a,truth[i][k],truth[i][0]); 
    }
    for(int i = 1; i<=m; i++){
        for(int j = 0; j<truth[i].size(); j++){
            if(findParent(a,0,truth[i][j])){
                ans--;
                break;
            }
        }
    }
    cout << ans << "\n";
}