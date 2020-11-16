#include<iostream>

using namespace std;
void divide(int size, int start_x, int start_y);
int n;
int al[128][128];
int bluecl = 0;
int whitecl = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> al[i][j];
        }
    }
    divide(n,0,0);
    cout << whitecl <<'\n' << bluecl <<'\n';
}

void divide(int size, int start_x, int start_y){
    int cnt =0;
    if(size == 1){
        if(al[start_x][start_y]==1) bluecl++;
        else whitecl++;
    }
    else{
        for(int i=start_x; i<start_x+size; i++){
            for(int j=start_y; j<start_y+size; j++){
                if(al[i][j]) cnt++;
            }
        }
        if(cnt == 0) whitecl++;
        else if(cnt == size*size )bluecl++;
        else{
            divide(size/2, start_x, start_y);
            divide(size/2, start_x+size/2, start_y);
            divide(size/2, start_x, start_y+size/2);
            divide(size/2, start_x+size/2, start_y+size/2);
        }
    }
}
