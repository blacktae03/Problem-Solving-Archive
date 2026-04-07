// 정답인 거 같은데 백준 서버 먹통 250625
#include <bits/stdc++.h>
using namespace std;

int N, T;
int D[104];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    D[1] = 1;
    D[2] = 1;
    D[3] = 1;
    D[4] = 2;
    D[5] = 2;

    for (int i = 6; i <= 100; i++) {
        D[i] = D[i-1] + D[i-5];
    }

    cin >> T;
    while(T--) {
        cin >> N;
        cout << D[N] << '\n';
    }
}
