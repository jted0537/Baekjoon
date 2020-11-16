#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 8

class edit{
public: 
    int du[2];
    int dist;
    edit(int a1, int a2, int b){
        this->du[0] = a1;
        this->du[1] = a2;
        this->dist = b;
    }
    bool operator <(edit& e){
        return this->dist < e.dist;
    }//아게 잘 안먹는데 이유를 한번 살펴보자
};


int parent[SIZE+1];

int getParent(int parent[], int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a,int b){
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int checker(int parent[], int a, int b){
    a = getParent(parent,a);
    b = getParent(parent,b);
    if(a==b) return 1;
    else return 0;
}

bool compare(edit& e1, edit& e2){
    return e1.dist < e2.dist;
}
int main(){
    int sum = 0;
    vector<edit> v1;
    v1.push_back(edit(1,7,12));
    v1.push_back(edit(1,4,28));
    v1.push_back(edit(1,2,67));
    v1.push_back(edit(1,5,17));
    v1.push_back(edit(2,4,24));
    v1.push_back(edit(2,5,62));
    v1.push_back(edit(3,5,20));
    v1.push_back(edit(3,6,37));
    v1.push_back(edit(4,7,13));
    v1.push_back(edit(5,6,45));
    v1.push_back(edit(5,7,73));
    for(int i=1; i<=SIZE; i++){
        parent[i] = i;
    }
    sort(v1.begin(), v1.end(),compare);
    for(int i = 0; i<v1.size(); i++){
        if(!checker(parent,v1[i].du[0],v1[i].du[1])){ 
            sum+=v1[i].dist;
            unionParent(parent, v1[i].du[0], v1[i].du[1]);
        }
    }
    cout << sum << endl;
}   