#include <bits/stdc++.h>
using namespace std;

int T, k;
multiset<int> S[10000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    while(T--) {
        cin >> k;
        auto minIt = S[T].begin();
        auto maxIt = S[T].end();
        // maxIt--;

        while (k--) {
            char IorD; int num;
            cin >> IorD >> num;
            
            if (IorD == 'I') S[T].insert(num);
            else {
                if (!S[T].size()) {}
                else if (num == 1) S[T].erase(maxIt); // prev(S.end()) 라고 하면 되네.
                else S[T].erase(minIt);
            }
            minIt = S[T].begin();
            maxIt = S[T].end();
            if (S[T].size()) maxIt--; // 이렇게 안하고 26번 주석처럼 하기.
        }

        if (!S[T].size()) cout << "EMPTY\n";
        else cout << *maxIt << ' ' << *minIt << '\n';
    }
}