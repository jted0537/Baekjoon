#include <iostream>
#include <vector>
using namespace std;

int n;
vector <int> v1;
int o[4];
int min_v = 1000000001;
int max_v = -1000000001;

void dfs(vector<int> num, int sum, int pl, int mi, int mu, int di, int cnt) {
    if(cnt == n) {
        max_v = max(max_v, sum);
        min_v = min(min_v, sum);
        return;
    }

    if(pl > 0) dfs(num, sum+num[cnt], pl-1, mi, mu, di, cnt+1);
    if(mi > 0) dfs(num, sum-num[cnt], pl, mi-1, mu, di, cnt+1);
    if(mu > 0) dfs(num, sum*num[cnt], pl, mi, mu-1, di, cnt+1);
    if(di > 0) dfs(num, sum/num[cnt], pl, mi, mu, di-1, cnt+1);

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i<n; i++) {
        int num;
        cin >> num;
        v1.push_back(num);
    }
    
    cin >> o[0] >> o[1] >> o[2] >> o[3];
    dfs(v1, v1[0], o[0], o[1], o[2], o[3], 1);
    cout <<  max_v <<  endl << min_v << endl;
    
}