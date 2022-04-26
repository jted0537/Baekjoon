#include<iostream>
#include<map>
#include<string>
using namespace std;


int n, m;
long long num;
map<string, int> m1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        m1[to_string(num)] = 1;
    }

    cin >> m;
    for(int j = 0; j < m; j++) {
        cin >> num;
        cout << m1[to_string(num)] << "\n";
    }
    return 0;
}
// map으로도 이분탐색으로도 가능