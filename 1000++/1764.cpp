#include<iostream>
#include<string>
#include<set>
#include<algorithm>

using namespace std;
string alpha[500001];
int n,m;
set <string> m1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        m1.insert(s);
    }
    int k =0;
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        set<string>::iterator iter;
        iter = m1.find(s);
        if(iter!=m1.end()){
            alpha[k] = s;
            k++;
        }
        
    }
    sort(alpha, alpha+k);
    cout<< k<<'\n';
    for(int i=0; i<k; i++){
        cout<<alpha[i]<<'\n';
    }
    return 0;
}