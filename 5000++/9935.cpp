#include<iostream>
#include<string>
#include<vector>

using namespace std;
string str;
string pat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str;
    cin >> pat;
    for(int i = 0; i<str.length(); i++){
        if(str.substr(0,i) == pat) cout << pat;
    }
}