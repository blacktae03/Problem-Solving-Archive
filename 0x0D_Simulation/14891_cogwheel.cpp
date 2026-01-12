#include <bits/stdc++.h>
using namespace std;

string cw[4];
unsigned char cw2[4];
int turn[4];
int K, what, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        cin >> cw[i];
        unsigned char bin = 128;

        for (int j = 0; j < 8; j++) {
            cw2[i] += bin * (cw[i][j] - '0');
            bin /= 2;
        }
    } // 이진수로 변환
    // 오른쪽 칸 == (cw2[i] / 32) % 2
    // 왼쪽 칸 == (cw2[i] / 2) % 2

    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> what >> turn[what-1];
        what--; // 인덱스에 맞게 최적화

        for (int j = 0; j < 4; j++) { // 오른쪽으로 가면서 회전할 건지 안할 건지 파악 (S, N 파악)
            if (what+j == 3) break;
            if ((cw2[what+j] / 32) % 2 + (cw2[what+j+1] / 2) % 2 == 1) {
                turn[what+j+1] = turn[what+j] * (-1);
            }
        }

        for (int j = 0; j < 4; j++) { // 왼쪽으로 가면서 회전할 건지 안할 건지 파악 (S, N 파악)
            if (what-j == 0) break;
            if ((cw2[what-j] / 2) % 2 + (cw2[what-j-1] / 32) % 2 == 1) {
                turn[what-j-1] = turn[what-j] * (-1);
            }
        }

        for (int j = 0; j < 4; j++) { // 회전시키기
            if (turn[j] == 1) {
                if(cw2[j] % 2) cw2[j] = (cw2[j] >> 1) + 128;
                else cw2[j] = cw2[j] >> 1;
            }

            else if (turn[j] == -1) {
                if(cw2[j] / 128) cw2[j] = (cw2[j] << 1) + 1;
                else cw2[j] = cw2[j] << 1;
            }
        }

        fill(turn, turn+4, 0);
    }
    
    for (int i = 0; i < 4; i++) ans += (cw2[i] / 128) * (1 << i);

    cout << ans;
}