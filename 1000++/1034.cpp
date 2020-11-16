#include <iostream>
#include <queue>
#include <string>

using namespace std; 

int n, m;
string desk[51];
int k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> desk[i];
    }
    cin >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int ans=0;
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (desk[i][j] == '0')
                count++;
        }
        if (count <= k && count % 2 == k % 2)
        {

            for (int j = i; j < n; j++)
            {
                if (desk[i] == desk[j])
                    ans++;
            }
            cnt = max(cnt, ans);
        }
    }
    cout << cnt;
}