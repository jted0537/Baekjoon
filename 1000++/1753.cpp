#include<iostream>
#include<queue>
#include<vector>
#define MAX 987654321
using namespace std;

int v, e;
int a, b, d;
int start;
vector <pair<int, int> > v1[20001];
int weight[20001] = { MAX, };

void dijkstra(int start){
    weight[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(start,0));
    while(!pq.empty()){
        int curr = pq.top().first;
        int dis = -pq.top().second;
        pq.pop();
        if(weight[curr] < dis) continue;
        for(int i = 0; i<v1[curr].size(); i++){
            int next = v1[curr][i].first;
            int next_dis = v1[curr][i].second + dis;
            if(next_dis < weight[next]){
                weight[next] = next_dis;
                pq.push(make_pair(next, -next_dis));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e;
    cin >> start;
    fill(weight, weight+v+1, MAX);
    for(int i=0; i<e; i++){
        cin >> a >> b >> d;
        v1[a].push_back(make_pair(b,d));
    }
    //for(int i = 1; i<=v; i++) cout << weight[i] << " ";
    dijkstra(start);
    for(int i = 1; i <= v; i++){
        if(weight[i] == MAX) cout << "INF" << '\n';
        else cout << weight[i] << '\n';
    }
}