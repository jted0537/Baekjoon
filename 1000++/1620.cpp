#include<iostream>
#include<map>
#include<string>

using namespace std;
int n,m;
map <string, int> m1;
string list[100003];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        m1.insert(make_pair(s,i));
        list[i] = s;
    }
    while(m--){
        string s;
        cin >> s;
        if((s[0]-'0')>=1 && (s[0]-'0')<=9){
            int a = stoi(s);
            cout << list[a] << '\n';
        }
        else{
            string s1 = s;
            cout << m1[s1] << '\n';
        }
    }
}
