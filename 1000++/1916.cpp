#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
vector <pair<int, int> > v1[1001];
int weight[1001] = {0, };

void dijkstra(int start){
    weight[start] = 0;
    priority_queue <pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int curr = pq.top().second;
        int dis = -pq.top().first;
        pq.pop();
        if(weight[curr] < dis) continue;
        for(int i = 0; i<v1[curr].size(); i++){
            int next = v1[curr][i].first;
            int next_dis = dis + v1[curr][i].second;
            if(weight[next] > next_dis){
                weight[next] = next_dis;
                pq.push(make_pair(-next_dis, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c;
    int start, end;
    cin >> n;
    cin >> m;
    memset(weight, 0x3f, sizeof(weight));
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        v1[a].push_back(make_pair(b,c));
    }
    cin >> start >> end;
    dijkstra(start);
    cout << weight[end];
}