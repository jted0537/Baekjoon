#include<iostream>
#include<vector>

using namespace std;

int MAX, len;
int num[10] = {1,2,3,4,5,6,7,8,9,10};
bool selectee[10] = {false, };
vector <int> v1;
void se(int cnt){
    if(cnt == len) {
        for(int i = 0; i<v1.size(); i++){
            cout << v1[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i<MAX; i++){
        if(selectee[i]) continue;
        selectee[i] = true;
        v1.push_back(num[i]);
        se(cnt+1);
        v1.pop_back();
        selectee[i] = false;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> MAX >> len;
    se(0);
}