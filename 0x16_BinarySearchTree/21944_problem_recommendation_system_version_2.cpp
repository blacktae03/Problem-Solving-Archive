#include <bits/stdc++.h>
using namespace std;

int N, M;

set<pair<int, int>> S[104];
set<tuple<int, int, int>> SPLG;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--) {
        int P, L, G;
        cin >> P >> L >> G;
        S[0].insert({L, P}); // S[0]은 모든 문제의 난이도와 번호를 기록한 set
        S[G].insert({L, P}); // S[G]는 문제의 알고리즘이 G인 문제들의 난이도와 번호를 기록한 set
        SPLG.insert({P, L, G}); // SPLG은 모든 문제의 번호와 난이도를 기록한 set
    }
    
    cin >> M;
    while(M--) {
        string cmd;
        int P, L, G, x;
        cin >> cmd;
        
        if (cmd == "recommend") {
            cin >> G >> x;
            if (x == 1) cout << prev(S[G].end())->second << '\n';
            else cout << S[G].begin()->second << '\n';
        }
        
        else if (cmd == "recommend2") {
            cin >> x;
            if (x == 1) cout << prev(S[0].end())->second << '\n';
            else cout << S[0].begin()->second << '\n';
        }
        
        else if (cmd == "recommend3") {
            cin >> x >> L;
            auto it = S[0].lower_bound({L, 0});
            if (x == 1) {
                if (it != S[0].end()) cout << it->second << '\n';
                else cout << -1 << '\n';
            }
            else {
                if (it != S[0].begin()) cout << prev(it)->second << '\n';
                else cout << -1 << '\n';
            }
        }
        
        else if (cmd == "add") {
            cin >> P >> L >> G;
            S[0].insert({L, P}); // S[0]은 모든 문제의 난이도와 번호를 기록한 set
            S[G].insert({L, P}); // S[G]는 문제의 알고리즘이 G인 문제들의 난이도와 번호를 기록한 set
            SPLG.insert({P, L, G}); // SPLG은 모든 문제의 번호와 난이도를 기록한 set
        }
        
        else if (cmd == "solved") {
            cin >> P;
            auto it = SPLG.lower_bound({P, 0, 0});
            int tp, tl, tg;
            tie(tp, tl, tg) = *it;
            S[0].erase({tl, tp});
            S[tg].erase({tl, tp});
            SPLG.erase(it);
        }
    }
}