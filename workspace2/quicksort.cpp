#include<iostream>

using namespace std;
int a[10] = {3,8,1,7,2,9,4,5,0,6};
void quicksort(int *data, int start, int end);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    quicksort(a,0,9);
    for(int i=0; i<10; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

void quicksort(int *data, int start, int end){
    if(end<=start) return;
    int key = start;
    int i = start+1;
    int j = end;
    int temp;
    while(i<=j){ 
        while(data[key] <= data[i]) i++;
        while(data[key] >= data[j] && j >start) j--;
        if(j<i){
            temp = data[key];
            data[key] = data[j];
            data[j] = temp;
        }
        else{
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    quicksort(data,start,j-1);
    quicksort(data,j+1,end);
}