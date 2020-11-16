#include<iostream>
#include<queue>
using namespace std;

int n,k;
queue <pair<int, int> >q1;
bool visited[100001] = {false, };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    q1.push(make_pair(n,0));
    visited[n] = true;
    int ans = 0;
    int count = 0;
    bool flag = false;
    while(!q1.empty()){
        int curr = q1.front().first;
        int weight = q1.front().second;
        visited[curr] = true;
        q1.pop();
        if(flag && curr == k && weight == ans) count++;
        if(!flag && curr == k) {
            ans = weight;
            flag = true;
            count++;
        }
        if(curr+1<100001 && !visited[curr+1]){
            q1.push(make_pair(curr+1,weight+1));
        }
        if(curr-1>=0 && !visited[curr-1]){
            q1.push(make_pair(curr-1,weight+1));
        }
        if(curr*2<100001 && !visited[curr*2]){
            q1.push(make_pair(curr*2,weight+1));
        }
    }
    cout << ans << "\n";
    cout << count;
}