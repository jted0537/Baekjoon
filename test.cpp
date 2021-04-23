#include<iostream>
#include<map>
#include<set>
#include<queue>

using namespace std;
priority_queue<pair<int, int> > pq;
set<int> s;
int main() {
    map<string, int> m1;
    m1.insert(make_pair("aa", 190232));
    m1["aa"] = 3;
    m1["ab"] = 4;
    m1["ac"] = 5;
    map<string, int>::iterator iter = m1.begin();
    for(; iter != m1.end(); iter++) {
        cout << iter->first << iter->second << "\n";
    }
    string a;
    
}