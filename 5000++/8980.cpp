#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, c;
int m;
int box[2001] = {0, };

vector<pair<pair<int, int>, int> > v;

int maxx(int a, int b){
    if (a>b) return a;
    else return b;
}

int minn(int a, int b){
    if(a>b) return b;
    else return a;
}

bool compare1(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if(a.first.second == b.first.second){
        return a.first.first < b.first.first;
    }
    return a.first.second < b.first.second;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int result = 0;
    cin >> n >> c;
    cin >> m;
    for(int i = 0; i<m; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        v.push_back(make_pair(make_pair(start, end), weight));
    }

    sort(v.begin(), v.end(), compare1);

    for(int i = 0; i<m; i++){
        int buf = 0;
        
        for(int j = v[i].first.first; j<v[i].first.second; j++){
            buf = maxx(box[j], buf);
        }

        int space = minn(c-buf, v[i].second);
        result += space;

        for(int j = v[i].first.first; j<v[i].first.second; j++){
            box[j] += space;
        }
    }

    cout << result;
}