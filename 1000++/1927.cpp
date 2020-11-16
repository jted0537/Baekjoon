#include<iostream>
#include<queue>

using namespace std;
priority_queue<int , vector<int>, greater<int> > q;

int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(n--){
        long long al;
        cin >> al;
        if(al != 0){
            q.push(al);
        }
        else {
            if(!q.empty()){
                cout << q.top() << '\n';
                q.pop();
            }
            else
            {
                cout << 0 << '\n';
            }     
        }
    }
    return 0;
}