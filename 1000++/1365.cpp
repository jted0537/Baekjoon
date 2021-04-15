#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 987654321

int N;
int line[100001];
int buf;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i<N; i++) {
        cin >> line[i];
    }
    v.push_back(-INF);
    for(int i = 0; i<N; i++) {
        buf = line[i];
        
        if(v.back() < buf) {
            v.push_back(buf);
        }
        else {
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), buf);
            *it = buf;
        }
    }
    cout << N - v.size()+1 << endl;
}
