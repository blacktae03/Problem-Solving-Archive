#include <bits/stdc++.h>
using namespace std;

int W[10004], D[4][10004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) cin >> W[i];

    D[2][1] = W[1];
    
    for (int i = 2; i <= n; i++) {
        D[2][i] = W[i];
        for (int j = 1; j < i; j++) {
            if (j == i-1) D[1][i] = max(D[1][i], D[2][j] + W[i]);
            else D[2][i] = max(D[2][i], max(D[1][j], D[2][j]) + W[i]);
        }
    }

    cout << max(*max_element(D[1]+1, D[1]+1+n), *max_element(D[2]+1, D[2]+1+n));
}
// D[i][j] = i번째 포도주를 마지막 포도주로 먹었을 때 포도주 총량의 최댓값 j는 i번째 잔과 그와 가장 가까운 잔의 칸 차이 (1 or 2(2이상))