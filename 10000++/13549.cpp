#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<pair<int, int> > q1;
bool visited[100001] = {false, };
int n,k;
vector <int> v1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int ans = 0;
    q1.push(make_pair(n,0));
    visited[n] = true;
    while(!q1.empty()){
        int curr = q1.front().first;
        int weight = q1.front().second;
        if(curr == k) v1.push_back(weight);
        q1.pop();
        if(curr*2<=100000 && !visited[curr*2]){
            q1.push(make_pair(curr*2, weight));
            visited[curr*2] = true;
        }
        if(curr-1>=0 && !visited[curr-1]){
            q1.push(make_pair(curr-1, weight+1));
            visited[curr-1] = true;
        }
        if(curr+1<=100000 && !visited[curr+1]){
            q1.push(make_pair(curr+1, weight+1));
            visited[curr+1] = true;
        }
    }
    int minn = 987654321;
    for(int i = 0; i<v1.size(); i++) minn = min(v1[i], minn);
    cout << minn << "\n";
}