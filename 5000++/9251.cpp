#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str1;
string str2;
int dp[1001][1001] = {0, };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int new_i = 0;
    int new_j = 0;
    cin >> str1 >> str2;
    if(str1.length() < str2.length()){
        string tmp = str1;
        str1 = str2;
        str2 = tmp;
    }
    for(int i = 0; i<str1.length(); i++){
        for(int j = 0; j<str2.length(); j++){
            if(str1[i] == str2[j]){
                dp[j+1][i+1] = dp[j][i]+1;
            }
            else{
                dp[j+1][i+1] = max(dp[j][i+1], dp[j+1][i]);
            }
        }
    }
    cout << dp[str2.length()][str1.length()];
}