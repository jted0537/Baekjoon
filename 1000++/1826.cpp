#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, L, P;
int jungle[1000001] = {0, };
priority_queue<pair<int, int> > pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int loc, dis;
    int result = 0;
    int fuel, buf;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> loc >> dis;
        jungle[loc] = dis;
    }
    cin >> L >> P;
    fuel = P;

    for(int i = 1; i <= L; i++){
        if(jungle[i] != 0) {
            pq.push(make_pair(jungle[i], i));
        }
        fuel--;
        if(i == L && fuel ==0 ) break;
        if(fuel <= 0) {
            if(pq.empty()) {
                cout << "-1" << endl;
                return 0;
            }
            buf = pq.top().first;
            pq.pop();
            fuel += buf;
            result++;
        }
    }

    cout << result << endl;
    return 0;
}