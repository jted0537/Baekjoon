#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 100000001

int n, m;
int weight[1001] = {0, };
vector <pair<int, int> > v1[101];
vector <int> ans[1001];
priority_queue <pair<pair<int,int>, vector<int> > > pq;
vector<int> v2;
void dijkstra(int start){
    weight[start] = 0;
    v2.push_back(start);
    pq.push(make_pair(make_pair(0,start), v2));
    while(!pq.empty()){
        int curr = pq.top().first.second;
        int dis = -pq.top().first.first;
        vector <int> buf_v = pq.top().second;
        pq.pop();
        for(int i=0; i<v1[curr].size(); i++){
            int next = v1[curr][i].first;
            int next_dis = dis + v1[curr][i].second;
            if(weight[next] > next_dis){
                weight[next] = next_dis;
                buf_v.push_back(next);
                pq.push(make_pair(make_pair(-next_dis, next), buf_v));
                ans[next] = buf_v;
                buf_v.pop_back();
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> m;
    int buf1, buf2, buf3;
    int start, end;
    fill(&weight[0], &weight[1000], INF);
    for(int i = 0; i<m; i++){
        cin >> buf1 >> buf2 >> buf3;
        v1[buf1].push_back(make_pair(buf2,buf3));
    }
    cin >> start >> end;
    dijkstra(start);
     
    cout << weight[end] << "\n";
    cout << ans[end].size() << "\n";
    for(int i = 0; i<ans[end].size(); i++) cout << ans[end][i] << " ";
}