#include <iostream>
#include <queue>

using namespace std;

int tomato[1001][1001];
int visit[1001][1001] = {
	-1,
};
int m, n;
int adj[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int> > q;

int main()
{
	int err = -1;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tomato[i][j];
			visit[i][j] = 0;
			if (tomato[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visit[i][j] = 0;
			}
			if(tomato[i][j] != -1){
				err = 1;
			}
		}
	}
	if(err == -1){
		cout << -1 << '\n';
		return 0;
	}
	while (!q.empty())
	{
		int tmpX = q.front().first;
		int tmpY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int newX = tmpX + adj[i][0];
			int newY = tmpY + adj[i][1];
			if (newX >= 0 && newX < n && newY >= 0 && newY < m && tomato[newX][newY] == 0)
			{
				q.push(make_pair(newX, newY));
				if(visit[newX][newY] == 0) visit[newX][newY] = visit[tmpX][tmpY] + 1;
				else visit[newX][newY] = min(visit[tmpX][tmpY] + 1, visit[newX][newY]);
				tomato[newX][newY] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans = max(ans, visit[i][j]);
			//cout << visit[i][j] << " ";
			if (tomato[i][j] == 0)
			{
				cout << -1 << '\n';
				return 0;
			}
		}
		//cout<<endl;
	}

	cout << ans;
	return 0;
}
