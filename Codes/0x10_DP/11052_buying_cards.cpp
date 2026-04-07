#include <bits/stdc++.h>
using namespace std;

int N;
int P[1004], D[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> P[i];

    D[1] = P[1];
    
    for (int i = 2; i <= N; i++) {
        D[i] = P[i];

        for (int j = 1; j < i; j++) {
            int q, r;
            q = i/j, r = i%j;
            D[i] = max(D[j]*q+D[r], D[i]);
        }
    }

    cout << D[N];

}
// D[i] = 카드를 i개 살 때 가격의 최댓값