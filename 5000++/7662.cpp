#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int MAX = 1000001;
bool visited[MAX] = {false, };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int data;
    char c;
    int d;
    cin >> n;
    while(n--){
        cin >> data;
        priority_queue <pair<int, int>, vector <pair<int, int> >, greater<pair<int, int> > > minH;
        priority_queue <pair<int, int>, vector <pair<int, int> >, less <pair <int, int> > > maxH;
        for(int i=0; i<data; i++){
            cin >> c >> d;
            if(c=='I'){
                minH.push(make_pair(d,i));
                maxH.push(make_pair(d,i));
                visited[i] = true;
            }
            else if(c=='D'){
                if(d == 1){
                    while(!maxH.empty() && !visited[maxH.top().second]) maxH.pop(); //다 제거해주지 않아도 위에있는놈인데 제거된놈이면 없애주는 작업
                    if(!maxH.empty()){
                        visited[maxH.top().second] = false;
                        maxH.pop();                 
                    }
                }
                else{
                    while(!minH.empty() && !visited[minH.top().second]) minH.pop();
                    if(!minH.empty()){
                        visited[minH.top().second] = false;
                        minH.pop();
                    }
                }
            }
        }
        while(!maxH.empty() && !visited[maxH.top().second]) maxH.pop();
        while(!minH.empty() && !visited[minH.top().second]) minH.pop();
        if(minH.empty() && maxH.empty()){
            cout << "EMPTY" << '\n';
        }
        else{
            cout << maxH.top().first << " " << minH.top().first << '\n';
        }
    }
}