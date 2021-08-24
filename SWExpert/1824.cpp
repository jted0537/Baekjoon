#include<iostream>

using namespace std;

char map[21][21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int mem = 0;
    int n;
    int r,c;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> r >> c;
        for(int j = 0; j<r; j++) {
            for(int k = 0; k<c; k++) cin >> map[j][k];
        }
        
        cout << "#" << i+1 << " " << "ans" << "\n";
    }
}