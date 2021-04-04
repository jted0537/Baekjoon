#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<pair<int, int> > h;
vector<pair<int, int> > c;
vector<pair<int, int> > c_remove;
bool selecte[13];
int ans = 987654321;

int abs(int a) {
    if (a<0) return -a;
    else return a;
}

int cal(void){
    int sum = 0;
    for(int i = 0; i< h.size(); i++){
        int min_v = 987654321;
        int x = h[i].first;
        int y = h[i].second;
        for(int j = 0; j<c_remove.size(); j++){
            int c_x = c_remove[j].first;
            int c_y = c_remove[j].second;
            
            int dis = abs(c_x-x) + abs(c_y-y);
            min_v = min(min_v, dis);
        }
        sum+=min_v;
    }
    return sum;
}

void jo(int idx, int cnt ) {
    if(cnt == m ) {
        ans = min(ans, cal());
        return;
    }
    for(int i = idx; i<c.size(); i++){
        if(selecte[i] == true) continue;
        selecte[i] = true;
        c_remove.push_back(c[i]);
        jo(i, cnt+1);
        c_remove.pop_back();
        selecte[i] = false;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) {
            int r;
            cin >> r;
            if(r == 1) h.push_back(make_pair(i,j));
            else if(r==2) c.push_back(make_pair(i, j));
        }
    }

    jo(0, 0);
    cout << ans;
    return 0;
}