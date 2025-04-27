#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string put = "";
    list<char> pass;
    

    cin >> N;

    for (int i = 0; i < N; i++) {
        pass.clear();
        auto cur = pass.begin();
        cin >> put;
        
        for (auto c : put) {
            if (c == '<') {
                if(cur != pass.begin()) cur--;
            }

            else if (c == '>') {
                if(cur != pass.end()) cur++;
            }

            else if (c == '-') {
                if(cur != pass.begin()) cur = pass.erase(--cur);
            }

            else pass.insert(cur, c);
        }
        
        for (auto d : pass) cout << d;
        cout << '\n';
    }
}
