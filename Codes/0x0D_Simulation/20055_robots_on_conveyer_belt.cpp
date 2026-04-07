#include <bits/stdc++.h>
using namespace std;

int N, K, turn;
int brd[210], dur[210], rbt[30000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= 2*N; i++) cin >> dur[i];

    while (true) {
        turn++;
        cout << "----- turn " << turn << " -----\n";
        
        rotate(brd+1, brd+2*N, brd+2*N+1); // 1
        for (int i = 1; i <= turn-1; i++) rbt[i]++;
        
        for (int i = 1; i <= turn-1 && rbt[i]; i++) { // 2
            cout << i << ' ';

            int nxt = (rbt[i] == 2*N) ? 1 : rbt[i]+1;
            cout << nxt << ' ';
            int cur = rbt[i];
            cout << cur << ' ';

            if (brd[nxt] == 0 && dur[nxt]) {
                brd[cur] = 0;
                brd[nxt] = i;
                dur[nxt]--;
                cout << "dur[2] == " << dur[2] << '\n';
                if (dur[nxt] == 0) K--;
                rbt[i] = nxt;
            }
            
            if (rbt[i] == N && brd[nxt+1] == 0 && dur[nxt+1]) {
                nxt++;
                brd[rbt[i]] = 0;
                brd[nxt] = i;
                dur[nxt]--;
                if (dur[nxt] == 0) K--;
                rbt[i] = nxt;
            }

        }
        cout << '\n';

        if (dur[1]) { // 3
            dur[1]--;
            brd[1] = turn;
            if (dur[1] == 0) K--;
            rbt[turn] = 1;
        }

        for (int i = 1; i <= 2*N; i++) {
            cout << brd[i] << ' ';
            if (i % N == 0) cout << '\n';
        }
        for (int i = 1; i <= 2*N; i++) {
            cout << "dur[" << i << "] == " << dur[i] << ' ';
            if (i % N == 0) cout << '\n';
        }
        // cout << K << '\n';

        
        if (K <= 0) break; // 4
    }


    cout << turn;
}