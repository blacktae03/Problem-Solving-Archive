#include <bits/stdc++.h>
using namespace std;

int N, K, turn;
int dur[210], rbt[210];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= 2*N; i++) cin >> dur[i];

    while (true) {
        turn++;
        // cout << "----- turn " << turn << " -----\n";
        
        rotate(dur+1, dur+2*N, dur+2*N+1); // 1
        rotate(rbt+1, rbt+2*N, rbt+2*N+1);
        if (rbt[N]) rbt[N] = 0;
        
        for (int i = N; i >= 2; i--) { // 2
            if (rbt[i] || !dur[i] || !rbt[i-1]) continue;

            swap(rbt[i], rbt[i-1]);
            dur[i]--;
            if (!dur[i]) K--;
            if (i == N) rbt[N] = 0;
        }

        if (dur[1]) { // 3
            rbt[1] = turn;
            dur[1]--;
            if (!dur[1]) K--;
        }
        

        // for (int i = 1; i <= 2*N; i++) {
        //     cout << brd[i] << ' ';
        //     if (i % N == 0) cout << '\n';
        // }
        // for (int i = 1; i <= 2*N; i++) {
        //     cout << "dur[" << i << "] == " << dur[i] << ' ';
        //     if (i % N == 0) cout << '\n';
        // }
        // cout << K << '\n';

        
        if (K <= 0) break; // 4
    }


    cout << turn;
}