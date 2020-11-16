#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<string,pair<int,int> > a,pair<string,pair<int,int> > b ){
    if(a.second.first == b.second.first) 
        return a.second.second > b.second.second;
    else
    {
        return a.second.first > b.second.first;
    }
    
}

int main(){
    vector<pair<string, pair<int, int> > > v;
    v.push_back(make_pair("정", make_pair(95, 1995)));
    v.push_back(make_pair("동", make_pair(92, 1994)));
    v.push_back(make_pair("혁", make_pair(92, 1996)));
    v.push_back(make_pair("동", make_pair(94, 1997)));
    v.push_back(make_pair("동", make_pair(93, 1997)));
    sort(v.begin(),v.end(),compare);
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
    }
}

