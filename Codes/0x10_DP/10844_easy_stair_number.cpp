// 정답인 거 같은데 백준 서버 먹통 250625
#include <bits/stdc++.h>
using namespace std;

int N;
int D[104][10];
int dx[2] = {1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill (D[1]+1, D[1]+10, 1);
    
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int dir = 0; dir < 2; dir++) {
                int nx = j + dx[dir];

                if (nx < 0 || nx > 9) continue;

                D[i][nx] += D[i-1][j] % 1000000000;
                D[i][nx] = D[i][nx] % 1000000000;
            }
        }
    }

    int sum = 0;

    for (int i = 0; i <= 9; i++) {
        sum += D[N][i];// % 1000000000;
        sum = sum % 1000000000;
    }

    cout << sum;
}
// D[i][j] = i자리 수의 j로 끝이 나는 계단 수의 수
// ans = D[N][0:10] % 10억
// ans = ( D[N][0] % 10억 + D[N][1] % 10억 + ... + D[N][9] % 10억 ) % 10억
// D[N][0] = D[1][1] + D[2][1] + ... + D[N-1][1]
// D[N][0] % 10억 = ( D[1][1] % 10억 + D[2][1] % 10억 + ... + D[N-1][1] % 10억 ) % 10억