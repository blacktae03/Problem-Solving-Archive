#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool yes = true;
    string s = "";
    stack<int> blnc;

    while (true) {
        yes = true;
        getline(cin, s);

        if (s == ".") break;

        for (char c : s) {
            if (c == '(') { 
                blnc.push(1);
            }

            else if (c == '[') {
                blnc.push(2);
            }

            else if (c == ')') {
                if(blnc.empty() == 1 || blnc.top() != 1) {
                    yes = false;
                    break;
                }
                blnc.pop();
            }
            else if (c == ']') {
                if(blnc.empty() == 1 || blnc.top() != 2) {
                    yes = false;
                    break;
                }
                blnc.pop();
            }
        }

        if (!yes) cout << "no\n";
        else if (blnc.empty() == 0) cout << "no\n";
        else cout << "yes\n";

        while (blnc.empty() == 0) {
            blnc.pop();
        }
    }    
}