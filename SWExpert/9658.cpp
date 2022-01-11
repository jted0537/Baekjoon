#include<iostream>
#include<string>

using namespace std;

int tc;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        cin >> str;
        char c1 = str[0];
        char c2 = str[1];
        char c3 = str[2];
        double ans = c1 - '0';
        int double_cnt = 0;
        ans += (double)(c2 - '0') / 10.0;
        if(c3 -'0' >= 5) ans += 0.1;
        if(ans >= 10.0) double_cnt++, ans/=10;
        double_cnt += (str.length() - 1);
        
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << "#" << i+1 << " " << ans << "*10^" << double_cnt << endl;
    }
    return 0;
}