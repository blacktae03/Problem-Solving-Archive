#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<pair<int, char>> s;
    pair<int, char> ptmp;
    int tmp = 0;
    int pval;
    bool yes = true;
    int sum = 0;
    string par;
    cin >> par;
    
    for (char c : par) {
        tmp = 0;
        
        if (c == '(' || c == '[') {
            if (c == '(') pval = 2;
            else {
                pval = 3;
            }
            
            if (!s.empty() && s.top().Y == '+') { // seg fault 가능성
                ptmp = {s.top().X, 'x'};
                s.pop();
                s.push(ptmp);
            }
            
            s.push({pval, '+'});
        }
        
        else {
            if (c == ')') {
                pval = 2;
            }
            else {
                pval = 3;
            }
            
            if (s.empty()) {
                yes = false;
                break;
            }
            
            while (!s.empty() && s.top().Y == '=') {
                tmp += s.top().X;
                s.pop();
                //cout << "aa";
            }
            
            if (s.empty()) {
                //cout << "dd";
                yes = false;
                break;
            }
            
            if (s.top().X != pval) {
                yes = false;
                break;
            }
            
            else {
                if (s.top().Y == '+') {
                    ptmp = {s.top().X, '='};
                    s.pop();
                    if (s.empty()) sum += ptmp.X;
                    else {
                        s.push(ptmp);
                    }
                }
                
                else if (s.top().Y == 'x') {
                    ptmp = {tmp*s.top().X, '='};
                    s.pop();
                    if (s.empty()) {
                        sum += ptmp.X;
                    }
                    else {
                        s.push(ptmp);
                    }
                }
            }
        }
        
    }
    
    if (!yes) cout << 0;
    else if (!s.empty()) cout << 0;
    else cout << sum;
}