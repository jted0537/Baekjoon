#include<iostream>
#include<vector>
#include<cstring>
#define INF 1000000000
using namespace std;

int n, m;
long long weight[501];
vector <pair<int, int> > v1[501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	bool flag = false;
	cin >> n >> m;
    fill(weight, weight+n+1,INF);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v1[a].push_back(make_pair(b, c));
	}
	weight[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < v1[j].size(); k++) {
				int next = v1[j][k].first;
				int dis = v1[j][k].second;
				if (weight[j]!= INF && weight[next] > dis + weight[j]) {
					weight[next] = dis + weight[j];
					if (i == n) {
						flag = true;
					}
				}
			}
		}
	}
	if (flag) cout << "-1\n";
	else {
		for (int i = 2; i <= n; i++) {
			if (weight[i] == INF) cout << "-1\n";
			else cout << weight[i] << "\n";
		}
	}
}