#include<iostream>
#include<string>
#include<vector>
using namespace std;

string solution(string sentence, string word, vector<int> v1) {
    string answer;
    int s_i = 0;
    int w_i = 0;
    int j = 0;
    for(int i = 0; i<v1.size(); i++) {
        int tab = v1[i];
        for(j = 0; j<tab; j++) {
            if(s_i >= sentence.size()) return answer;
            if(sentence[s_i] == word[w_i]) {
                break;
            } 
            answer.push_back(sentence[s_i++]);
        }
        answer.push_back(word[w_i]);
        w_i++;
        if(w_i == word.size()) w_i = 0;
        cout << j << tab << "\n";
        for(;j<tab; j++) {
            if(s_i >= sentence.size()) return answer;
            answer.push_back(sentence[s_i++]);
        }
    }
    for(; s_i<sentence.size(); s_i++) answer.push_back(sentence[s_i]);
    return answer;
}

int main() {
    string sentence = "abcde fghi", word = "xyz";
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(0);
    v1.push_back(1);
    //v1.push_back(3);
    // v1.push_back(2);
    // v1.push_back(3);
    // v1.push_back(4);
    cout << solution(sentence, word, v1) << "\n";
}
