#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sdt[2][7];
    int N, K, s, g, cnt = 0;

    fill(sdt[0], sdt[0]+7, 0);
    fill(sdt[1], sdt[1]+7, 0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> s >> g;
        sdt[s][g]++;
    }

    for (int i = 0; i < 2; i++)
        for (int j = 1; j < 7; j++)
            cnt += (sdt[i][j]+K-1)/K;

    cout << cnt;
}