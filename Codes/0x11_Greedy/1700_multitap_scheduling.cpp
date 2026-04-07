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
            if (M[j] && M[j] != E[i]) {
                if (T[M[j]] < mn) {
                    mn = T[M[j]];
                    mnidx = j;
                }
                continue;
            }
            M[j] = E[i];
            break;
        }
        
        if (j == N) {
            ans++;
            M[mnidx] = E[i];
        }
    }

    cout << ans;
}
// 2 7
// 2 3 2 3 1 2 7 일 때
// 2 꼽고 3 꼽고 가만히 가만히 3뽑1 가만히 2뽑7