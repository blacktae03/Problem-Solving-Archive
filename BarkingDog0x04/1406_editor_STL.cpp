#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M;
    char com;
    string s = "";
    cin >> s;

    list<char> e;

    for(auto c : s) e.push_back(c);
    auto csr = e.end();
    
    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> com;
        
        if (com == 'L' && csr != e.begin()) csr--;

        if (com == 'D' && csr != e.end()) csr++;

        if (com == 'B' && csr != e.begin()) csr = e.erase(--csr);

        if (com == 'P') {
            cin >> com;
            e.insert(csr, com);
        }
        
        // if(csr == e.end()) cout << "end" << '\n';

        // else cout << *csr << '\n';
    }

    for (auto c : e) cout << c; 
}