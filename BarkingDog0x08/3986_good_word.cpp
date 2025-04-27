#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    int N, cnt = 0;
    
    cin >> N;

    while (N--) {
        stack<char> s;

        cin >> word;

        for (char c : word) {
            if (!s.empty()) {
                if (s.top() == c) {
                    s.pop();
                }
                else {
                    s.push(c);
                }
            }
            else {
                s.push(c);
            }
        }

        if (s.empty()) cnt++;
    }

    cout << cnt;
}