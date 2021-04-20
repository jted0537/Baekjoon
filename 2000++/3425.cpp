#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;

vector<pair<string, long long> > cmd;
vector<long long> num;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str, buf;
    int n;
    long long m;
    int j;
    long long number;

    while(str != "QUIT") {
        vector<pair<string, long long> > cmd;
        vector<long long> num;
        while(buf != "END") {
            cin >> buf;
            if(buf == "QUIT") return 0;
            if(buf == "END") break;
            if(buf == "NUM") {
                cin >> number;
                cmd.push_back(make_pair(buf, number));
            }
            else cmd.push_back(make_pair(buf, 0));
        }
        cin >> n;
        for(int i = 0; i<n; i++) {
            cin >> m;
            num.push_back(m);
        }

        for(int i = 0; i<n; i++) {
            stack<long long> s;
            long long fir_num = num[i];
            s.push(fir_num);
            for(j = 0; j<cmd.size(); j++) {
                string cur_cmd = cmd[j].first;
                long long cur_num = cmd[j].second;
                if(cur_cmd == "NUM") s.push(cur_num);
                else if(cur_cmd == "POP") {
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    s.pop();
                }
                else if(cur_cmd == "INV") {
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    s.top() = -s.top();
                }
                else if(cur_cmd == "DUP") {
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    s.push(s.top());
                }
                else if(cur_cmd == "SWP") {
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    long long first = s.top();
                    s.pop();
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    long long second = s.top();
                    s.top() = first;
                    s.push(second);
                }
                else if(cur_cmd == "ADD") {
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    long long first = s.top();
                    s.pop();
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    s.top() += first;
                }
                else if(cur_cmd == "SUB") {
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    long long first = s.top();
                    s.pop();
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    s.top() -= first;
                }
                else if(cur_cmd == "MUL") {
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    long long first = s.top();
                    s.pop();
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    s.top() *= first;
                }
                else if(cur_cmd == "DIV") {
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    long long first = s.top();
                    s.pop();
                    if(s.empty() || first == 0) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    s.top() = s.top()/first;
                }
                else if(cur_cmd == "MOD") {
                    if(s.empty()) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    long long first = s.top();
                    s.pop();
                    if(s.empty() || first == 0) {
                        cout << "ERROR" << "\n";
                        break;
                    }
                    s.top() = s.top()%first;
                }

                if(!s.empty() && abs(s.top()) > 1000000000) {
                    cout << "ERROR" << "\n";
                    break;
                }
            }
            if(j == cmd.size()) {
                if(s.size() != 1) cout << "ERROR" << "\n";
                else cout << s.top() << "\n";
            }
            
        }
        cout << "\n";
        str = "";
        buf = "";
    }

}