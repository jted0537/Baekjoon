#include<iostream>

using namespace std;
#define ma 10000
int alpha[ma];

int main(){
    for(int i=2; i<ma; i++){
        alpha[i] = i;
    }
    for(int i=2; i<ma; i++){
        for(int j = i+i; j<ma; j+=i){
            alpha[j] = 0;
        }
    }
    for(int i=2; i<ma; i++){
        if(alpha[i]!=0) cout << alpha[i] << " ";
    }
}