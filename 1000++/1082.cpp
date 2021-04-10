#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int price[10];
int num[100];
vector<pair<int, int> > v,v2;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int total, minn = 0;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> price[i];
        v.push_back(make_pair(price[i], i));
        if(i>0) v2.push_back(make_pair(price[i],i));
    }
    cin >> total;
    sort(v.begin(), v.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);

    if(N == 1) {
            cout << "0" << endl;
            return 0;
    }

    if(v[0].second == v2[0].second){
        minn = total/v[0].first;
        total -= minn * v[0].first;
    }
    else {
        if(total - v[1].first < 0) {
            cout << "0" << endl;
            return 0;
        }
        else{
            minn = (total-v[1].first)/v[0].first;
            minn++;
            total -= v[1].first;
            total -= v[0].first*(minn-1);
        }
    }
    
    for(int i = 0; i<minn; i++){
        if(i==0) num[i] = v2[0].second;
        else num[i] =  v[0].second;
    }

    for(int i = 0; i<minn; i++){
        for(int j = N-1; j>num[i]; j--){
            if(total + (price[num[i]] - price[j]) >= 0) {
                total += (price[num[i]] - price[j]);
                num[i] = j;
                break;
            } 
        }
    }

    for(int i = 0; i<minn; i++) cout << num[i];
    return 0;
}