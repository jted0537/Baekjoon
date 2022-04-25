#include<iostream>
#include<string>
#include<set>

using namespace std;

int n, m;
string arr[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<string> s;
    int start = 1;
    int end = n;
    while(start <= end) {
        bool is_ok = true;
        int mid = (start + end) / 2;
        for(int j = 0; j < m; j++) {
            string str = "";
            for(int k = mid; k < n; k++) {
                str += arr[k][j];
            }
            if(s.count(str) == 0) {
                s.insert(str);
            } 
            else {
                is_ok = false;
                break;
            }
        }
        if(is_ok) start = mid + 1;
        else end = mid - 1;
    }

    cout << start - 1 << endl;

    return 0;
}