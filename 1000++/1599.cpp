#include<iostream>
#include<algorithm>
using namespace std;

int n;

bool compare(string a, string b) {
    int a_idx = 0;
    int b_idx = 0;
    for(int i = 0; i<a.length(); i++) if(a[i] == 'n' && (i+1) < a.length() && a[i+1] == 'g') a[i] = 'z';
    for(int i = 0; i<b.length(); i++) if(b[i] == 'n' && (i+1) < b.length() && b[i+1] == 'g') b[i] = 'z';
    
    while(a_idx<a.length() && b_idx < b.length()){
        char a_temp = a[a_idx];
        char b_temp = b[b_idx];
        a_idx++, b_idx++;
        if(a_temp == 'z' && b_temp == 'z'){
            a_idx++, b_idx++;
            continue;
        }
        if(a_temp == 'z') {
            a_idx++;
            return 'n'+0.5 < b_temp;
        }
        if(b_temp == 'z') {
            b_idx++;
            return a_temp < 'n'+0.5;
        }
        if(a_temp == b_temp) continue;
        if(a_temp == 'k') return 'c' < b_temp;
        if(b_temp == 'k') return a_temp < 'c';
        return a_temp < b_temp;
    }
    return a.length() < b.length();
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    string str[1001];
    for(int i = 0; i<n; i++) cin >> str[i];
    sort(str, str+n, compare);
    for(int i = 0; i<n; i++) cout << str[i] << "\n";
}