#include<iostream>
#include<string>
#include<map>
using namespace std;


int t, relation, node;
string s1, s2;
int parent[200002];
int size_l[200002];


int find_parent(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
    int a_parent = find_parent(a);
    int b_parent = find_parent(b);

    if(a_parent != b_parent) {
        if(size_l[a_parent] < size_l[b_parent]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        size_l[a_parent] += size_l[b_parent];
        parent[b_parent] = a_parent;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> relation;
        for(int j = 0; j < 200002; j++) {
            size_l[j] = 1;
            parent[j] = j;
        }
        map<string, int> m1;
        node = 1;
        for(int j = 0; j < relation; j++) {
            cin >> s1 >> s2;

            if(m1.count(s1) == 0) m1[s1] = node++;
            if(m1.count(s2) == 0) m1[s2] = node++;

            union_parent(m1[s1], m1[s2]);

            cout << max(size_l[find_parent(m1[s1])], size_l[find_parent(m1[s2])]) << '\n';

        }
    }
    return 0;
}