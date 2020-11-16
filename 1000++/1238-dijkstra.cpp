#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

#define MAX 987654321

using namespace std;
vector <pair<int, int> > a[1001];
int weight[1001][1001];
int n, m, x;
void dijkstra(int start, int weight[]) {
	weight[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int curr = pq.top().first;
		int dis = -pq.top().second;
		pq.pop();
		if (weight[curr] < dis) continue;
		for (int i = 0; i < a[curr].size(); i++) {
			int next = a[curr][i].first;
			int next_dis = dis + a[curr][i].second;
			if (next_dis < weight[next]) {
				weight[next] = next_dis;
				pq.push(make_pair(next, -next_dis));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int buf1, buf2, buf3;
	int ans = 0;
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		cin >> buf1 >> buf2 >> buf3;
		a[buf1].push_back(make_pair(buf2, buf3));
	}
    memset(weight, MAX, sizeof(weight));
	for(int i =1; i<=n; i++){
        dijkstra(i,weight[i]);
    }
    for(int i = 1; i<=n; i++){
        if(i==x) continue;
        weight[x][i] += weight[i][x];
    }
	for (int i = 1; i <= n; i++) {
		ans = max(ans, weight[x][i]);
	}
	cout << ans;
}