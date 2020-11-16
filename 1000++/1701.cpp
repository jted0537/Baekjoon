#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int maxx = 0;
    cin >> str;
    int len = str.length();
    for(int k =0; k<len; k++){
        string tmp = str.substr(k);
        //cout << tmp << endl;
        vector<int> v1(tmp.length()+1,0);
        int j = 0;
        for(int i=1; i<tmp.length(); i++){
            while(j>0 && tmp[i]!=tmp[j]) j = v1[j-1];
            if(tmp[i] == tmp[j]){
                 v1[i] = ++j;
                 maxx = max(maxx,v1[i]);
            }
        }
    }
    cout << maxx;
}