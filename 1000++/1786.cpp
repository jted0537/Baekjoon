#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector <int> ans;
int cl = 0;
vector<int> makeTable(string pattern){
    int patternsize = pattern.size();
    vector<int> table(patternsize,0);
    int j = 0;
    for(int i = 1; i<patternsize; i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

void kmp(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parentsize = parent.size();
    int patternsize = pattern.size();
    int j = 0;
    for(int i = 0; i<parentsize; i++){
        while(j>0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == patternsize-1){
                cl++;
                ans.push_back(i-patternsize+2);
                j = table[j];//위치 i-pattern+2
            }
            else j++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string t, p;
    getline(cin, t);
    getline(cin, p);
    kmp(t,p);
    cout << cl <<'\n';
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << '\n';
}