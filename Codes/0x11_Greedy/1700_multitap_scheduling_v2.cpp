#include <bits/stdc++.h>
using namespace std;

int N, K;
int M[109], T[109], E[109];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        cin >> E[i];
        T[E[i]] = i;
    }

    int j;
    for (int i = 1; i <= K; i++) {
        int mn = 109, mnidx = 109;
        for (j = 0; j < N; j++) {
            if (!M[j] || M[j] == E[i]) {
                M[j] = E[i];
                break;
            }

            if (T[M[j]] < mn) {
                mn = T[M[j]];
                mnidx = j;
            }
        }
        
        if (j == N) {
            ans++;
            // cout << M[mnidx] << " picked!, " << E[i] <<" pluged!\n";
            M[mnidx] = E[i];
            // for (int i = 0; i < N; i++) cout << M[i] << ' ';
            // cout << '\n';
        }
    }

    cout << ans;
}
// 2 7
// 2 3 2 3 1 2 7 일 때
// 2 꼽고 3 꼽고 가만히 가만히 3뽑1 가만히 2뽑7
// 2 8
// 2 3 2 3 1 3 2 7 일 때
// 2꼽 3꼽 가만히 가만히 3뽑1 1뽑3 가만히 3뽑7
// 2 7
// 2 3 2 3 1 3 7 일 때
// 2꼽 3꼽 가만히 가만히 2뽑1 가만히 1뽑7
// 2 7
// 1 2 3 4 5 6 7 일 때
// 1꼽 2꼽 1뽑3 2뽑4 3뽑5 4뽑6 5뽑7