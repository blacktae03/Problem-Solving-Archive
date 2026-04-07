#include <bits/stdc++.h>
using namespace std;

int N, K;
int V[105], W[105];
int D[105], cur[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    // D[1][0] = 0;
    // cur[1][0] = 0;
    // if (W[1] <= K) {
    //     D[1][1] = V[1];
    //     cur[1][1] = W[1];
    // }

    D[1] = V[1];
    cur[1] = W[1];
    
    for (int i = 2; i <= N; i++) {
        D[i] = V[i];
        cur[i] = W[i];
        
        for (int j = 1; j < N; j++) {
            if (cur[j] + W[i] <= K && D[j] + V[i] > D[i]) {
                D[i] = D[j] + V[i];
                cur[i] = cur[j] + W[i];
            }
        }
    }
    
    cout << "D : ";
    for (int i = 1; i <= N; i++) {
        cout << D[i] << ' ';
    }
    cout << "\ncur : ";
    for (int i = 1; i <= N; i++) {
        cout << cur[i] << ' ';
    }
    cout << '\n';

    cout << *max_element(D+1, D+1+N);
}
// D[i][0or1] = i번째 아이템까지만 봤을 때, i번째 아이템을 포함한(1) 또는 포함하지 않은(0) 가치 합의 최댓값
// cur[i][0or1] = 그때의 배낭 내 총 무게
// v2
// 아니 잠깐만 N이 100이라서 O(N^2) 해도 됨.
// D[i] = i번째 물건을 포함한 배낭의 가치의 최댓값
// v3
// D[i] = 무게가 i인 배낭합의 최댓값
// v4
// D[i] = i번째까지 배낭합의 최댓값의 {무게, 배낭합}