#include <bits/stdc++.h>
using namespace std;

int brd[4][100004], D[100004][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    
    while(T--) {
        int n; cin >> n;

        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> brd[i][j];
            }
        }

        D[1][0] = 0;
        D[1][1] = brd[1][1];
        D[1][2] = brd[2][1];

        for (int i = 2; i <= n; i++) {
            D[i][0] = *max_element(D[i-1], D[i-1]+3);
            D[i][1] = max(D[i-1][2], D[i-1][0]) + brd[1][i];
            D[i][2] = max(D[i-1][1], D[i-1][0]) + brd[2][i];
        }

        cout << *max_element(D[n], D[n]+3) << '\n';
    }
}
// D[i][0:3] = i번쨰 열에 있는 1:3행 스티커가 포함된 최댓값. 0은 어느 스티커도 포함하지 않은 경우 최댓값.