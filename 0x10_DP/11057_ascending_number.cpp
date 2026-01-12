#include <bits/stdc++.h>
using namespace std;

int N;
int D[1004][14];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fill(D[1], D[1]+10, 1); // D[1][0]부터 D[1][9]까지 1로 채우기

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                D[i][j] = (D[i][j] + D[i-1][k]) % 10007;
            }
            // D[i][j] = (D[i][j-1] + D[i-1][j]) % 10007로 시간 복잡도 줄일 수 있음.
            // 왜냐하면 결국 D[i][j-1]은 D[i-1][0:j]의 값이니까 마지막 D[i-1][j]만 한 번 더 더해주면 되네 ㄷㄷ;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) sum = (sum + D[N][i]) % 10007; cout << sum;
    // 23 묶어서 cout << accumulate(D[N], D[N]+10, 0) % 10007 로 쓸 수 있음
    // 나는 계속 모듈로 연산한다는 점에서 살짝 다르긴 하네
}
// D[i][j] = j로 끝나는 i자리 오르막 수