 #include<iostream>

using namespace std;
int a[10] = {3,8,1,7,2,9,4,5,0,6};
int main(){
    //힙을 구성
    int number = 10;
    for(int i=1; i<number; i++){
        int c = i;
        do{
            int root = (c-1)/2;
            if(a[root] > a[c]){
                int tmp = a[root];
                a[root] = a[c];
                a[c] = tmp;
            }
            c = root;
        }while(c!=0);
    }
    for(int i = number-1; i>=0; i--){
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        int root = 0;
        int c = 1;
        do{
            c = root*2 + 1;
            if(a[c] > a[c+1] && c<i-1) c++;
            if(a[c] < a[root] && c<i){
                tmp = a[root];
                a[root] = a[c];
                a[c] = tmp;
            }
            root = c;
        }while(c<i);
    }
    for(int i=0; i<number; i++){
        cout << a[i] << " ";
    }
}
