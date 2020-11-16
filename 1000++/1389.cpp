#include<iostream>

#include<queue>
using namespace std;
int n, m;

queue  <int>  q;
int relation[101][101] = { 0. };
int re[101];
int max1 = 987654;
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int bufx, bufy;
	for (int i = 0; i < m; i++) {
		cin >> bufx >> bufy;
		relation[bufx][bufy] = 1;
		relation[bufy][bufx] = 1;
	}
	for (int i = 1; i <= n; i++) {
		q.push(i);
		re[i] = 1;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int j = 1; j <= n; j++) {
				if (j == x) continue;
				else if (re[j] == 0 && relation[j][x] == 1) {
					q.push(j);
					re[j] = re[x] + 1;
				}
			}
		}
		int result=0;
		for (int j = 0; j < n; j++) {
			result += re[j];
		}
		if (result < max1) {
			max1 = result;
			ans = i;
		}
		memset(re, 0, sizeof(re));
	}
	cout << ans;

}
