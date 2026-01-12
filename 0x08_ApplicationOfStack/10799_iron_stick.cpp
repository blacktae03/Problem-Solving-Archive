#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string iron;
    stack<int> s;
    int cnt = 0;
    
    s.push(0);

    cin >> iron;

    for (char c : iron) {
        if (c == '(') {
            if (s.top() == -1) {
                s.pop();
                s.push(s.top()+1);
            }
            s.push(-1);
        }

        else {
            if (s.top() == -1) {
                s.pop();
                cnt += s.top();
            }

        }
    }
}